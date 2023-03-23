#pragma once
#include "MultiMap.h"

template <class K, class V>
class MultiMap;

template <class K, class V>
class MultiMapIterator
{
    friend class MultiMap<K, V>;

private:
    const MultiMap<K, V>& col;
    //TODO - Representation
    NodeB<K, V>* current;
    //DO NOT CHANGE THIS PART
    explicit MultiMapIterator(const MultiMap<K, V>& c);

public:
    std::pair<K, V> getCurrent()const;
    bool valid() const;
    void next();
    void first();
};


template <class K, class V>
MultiMapIterator<K, V>::MultiMapIterator(const MultiMap<K, V>& c) : col(c) {
    this->current = this->col.head;
} // O(1)

template <class K, class V>
std::pair<K, V> MultiMapIterator<K, V>::getCurrent() const {
    if (this->current == nullptr)
        throw exception();
    return this->current->info;
} // O(1)

template <class K, class V>
bool MultiMapIterator<K, V>::valid() const {
    if (current != nullptr)
        return true;
    return false;
} // O(1)

template <class K, class V>
void MultiMapIterator<K, V>::next() {
    if (this->current == nullptr)
        throw exception();
    this->current = this->current->next;
} // O(1)

template <class K, class V>
void MultiMapIterator<K, V>::first() {
    this->current = this->col.head;
} //O(1)