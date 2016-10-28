#pragma once

#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <exception>

#include "../DataStructures/UnionFind.h"

using namespace datastructures;

namespace applications
{
    class Percolation
    {
    public:
        Percolation(const uint n);

    public:
        void open(uint row, uint col);
        bool isOpen(uint row, uint col) const;
        bool isFull(uint row, uint col) const;
        bool percolates() const;

    private:
        std::vector<std::vector<bool>> m_maze;
        uint m_size;

        std::shared_ptr<WeightedUF> checkPercolatesUF;
        std::shared_ptr<WeightedUF> checkFullUF;
    };
}
