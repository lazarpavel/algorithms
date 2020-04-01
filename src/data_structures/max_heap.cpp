#include "data_structures/max_heap.h"

template<typename T>
data_structures::max_heap<T>::max_heap(std::vector<T> items)
    : heap<T>::heap(items) {
    for (uint it = 0; it < items.size(); ++it)
        this->insert(items[it]);
}

template<typename T>
bool data_structures::max_heap<T>::compare(const T& lhs, const T& rhs) const {
    return lhs < rhs;
}