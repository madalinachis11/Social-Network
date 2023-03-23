#pragma once
#include "Multime.h"
#include "exception"

template <class V>
class SetIterator
{
    //DO NOT CHANGE THIS PART
    friend class Set<V>;
private:
    //DO NOT CHANGE THIS PART
    const Set<V>& set;
    SetIterator(const Set<V>& s);

    Node<V>* location;

public:
    void first();
    void next();
    V getCurrent();
    bool valid() const;
};

template <class V>
SetIterator<V>::SetIterator(const Set<V>& m) : set(m)
{
    this->location = this->set.head;
}

template <class V>
void SetIterator<V>::first() {
    this->location = this->set.head;
}


template <class V>
void SetIterator<V>::next() {
    if (!this->valid())
        throw std::exception();
    location = location->next;
}


template <class V>
V SetIterator<V>::getCurrent()
{
    if (!this->valid())
        throw std::exception();
    return this->location->value;
}

template <class V>
bool SetIterator<V>::valid() const {
    if (location != nullptr)
        return true;
    return false;
}