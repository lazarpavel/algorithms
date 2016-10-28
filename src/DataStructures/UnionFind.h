#pragma once

#include <iostream>
#include <vector>

namespace datastructures
{
    // source: Algorithms, 4th ed. [Sedgewick, Wayne].pdf
    class QuickFindUF
    {
    public:
        QuickFindUF(const uint size);

    public:
        void connect(const uint, const uint);
        bool connected(const uint, const uint) const;

    private:
        std::vector<uint> m_items;
    };

    // source: Algorithms, 4th ed. [Sedgewick, Wayne].pdf
    class QuickUnionUF
    {
    public:
        QuickUnionUF(const uint size);

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
    class WeightedUF
    {
    public:
        WeightedUF(const uint size);

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
