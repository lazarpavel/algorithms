#pragma once

#include <iostream>
#include <vector>

namespace data_structures
{
//
// source: Elements of Programming Interviews - The Insiders Guide by Adnan Aziz, Tsung - Hsien Lee, Amit Prakash
//
template<typename T>
class heap
{
public:
    heap(std::vector<T> items);

public:
    virtual T get() const;
    virtual T extract();
    virtual void insert(const T& value);
    virtual void print() const;

protected:
    virtual bool compare(const T& lhs, const T& rhs) const = 0;

    uint get_parent_index(uint idx);
    uint get_left_child_index(uint idx);
    uint get_right_child_index(uint idx);

    void shift_up();
    void shift_down(uint index);
    void swap(uint lhs, uint rhs);

protected:
    std::vector<T> m_items;
    uint m_position;
};
}