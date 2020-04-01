#pragma once

#include <iostream>
#include "data_structures/heap.h"

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
}