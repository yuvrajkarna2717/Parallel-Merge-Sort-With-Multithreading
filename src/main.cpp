#include "../include/sort_utils.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

std::vector<int> generateRandomVector(size_t size, int min = 0, int max = 1000000) {
    std::vector<int> vec(size);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(min, max);
    for (auto& v : vec) v = dist(mt);
    return vec;
}

int main() {
    const size_t SIZE = 1'000'000;
    std::vector<int> data1 = generateRandomVector(SIZE);
    std::vector<int> data2 = data1;

    auto start = std::chrono::high_resolution_clock::now();
    serialMergeSort(data1, 0, data1.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Serial sort time: "
              << std::chrono::duration<double>(end - start).count()
              << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    parallelMergeSort(data2, 0, data2.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Parallel sort time: "
              << std::chrono::duration<double>(end - start).count()
              << " seconds\n";

    return 0;
}
