#pragma once

#include "data_structures/heap.hpp"
#include <iostream>

namespace data_structures
{
//
// source: Elements of Programming Interviews - The Insiders Guide by Adnan Aziz, Tsung - Hsien Lee, Amit Prakash
//
    template<typename T>
    class min_heap : public heap<T>
    {
    public:
        min_heap(std::vector<T> items);

    protected:
        virtual bool compare(const T& lhs, const T& rhs) const;

    };

    template<typename T>
    data_structures::min_heap<T>::min_heap(std::vector<T> items)
        : heap<T>::heap(items) {
        for (uint it = 0; it < items.size(); ++it)
            this->insert(items[it]);
    }

    template<typename T>
    bool data_structures::min_heap<T>::compare(const T& lhs, const T& rhs) const {
        return lhs > rhs;
    }

}