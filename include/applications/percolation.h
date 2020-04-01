#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <exception>

#include "data_structures/weighted_quick_union_uf.h"

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

        std::shared_ptr<data_structures::weighted_quick_union_uf> check_percolates_uf;
        std::shared_ptr<data_structures::weighted_quick_union_uf> check_full_uf;
    };
}
#endif /* PERCOLATION_H */
