#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <memory>

#include "data_structures/min_heap.hpp"

namespace algorithms
{
    template <typename T>
    unsigned int find_min_index(std::vector<T>& items, unsigned int startIdx)
    {
        unsigned int minIdx = startIdx;

        for (unsigned int i = startIdx + 1; i < items.size(); ++i)
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
        for (unsigned int i = 0; i < items.size(); ++i)
        {
            unsigned int minIdx = find_min_index(items, i);
            std::swap(items[i], items[minIdx]);
        }
    }

    // Time: O(n * log n)
    template <typename T>
    void heap_sort(std::vector<T>& items)
    {
        std::shared_ptr<data_structures::min_heap<T>> heap = std::make_shared<data_structures::min_heap<T>>(items);

        for (unsigned int i = 0; i < items.size(); ++i)
            items[i] = heap->extract();
    }

    // source: The Algorithm Design Manual by Steven S. Skiena
    template <typename T>
    void merge(std::vector<T>& items, unsigned int low, unsigned int middle, unsigned int high)
    {
        std::queue<T> lhs;
        std::queue<T> rhs;

        for (unsigned int i = low; i <= middle; ++i)
            lhs.push(items[i]);

        for (unsigned int i = middle + 1; i <= high; ++i)
            rhs.push(items[i]);

        unsigned int it = low;
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
    void merge_sort(std::vector<T>& items, unsigned int low, unsigned int high)
    {
        if (low < high)
        {
            unsigned int middle = (low + high) / 2;

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
    unsigned int partition(std::vector<T>& items, unsigned int low, unsigned int high)
    {
        unsigned int pivot = high;
        unsigned int firstHigh = low;

        for (unsigned int it = low; it < high; ++it)
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
    void quick_sort(std::vector<T>& items, unsigned int low, unsigned int high)
    {
        if (low < high)
        {
            unsigned int pivot = partition(items, low, high);

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
    void insertion_sort(std::vector<T>& items)
    {
        for (unsigned int i = 1; i < items.size(); ++i)
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
    void bucket_sort(std::vector<T>& items, unsigned int level = 0)
    {
    }

    void couting_sort(std::vector<unsigned int>& items, unsigned int max_value) {
        std::vector<unsigned int> counter;

        for (unsigned int i = 0; i <= max_value; ++i) {
            counter.push_back(0);
        }

        for (size_t i = 0; i < items.size(); ++i) {
            ++counter[items[i]];
        }

        size_t index = 0;
        for (unsigned int i = 0; i < counter.size(); ++i) {
            while (counter[i] > 0) {
                items[index] = i;
                ++index;
                --counter[i];
            }
        }
    }
}
