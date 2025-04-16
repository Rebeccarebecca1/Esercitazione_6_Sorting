#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
void heapify(std::vector<T>& v, int start, int n, int i) {
    int largest = i;
    int left = 2 * (i - start) + 1 + start;
    int right = 2 * (i - start) + 2 + start;

    if (left <= n && v[left] > v[largest])
        largest = left;

    if (right <= n && v[right] > v[largest])
        largest = right;

    if (largest != i) {
        std::swap(v[i], v[largest]);
        heapify(v, start, n, largest);
    }
}

template<typename T>
void HeapSort(std::vector<T>& v, int start, int end) {
    // Build max heap
    for (int i = (start + end) / 2; i >= start; --i)
        heapify(v, start, end, i);

    // Extract elements from heap one by one
    for (int i = end; i > start; --i) {
        std::swap(v[start], v[i]);
        heapify(v, start, i - 1, start);
    }
}

template<typename T>
void SelectionSort(std::vector<T>& v) {
    size_t n = v.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (v[j] < v[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(v[i], v[min_index]);
        }
    }
}

template<typename T>
void InsertionSort(std::vector<T>& v) {
    size_t n = v.size();
    for (size_t i = 1; i < n; ++i) {
        T key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}


template<typename T>
void BubbleSort(std::vector<T>& data)
{
    size_t rem_size = data.size();
    size_t last_seen = rem_size;
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (size_t i = 1; i < rem_size; i++) {
            if (data[i-1] > data[i]) {
                std::swap(data[i-1], data[i]);
                swapped = true;
                last_seen = i;
            }
        }
//        rem_size = rem_size - 1;
        rem_size = last_seen;
    }
}



}







