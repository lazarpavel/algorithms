#include "data_structures/quick_find_uf.h"

data_structures::quick_find_uf::quick_find_uf(const unsigned int size) {
    m_items.resize(size);

    for (unsigned int i = 0; i < size; ++i)
        m_items[i] = i;
}

bool data_structures::quick_find_uf::connected(const unsigned int p, const unsigned int q) const {
    return m_items[q] == m_items[p];
}

void data_structures::quick_find_uf::connect(const unsigned int p, const unsigned int q) {
    unsigned int pid = m_items[p];
    unsigned int qid = m_items[q];

    for (unsigned int i = 0; i < m_items.size(); ++i)
        if (m_items[i] == pid) m_items[i] = qid;
}
