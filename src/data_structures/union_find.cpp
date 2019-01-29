#include "union_find.h"

using namespace data_structures;

quick_find_uf::quick_find_uf(const uint size)
{
    m_items.resize(size);

    for (uint i = 0; i < size; ++i)
        m_items[i] = i;
}

bool quick_find_uf::connected(const uint p, const uint q) const
{
    return m_items[q] == m_items[p];
}

void quick_find_uf::connect(const uint p, const uint q)
{
    uint pid = m_items[p];
    uint qid = m_items[q];

    for (uint i = 0; i < m_items.size(); ++i)
        if (m_items[i] == pid) m_items[i] = qid;
}


quick_union_uf::quick_union_uf(const uint size)
{
    m_items.resize(size);

    for (uint i = 0; i < size; ++i)
        m_items[i] = i;
}

bool quick_union_uf::connected(const uint p, const uint q) const
{
    return root(p) == root(q);
}

void quick_union_uf::connect(const uint p, const uint q)
{
    uint root_p = root(p);
    uint root_q = root(q);
    m_items[root_p] = root_q;
}

uint quick_union_uf::root(uint id) const
{
    while (id != m_items[id])
        id = m_items[id];

    return id;
}

weighted_uf::weighted_uf(const uint size)
{
    m_items.resize(size);
    m_size.resize(size);

    for (uint i = 0; i < size; ++i)
    {
        m_items[i] = i;
        m_size[i] = 1;
    }
}

bool weighted_uf::connected(const uint p, const uint q)
{
    return root(p) == root(q);
}

void weighted_uf::connect(const uint p, const uint q)
{
    uint root_p = root(p);
    uint root_q = root(q);

    if (root_p == root_q)
        return;

    if (m_size[root_p] < m_size[root_q])
    {
        m_items[root_p] = root_q;
        m_size[root_q] += m_size[root_p];
    }
    else
    {
        m_items[root_q] = root_p;
        m_size[root_p] += m_size[root_q];
    }
}

uint weighted_uf::root(uint id)
{
    while (id != m_items[id])
    {
        m_items[id] = m_items[m_items[id]];
        id = m_items[id];
    }

    return id;
}
