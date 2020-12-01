#pragma once

#include <iostream>
#include <vector>

namespace data_structures
{
    // source: Algorithms, 4th ed. [Sedgewick, Wayne].pdf with path compression
    class weighted_quick_union_uf
    {
    public:
        weighted_quick_union_uf(const unsigned int size);

    public:
        void connect(const unsigned int, const unsigned int);
        bool connected(const unsigned int, const unsigned int);

    private:
        unsigned int root(unsigned int id);

    private:
        std::vector<unsigned int> m_items;
        std::vector<unsigned int> m_size;
    };

}