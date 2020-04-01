#pragma once

#include <iostream>
#include "heap.h"

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
}