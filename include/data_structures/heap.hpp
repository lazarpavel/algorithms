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

        heap(size_t size);

    public:
        virtual T get() const;
        virtual T extract();
        virtual void insert(const T& value);

        virtual bool is_empty();

    protected:
        virtual bool compare(const T& lhs, const T& rhs) const = 0;

        unsigned int get_parent_index(unsigned int idx);
        unsigned int get_left_child_index(unsigned int idx);
        unsigned int get_right_child_index(unsigned int idx);

        void shift_up();
        void shift_down(unsigned int index);
        void swap(unsigned int lhs, unsigned int rhs);

    protected:
        std::vector<T> m_items;
        unsigned int m_position;
    };

    template<typename T>
    data_structures::heap<T>::heap(std::vector<T> items)
    {
        m_items.resize(items.size());
        m_position = 0;
    }

    template<typename T>
    data_structures::heap<T>::heap(size_t size)
    {
        m_items.resize(size);
        m_position = 0;
    }

    template<typename T>
    void data_structures::heap<T>::insert(const T& value)
    {
        if (m_position == 0)
        {
            m_items[m_position + 1] = value;
            m_position = 2;
        }
        else
        {
            m_items[m_position] = value;
            ++m_position;

            shift_up();
        }
    }

    template<typename T>
    void data_structures::heap<T>::shift_up()
    {
        unsigned int tmp = m_position - 1;

        while(tmp > 1 && compare(m_items[tmp / 2], m_items[tmp]))
        {
            swap(tmp, tmp / 2);
            tmp = tmp / 2;
        }
    }

    template<typename T>
    bool data_structures::heap<T>::is_empty()
    {
        return m_position == 0;
    }

    template<typename T>
    T data_structures::heap<T>::extract()
    {
        T min = m_items[1];

        m_items[1] = m_items[--m_position];

        shift_down(1);

        return min;
    }

    template<typename T>
    void data_structures::heap<T>::shift_down(unsigned int index)
    {
        T tmp = m_items[index];
        unsigned int heapIdx = index;

        if (2 * index < m_position && compare(m_items[heapIdx], m_items[2 * index]))
            heapIdx = 2 * index;

        if (2 * index + 1 < m_position && compare(m_items[heapIdx], m_items[2 * index + 1]))
            heapIdx = 2 * index + 1;

        if (heapIdx != index)
        {
            swap(index, heapIdx);
            shift_down(heapIdx);
        }
    }

    template<typename T>
    void data_structures::heap<T>::swap(unsigned int lhs, unsigned int rhs)
    {
        T temp = m_items[lhs];

        m_items[lhs] = m_items[rhs];
        m_items[rhs] = temp;
    }

    template<typename T>
    T data_structures::heap<T>::get() const
    {
        return m_items[1];
    }

    template<typename T>
    unsigned int data_structures::heap<T>::get_parent_index(unsigned int idx)
    {
        if (idx == 1)
            return -1;
        else
            return ((unsigned int) idx / 2);
    }

    template<typename T>
    unsigned int data_structures::heap<T>::get_left_child_index(unsigned int idx)
    {
        return 2 * idx;
    }

    template<typename T>
    unsigned int data_structures::heap<T>::get_right_child_index(unsigned int idx)
    {
        return (2 * idx) + 1;
    }

}