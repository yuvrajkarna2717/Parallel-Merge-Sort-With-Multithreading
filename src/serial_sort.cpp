#include "../include/sort_utils.hpp"

void serialMergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    serialMergeSort(arr, left, mid);
    serialMergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
