#pragma once

#include <iterator>

namespace algorithms
{
    template <typename iterator, typename T>
    iterator linear_search(iterator it, iterator end, const T& value)
    {
        for(; it != end; ++it)
        {
            if (*it == value)
                break;
        }

        return it;
    }

    template <typename iterator, typename T>
    iterator binary_search(iterator begin, iterator end, const T& value)
    {
        iterator fst = begin;
        iterator lst = end;

        unsigned int distance = std::distance(begin, end);

        while (distance > 1)
        {
            iterator middle = fst;
            std::advance(middle, distance / 2);

            if (*middle > value)
                lst = middle;
            else
                fst = middle;

            distance = std::distance(fst, lst);
        }

        if (*fst == value)
            return fst;

        return end;
    }
}
