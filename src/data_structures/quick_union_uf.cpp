#include "data_structures/quick_union_uf.h"

data_structures::quick_union_uf::quick_union_uf(const uint size) {
    m_items.resize(size);

    for (uint i = 0; i < size; ++i)
        m_items[i] = i;
}

bool data_structures::quick_union_uf::connected(const uint p, const uint q) const {
    return root(p) == root(q);
}

void data_structures::quick_union_uf::connect(const uint p, const uint q) {
    uint root_p = root(p);
    uint root_q = root(q);
    m_items[root_p] = root_q;
}

uint data_structures::quick_union_uf::root(uint id) const {
    while (id != m_items[id])
        id = m_items[id];

    return id;
}
