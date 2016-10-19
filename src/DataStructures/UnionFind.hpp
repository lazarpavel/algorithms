#pragma once

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

    QuickFindUF::QuickFindUF(const uint size)
    {
        m_items.resize(size);

        for (uint i = 0; i < size; ++i)
            m_items[i] = i;
    }

    bool QuickFindUF::connected(const uint p, const uint q) const
    {
        return m_items[q] == m_items[p];
    }

    void QuickFindUF::connect(const uint p, const uint q)
    {
        uint pid = m_items[p];
        uint qid = m_items[q];

        for (uint i = 0; i < m_items.size(); ++i)
            if (m_items[i] == pid) m_items[i] = qid;
    }

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

    QuickUnionUF::QuickUnionUF(const uint size)
    {
        m_items.resize(size);

        for (uint i = 0; i < size; ++i)
            m_items[i] = i;
    }

    bool QuickUnionUF::connected(const uint p, const uint q) const
    {
        return root(p) == root(q);
    }

    void QuickUnionUF::connect(const uint p, const uint q)
    {
        uint rootP = root(p);
        uint rootQ = root(q);
        m_items[rootP] = rootQ;
    }

    uint QuickUnionUF::root(uint id) const
    {
        while (id != m_items[id])
            id = m_items[id];

        return id;
    }

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

    WeightedUF::WeightedUF(const uint size)
    {
        m_items.resize(size);
        m_size.resize(size);

        for (uint i = 0; i < size; ++i)
        {
            m_items[i] = i;
            m_size[i] = 1;
        }
    }

    bool WeightedUF::connected(const uint p, const uint q)
    {
        return root(p) == root(q);
    }

    void WeightedUF::connect(const uint p, const uint q)
    {
        uint rootP = root(p);
        uint rootQ = root(q);

        if (rootP == rootQ)
            return;

        if (m_size[rootP] < m_size[rootQ])
        {
            m_items[rootP] = rootQ;
            m_size[rootQ] += m_size[rootP];
        }
        else
        {
            m_items[rootQ] = rootP;
            m_size[rootP] += m_size[rootQ];
        }
    }

    uint WeightedUF::root(uint id)
    {
        while (id != m_items[id])
        {
            m_items[id] = m_items[m_items[id]];
            id = m_items[id];
        }

        return id;
    }
}
