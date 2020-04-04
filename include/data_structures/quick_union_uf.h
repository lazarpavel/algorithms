#pragma once

#include <iostream>
#include <vector>

namespace data_structures
{
// source: Algorithms, 4th ed. [Sedgewick, Wayne].pdf
    class quick_union_uf
    {
    public:
        quick_union_uf(const uint size);

    public:
        void connect(const uint, const uint);
        bool connected(const uint, const uint) const;

    private:
        uint root(uint id) const;

    private:
        std::vector<uint> m_items;
    };

}