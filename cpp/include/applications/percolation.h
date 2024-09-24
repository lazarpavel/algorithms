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
        percolation(const unsigned int n);

    public:
        void open(unsigned int row, unsigned int col);
        bool is_open(unsigned int row, unsigned int col) const;
        bool is_full(unsigned int row, unsigned int col) const;
        bool percolates() const;

    private:
        std::vector<std::vector<bool>> m_maze;
        unsigned int m_size;

        std::shared_ptr<data_structures::weighted_quick_union_uf> check_percolates_uf;
        std::shared_ptr<data_structures::weighted_quick_union_uf> check_full_uf;
    };
}
#endif /* PERCOLATION_H */
