#pragma once

#include <vector>
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
}
