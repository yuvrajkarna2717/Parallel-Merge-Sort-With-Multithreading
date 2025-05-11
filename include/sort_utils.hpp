#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP

#include <vector>

void serialMergeSort(std::vector<int>& arr, int left, int right);
void parallelMergeSort(std::vector<int>& arr, int left, int right, int depth = 0);
void merge(std::vector<int>& arr, int left, int mid, int right);

#endif // SORT_UTILS_HPP
