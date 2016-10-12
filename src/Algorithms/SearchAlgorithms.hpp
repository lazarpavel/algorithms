#pragma once

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
}
