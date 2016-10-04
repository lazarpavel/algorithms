#pragma once

#include <vector>
#include <utility>

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

    template <typename T>
    void selectionSort(std::vector<T>& items)
    {
        for (uint i = 0; i < items.size(); ++i)
        {
            uint minIdx = findMinIndex(items, i);
            std::swap(items[i], items[minIdx]);
        }
    }

    template <typename T>
    void heapSort(std::vector<T>& items)
    {
        // TODO:
    }
}
