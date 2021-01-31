#pragma once

#include <iterator>

namespace algorithms
{

    template<typename iterator, typename comparator>
    iterator quick_select(iterator start, iterator end, iterator kth, comparator compare) {
        iterator pivot = kth;
        iterator firstHigh = start;

        for (iterator it = start; it != end; ++it) {
            if (compare(it, pivot)) {
                std::swap(*it, *firstHigh);
                ++firstHigh;
            }
        }

        std::swap(*pivot, *firstHigh);

        return firstHigh;
    }

}