#include "data_structures/weighted_quick_union_uf.h"

data_structures::weighted_quick_union_uf::weighted_quick_union_uf(const uint size) {
    m_items.resize(size);
    m_size.resize(size);

    for (uint i = 0; i < size; ++i) {
        m_items[i] = i;
        m_size[i] = 1;
    }
}

bool data_structures::weighted_quick_union_uf::connected(const uint p, const uint q) {
    return root(p) == root(q);
}

void data_structures::weighted_quick_union_uf::connect(const uint p, const uint q) {
    uint root_p = root(p);
    uint root_q = root(q);

    if (root_p == root_q)
        return;

    if (m_size[root_p] < m_size[root_q]) {
        m_items[root_p] = root_q;
        m_size[root_q] += m_size[root_p];
    } else {
        m_items[root_q] = root_p;
        m_size[root_p] += m_size[root_q];
    }
}

uint data_structures::weighted_quick_union_uf::root(uint id) {
    while (id != m_items[id])
    {
        m_items[id] = m_items[m_items[id]];
        id = m_items[id];
    }

    return id;
}