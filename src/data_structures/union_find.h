#pragma once

#include <iostream>
#include <vector>

namespace datastructures
{
    // source: Algorithms, 4th ed. [Sedgewick, Wayne].pdf
    class quick_find_uf
    {
    public:
        quick_find_uf(const uint size);

    public:
        void connect(const uint, const uint);
        bool connected(const uint, const uint) const;

    private:
        std::vector<uint> m_items;
    };

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

    // source: Algorithms, 4th ed. [Sedgewick, Wayne].pdf
    // with path compression
    class weighted_uf
    {
    public:
        weighted_uf(const uint size);

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
