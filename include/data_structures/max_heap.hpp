#pragma once

#include "heap.hpp"
#include <iostream>

namespace data_structures
{
//
// source: Elements of Programming Interviews - The Insiders Guide by Adnan Aziz, Tsung - Hsien Lee, Amit Prakash
//
    template<typename T>
    class max_heap : public heap<T>
    {
    public:
        max_heap(std::vector<T> items);

    protected:
        virtual bool compare(const T& lhs, const T& rhs) const;

    };

    template<typename T>
    data_structures::max_heap<T>::max_heap(std::vector<T> items)
        : heap<T>::heap(items) {
        for (unsigned int it = 0; it < items.size(); ++it)
            this->insert(items[it]);
    }

    template<typename T>
    bool data_structures::max_heap<T>::compare(const T& lhs, const T& rhs) const {
        return lhs < rhs;
    }

}