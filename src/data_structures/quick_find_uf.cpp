#include "data_structures/quick_find_uf.h"

data_structures::quick_find_uf::quick_find_uf(const uint size) {
    m_items.resize(size);

    for (uint i = 0; i < size; ++i)
        m_items[i] = i;
}

bool data_structures::quick_find_uf::connected(const uint p, const uint q) const {
    return m_items[q] == m_items[p];
}

void data_structures::quick_find_uf::connect(const uint p, const uint q) {
    uint pid = m_items[p];
    uint qid = m_items[q];

    for (uint i = 0; i < m_items.size(); ++i)
        if (m_items[i] == pid) m_items[i] = qid;
}
