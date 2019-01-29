#pragma once

#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <exception>

#include "../data_structures/union_find.h"

using namespace data_structures;

namespace applications
{
    class percolation
    {
    public:
        percolation(const uint n);

    public:
        void open(uint row, uint col);
        bool is_open(uint row, uint col) const;
        bool is_full(uint row, uint col) const;
        bool percolates() const;

    private:
        std::vector<std::vector<bool>> m_maze;
        uint m_size;

        std::shared_ptr<weighted_uf> check_percolates_uf;
        std::shared_ptr<weighted_uf> check_full_uf;
    };
}
