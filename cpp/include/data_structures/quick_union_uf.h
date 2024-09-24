#pragma once

#include <iostream>
#include <vector>

namespace data_structures
{
// source: Algorithms, 4th ed. [Sedgewick, Wayne].pdf
    class quick_union_uf
    {
    public:
        quick_union_uf(const unsigned int size);

    public:
        void connect(const unsigned int, const unsigned int);
        bool connected(const unsigned int, const unsigned int) const;

    private:
        unsigned int root(unsigned int id) const;

    private:
        std::vector<unsigned int> m_items;
    };

}