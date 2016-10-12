#pragma once

#include <iostream>

namespace datastructures
{
    //
    // source: Elements of Programming Interviews - The Insiders Guide by Adnan Aziz, Tsung - Hsien Lee, Amit Prakash
    //
    template <typename T>
    class Heap
    {
    public:
        Heap(std::vector<T> items);

    public:
        virtual T get() const;
        virtual T extract();
        virtual void insert(const T& value);
        virtual void print() const;

    protected:
        virtual bool compare(const T& lhs, const T& rhs) const = 0;

        uint getParentIndex(uint idx);
        uint getLeftChildIndex(uint idx);
        uint getRightChildIndex(uint idx);

        void shiftUp();
        void shiftDown(uint index);
        void swap(uint lhs, uint rhs);

    protected:
        std::vector<T> m_items;
        uint m_position;
    };

    template <typename T>
    Heap<T>::Heap(std::vector<T> items)
    {
        m_items.resize(items.size());
        m_position = 0;
    }

    template <typename T>
    void Heap<T>::print() const
    {
        for (uint i = 0; i < m_items.size(); ++i)
            std::cout << m_items[i] << " ";

        std::cout << std::endl;
    }

    template <typename T>
    void Heap<T>::insert(const T& value)
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

            shiftUp();
        }
    }

    template<typename T>
    void Heap<T>::shiftUp()
    {
        uint tmp = m_position - 1;
        while(tmp > 1 && compare(m_items[tmp / 2], m_items[tmp]))
        {
            swap(tmp, tmp / 2);
            tmp = tmp / 2;
        }
    }

    template<typename T>
    T Heap<T>::extract()
    {
        T min = m_items[1];

        m_items[1] = m_items[--m_position];

        shiftDown(1);

        return min;
    }

    template<typename T>
    void Heap<T>::shiftDown(uint index)
    {
        T tmp = m_items[index];
        uint heapIdx = index;

        if (2 * index < m_position && compare(m_items[heapIdx], m_items[2 * index]))
            heapIdx = 2 * index;

        if (2 * index + 1 < m_position && compare(m_items[heapIdx], m_items[2 * index + 1]))
            heapIdx = 2 * index + 1;

        if (heapIdx != index)
        {
            swap(index, heapIdx);
            shiftDown(heapIdx);
        }
    }

    template<typename T>
    void Heap<T>::swap(uint lhs, uint rhs)
    {
        T temp = m_items[lhs];

        m_items[lhs] = m_items[rhs];
        m_items[rhs] = temp;
    }

    template <typename T>
    T Heap<T>::get() const
    {
        return m_items[1];
    }

    template <typename T>
    uint Heap<T>::getParentIndex(uint idx)
    {
        if (idx == 1)
            return -1;
        else
            return ((uint) idx / 2);
    }

    template <typename T>
    uint Heap<T>::getLeftChildIndex(uint idx)
    {
        return 2 * idx;
    }

    template <typename T>
    uint Heap<T>::getRightChildIndex(uint idx)
    {
        return (2 * idx) + 1;
    }

    template <typename T>
    class MinHeap : public Heap<T>
    {
    public:
        MinHeap(std::vector<T> items);

    protected:
        virtual bool compare(const T& lhs, const T& rhs) const;
    };

    template <typename T>
    MinHeap<T>::MinHeap(std::vector<T> items)
        : Heap<T>::Heap(items)
    {
        for (uint it = 0; it < items.size(); ++it)
            this->insert(items[it]);
    }

    template <typename T>
    bool MinHeap<T>::compare(const T& lhs, const T& rhs) const
    {
        return lhs > rhs;
    }

    template <typename T>
    class MaxHeap : public Heap<T>
    {
    public:
        MaxHeap(std::vector<T> items);

    protected:
        virtual bool compare(const T& lhs, const T& rhs) const;
    };

    template <typename T>
    MaxHeap<T>::MaxHeap(std::vector<T> items)
        : Heap<T>::Heap(items)
    {
        for (uint it = 0; it < items.size(); ++it)
            this->insert(items[it]);
    }

    template <typename T>
    bool MaxHeap<T>::compare(const T& lhs, const T& rhs) const
    {
        return lhs < rhs;
    }
}
