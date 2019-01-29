#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <memory>

#include "../data_structures/heap.hpp"

using namespace datastructures;

namespace algorithms
{
    template <typename T>
    uint find_min_index(std::vector<T>& items, uint startIdx)
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
    void selection_sort(std::vector<T>& items)
    {
        for (uint i = 0; i < items.size(); ++i)
        {
            uint minIdx = find_min_index(items, i);
            std::swap(items[i], items[minIdx]);
        }
    }

    // Time: O(n * log n)
    template <typename T>
    void heap_sort(std::vector<T>& items)
    {
        std::shared_ptr<min_heap<T>> heap = std::make_shared<min_heap<T>>(items);

        for (uint i = 0; i < items.size(); ++i)
            items[i] = heap->extract();
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
    void merge_sort(std::vector<T>& items, uint low, uint high)
    {
        if (low < high)
        {
            uint middle = (low + high) / 2;

            merge_sort(items, low, middle);
            merge_sort(items, middle + 1, high);

            merge(items, low, middle, high);
        }
    }

    // Time: O(n * log n)
    template <typename T>
    void merge_sort(std::vector<T>& items)
    {
        merge_sort(items, 0, items.size() - 1);
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
    void quick_sort(std::vector<T>& items, uint low, uint high)
    {
        if (low < high)
        {
            uint pivot = partition(items, low, high);

            quick_sort(items, low, pivot - 1);
            quick_sort(items, pivot + 1, high);
        }
    }

    // Time: O(n * log n) -> O(n ^ 2) - Worst Case
    template <typename T>
    void quick_sort(std::vector<T>& items)
    {
        quick_sort(items, 0, items.size() - 1);
    }

    // pseudocode source: https://en.wikipedia.org/wiki/Insertion_sort
    template <typename T>
    void insertionSort(std::vector<T>& items)
    {
        for (uint i = 1; i < items.size(); ++i)
        {
            T temp = items[i];
            int j = i - 1;

            while (j >= 0 && items[j] > temp)
            {
                items[j + 1] = items[j];
                --j;
            }

            items[j + 1] = temp;
        }
    }

    template <typename T>
    void bucket_sort(std::vector<T>& items, uint level = 0)
    {
    }
}
