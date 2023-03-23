#pragma once
#include<vector>
#include <algorithm>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
template <class K, class V>
class MultiMapIterator;

template <class K, class V>
class NodeB {
public:
    std::pair<K, V> info;
    NodeB<K, V>* next;
    NodeB(std::pair<K, V> e) : info{ e } { this->next = nullptr; }
};

template <class K, class V>
class MultiMap
{
    friend class MultiMapIterator<K, V>;

private:
    NodeB<K, V>* head;
    NodeB<K, V>* tail;

public:
    //constructor
    MultiMap() : head{ nullptr }, tail{ nullptr }{};

    //adds a key value pair to the multimap
    void add(K c, V v);

    //removes a key value pair from the multimap
    //returns true if the pair was removed (if it was in the multimap) and false otherwise
    bool remove(K c, V v);

    // returns the difference between min/max key
    vector<K> getKeys() const;

    //returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
    vector<V> search(K c) const;

    //returns the number of pairs from the multimap
    int size() const;

    // Update a key from the map, returns true if done successfully, false otherwise
    bool updateKey(K oldKey, K newKey) const;

    //checks whether the multimap is empty
    bool isEmpty() const;

    //returns an iterator for the multimap
    MultiMapIterator<K, V> iterator() const;

    //descturctor
    ~MultiMap();

    bool updateValue(V oldValue, V newValue) const;
};


template <class K, class V>
inline void MultiMap<K, V>::add(K c, V v) {
    std::pair<K, V> e;
    e.first = c;
    e.second = v;
    NodeB<K, V>* current = this->head;
    if (current == nullptr)
    {
        NodeB<K, V>* newNode = new NodeB<K, V>(e);
        this->head = newNode;
        this->tail = newNode;
        return;
    }

    NodeB<K, V>* newNode = new NodeB<K, V>(e);
    this->tail->next = newNode;
    this->tail = newNode;
}// Theta(1)

template <class K, class V>
inline bool MultiMap<K, V>::remove(K c, V v) {
    std::pair<K, V> e;
    e.first = c;
    e.second = v;
    NodeB<K, V>* current = this->head;
    if (current == nullptr)
        return false;
    if (current->info == e)
    {
        NodeB<K, V>* nextNode = current->next;
        delete current;
        this->head = nextNode;
        return true;
    }
    while (current->next != nullptr && current->next->info != e)
        current = current->next;
    if (current->next == nullptr)
        return  false;
    NodeB<K, V>* toDelete = current->next;
    current->next = toDelete->next;
    if (this->tail == toDelete)
        this->tail = current;
    delete toDelete;
    return true;
} // Best case: Theta(1) Worst case: Theta(length) => Total complexity O(length)

template <class K, class V>
inline vector<V> MultiMap<K, V>::search(K c) const {
    vector<V> v;
    NodeB<K, V>* current = this->head;
    while (current != nullptr)
    {
        if (current->info.first == c)
            v.push_back(current->info.second);
        current = current->next;
    }
    return v;
} // Best case: Theta(1) Worst case: Theta(length) => Total complexity O(length)

template <class K, class V>
inline int MultiMap<K, V>::size() const {
    int size = 0;
    NodeB<K, V>* current = this->head;
    while (current != nullptr)
        size++, current = current->next;
    return size;
} // O(length)

template <class K, class V>
inline vector<K> MultiMap<K, V>::getKeys() const
{
    vector<K> v;
    NodeB<K, V>* current = this->head;
    while (current != nullptr)
    {
        if (std::find(v.begin(), v.end(), current->info.first) == v.end())
            v.push_back(current->info.first);
        current = current->next;
    }
    return v;
} // O(length)

template <class K, class V>
inline bool MultiMap<K, V>::isEmpty() const {
    if (this->head == nullptr)
        return true;
    return false;
} // O(1)

template <class K, class V>
inline MultiMapIterator<K, V> MultiMap<K, V>::iterator() const {
    return MultiMapIterator<K, V>(*this);
} // O(1)

template <class K, class V>
MultiMap<K, V>::~MultiMap() = default;

template<class K, class V>
bool MultiMap<K, V>::updateKey(K oldKey, K newKey) const {
    bool wasUpdated = false;
    NodeB<K, V>* current = this->head;
    while (current != nullptr)
    {
        if (current->info.first == oldKey)
            current->info.first = newKey, wasUpdated = true;
        current = current->next;
    }
    return wasUpdated;
}

template<class K, class V>
bool MultiMap<K, V>::updateValue(V oldValue, V newValue) const {
    bool wasUpdated = false;
    NodeB<K, V>* current = this->head;
    while (current != nullptr)
    {
        if (current->info.second == oldValue)
            current->info.second = newValue, wasUpdated = true;
        current = current->next;
    }
    return wasUpdated;
}
// O(length)