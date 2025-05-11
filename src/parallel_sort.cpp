#include "../include/sort_utils.hpp"
#include <thread>

constexpr int MAX_DEPTH = 4; // Limit recursion depth for parallelism

void parallelMergeSort(std::vector<int>& arr, int left, int right, int depth) {
    if (left >= right) return;
    int mid = (left + right) / 2;

    if (depth >= MAX_DEPTH) {
        serialMergeSort(arr, left, mid);
        serialMergeSort(arr, mid + 1, right);
    } else {
        std::thread leftThread(parallelMergeSort, std::ref(arr), left, mid, depth + 1);
        std::thread rightThread(parallelMergeSort, std::ref(arr), mid + 1, right, depth + 1);
        leftThread.join();
        rightThread.join();
    }

    merge(arr, left, mid, right);
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); ++k) {
        arr[left + k] = temp[k];
    }
}
