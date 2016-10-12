#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <memory>

#include "../DataStructures/Heap.hpp"

using namespace datastructures;

namespace algorithms
{
    template <typename T>
    uint findMinIndex(std::vector<T>& items, uint startIdx)
    {
        uint minIdx = startIdx;

        for (uint i = startIdx + 1; i < items.size(); ++i)
        {
            if (items[i] < items[minIdx])
                minIdx = i;
        }

        return minIdx;
    }

    // Time: O(n^2)
    template <typename T>
    void selectionSort(std::vector<T>& items)
    {
        for (uint i = 0; i < items.size(); ++i)
        {
            uint minIdx = findMinIndex(items, i);
            std::swap(items[i], items[minIdx]);
        }
    }

    // Time: O(n * log n)
    template <typename T>
    void heapSort(std::vector<T>& items)
    {
        std::shared_ptr<MinHeap<T>> minHeap = std::make_shared<MinHeap<T>>(items);

        for (uint i = 0; i < items.size(); ++i)
            items[i] = minHeap->extract();
    }

    // source: The Algorithm Design Manual by Steven S. Skiena
    template <typename T>
    void merge(std::vector<T>& items, uint low, uint middle, uint high)
    {
        std::queue<T> lhs;
        std::queue<T> rhs;

        for (uint i = low; i <= middle; ++i)
            lhs.push(items[i]);

        for (uint i = middle + 1; i <= high; ++i)
            rhs.push(items[i]);

        uint it = low;
        while (!(lhs.empty() || rhs.empty()))
        {
            if (lhs.front() <= rhs.front())
            {
                items[it++] = lhs.front();
                lhs.pop();
            }
            else
            {
                items[it++] = rhs.front();
                rhs.pop();
            }
        }

        while (!lhs.empty())
        {
            items[it++] = lhs.front();
            lhs.pop();
        }

        while (!rhs.empty())
        {
            items[it++] = rhs.front();
            rhs.pop();
        }
    }

    // source: The Algorithm Design Manual by Steven S. Skiena
    template <typename T>
    void mergeSort(std::vector<T>& items, uint low, uint high)
    {
        if (low < high)
        {
            uint middle = (low + high) / 2;

            mergeSort(items, low, middle);
            mergeSort(items, middle + 1, high);

            merge(items, low, middle, high);
        }
    }

    // Time: O(n * log n)
    template <typename T>
    void mergeSort(std::vector<T>& items)
    {
        mergeSort(items, 0, items.size() - 1);
    }

    // source: The Algorithm Design Manual by Steven S. Skiena
    template <typename T>
    uint partition(std::vector<T>& items, uint low, uint high)
    {
        uint pivot = high;
        uint firstHigh = low;

        for (uint it = low; it < high; ++it)
        {
            if (items[it] < items[pivot])
            {
                std::swap(items[it], items[firstHigh]);
                ++firstHigh;
            }
        }

        std::swap(items[pivot], items[firstHigh]);
        return firstHigh;
    }

    // source: The Algorithm Design Manual by Steven S. Skiena
    template <typename T>
    void quickSort(std::vector<T>& items, uint low, uint high)
    {
        if (low < high)
        {
            uint pivot = partition(items, low, high);

            quickSort(items, low, pivot - 1);
            quickSort(items, pivot + 1, high);
        }
    }

    template <typename T>
    void quickSort(std::vector<T>& items)
    {
        quickSort(items, 0, items.size() - 1);
    }

    template <typename T>
    void bucketSort(std::vector<T>& items)
    {
    }
}
