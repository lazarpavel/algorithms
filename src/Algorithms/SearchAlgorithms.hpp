#pragma once

#include <iterator>

using namespace datastructures;

namespace algorithms
{
    template <typename Iterator, typename T>
    Iterator linearSearch(Iterator it, Iterator end, const T& value)
    {
        for(; it != end; ++it)
        {
            if (*it == value)
                break;
        }

        return it;
    }

    template <typename Iterator, typename T>
    Iterator binarySearch(Iterator begin, Iterator end, const T& value)
    {
        Iterator fst = begin;
        Iterator lst = end;

        uint distance = std::distance(begin, end);

        while (distance > 1)
        {
            Iterator middle = fst;
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
