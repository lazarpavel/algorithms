#pragma once

#include <iterator>

namespace algorithms
{
    std::vector<unsigned> karatsuba_multiply(std::vector<unsigned> lhs, std::vector<unsigned> rhs)
    {
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