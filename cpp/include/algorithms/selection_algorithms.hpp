#pragma once

#include <iterator>
#include <ctime>

namespace algorithms
{
    template<typename iterator, typename comparator>
    iterator randomized_partition(iterator start, iterator end, comparator compare)
    {
        srand((unsigned) time(0));
        size_t random_dist = rand() % std::distance(end, start);

        iterator pivot = start + random_dist;
        auto pivot_value = *pivot;

        std::iter_swap(pivot, start);
        iterator first_high = start;

        for (iterator lhs = start, rhs = std::prev(end); std::distance(lhs, rhs) >= 0;)
        {
            if (*lhs == pivot_value)
            {
                ++lhs;
            }
            else if (*lhs < pivot_value)
            {
                std::iter_swap(lhs, first_high);
                ++lhs;
                ++first_high;
            }
            else
            {
                std::iter_swap(lhs, rhs);
                rhs = std::prev(rhs);
            }
        }

        return first_high;
    }

    template<typename iterator, typename comparator>
    iterator randomized_quick_select(iterator start, iterator end, int kth, comparator compare)
    {
        if (start == end)
        {
            return start;
        }

        iterator pivot = randomized_partition(start, end, compare);
        size_t dist = std::distance(start, pivot);

        if (dist == kth - 1)
        {
            return pivot;
        }
        else if (dist > kth - 1)
        {
            return randomized_quick_select(start, pivot, kth, compare);
        }

        return randomized_quick_select(pivot + 1, end, kth - dist - 1, compare);
    }
}