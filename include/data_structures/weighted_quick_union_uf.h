#pragma once

#include <iostream>
#include <vector>

namespace data_structures
{
    // source: Algorithms, 4th ed. [Sedgewick, Wayne].pdf with path compression
    class weighted_quick_union_uf
    {
    public:
        weighted_quick_union_uf(const uint size);

    public:
        void connect(const uint, const uint);
        bool connected(const uint, const uint);

    private:
        uint root(uint id);

    private:
        std::vector<uint> m_items;
        std::vector<uint> m_size;
    };

}