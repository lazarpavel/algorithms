#include "data_structures/quick_union_uf.h"

data_structures::quick_union_uf::quick_union_uf(const unsigned int size) {
    m_items.resize(size);

    for (unsigned int i = 0; i < size; ++i)
        m_items[i] = i;
}

bool data_structures::quick_union_uf::connected(const unsigned int p, const unsigned int q) const {
    return root(p) == root(q);
}

void data_structures::quick_union_uf::connect(const unsigned int p, const unsigned int q) {
    unsigned int root_p = root(p);
    unsigned int root_q = root(q);
    m_items[root_p] = root_q;
}

unsigned int data_structures::quick_union_uf::root(unsigned int id) const {
    while (id != m_items[id])
        id = m_items[id];

    return id;
}
