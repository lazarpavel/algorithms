#include "data_structures/weighted_quick_union_uf.h"

data_structures::weighted_quick_union_uf::weighted_quick_union_uf(const unsigned int size) {
    m_items.resize(size);
    m_size.resize(size);

    for (unsigned int i = 0; i < size; ++i) {
        m_items[i] = i;
        m_size[i] = 1;
    }
}

bool data_structures::weighted_quick_union_uf::connected(const unsigned int p, const unsigned int q) {
    return root(p) == root(q);
}

void data_structures::weighted_quick_union_uf::connect(const unsigned int p, const unsigned int q) {
    unsigned int root_p = root(p);
    unsigned int root_q = root(q);

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

unsigned int data_structures::weighted_quick_union_uf::root(unsigned int id) {
    while (id != m_items[id])
    {
        m_items[id] = m_items[m_items[id]];
        id = m_items[id];
    }

    return id;
}