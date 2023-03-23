#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
template <class V>
class SetIterator;

template <class V>
class Node {
public:
    V value;
    Node<V>* next;
    Node(V e) : value{ e } { this->next = nullptr; }
};

template <class V>
class Set {
    //DO NOT CHANGE THIS PART
    friend class SetIterator<V>;

private:
    int numberElements{ 0 };
    Node<V>* head;

public:
    //implicit constructor
    Set();

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(V e);

    //removes an element from the set
    //returns true if e was removed, false otherwise
    bool remove(V e);

    //checks whether an element belongs to the set or not
    bool search(V elem) const;

    //returns the number of elements;
    int size() const;

    //check whether the set is empty or not;
    bool isEmpty() const;

    //return an iterator for the set
    SetIterator<V> iterator() const;

    // destructor
    ~Set();
};

template <class V>

Set<V>::Set() {
    this->head = nullptr;
}

template <class V>
bool Set<V>::add(V elem) {
    auto* newEntry = new Node<V>(elem);
    Node<V>* location = this->head;
    if (location == nullptr)
    {
        this->head = newEntry;
        this->numberElements++;
        return true;
    }
    while (location->next != nullptr)
    {
        if (location->value == elem)
            return false;
        location = location->next;
    }
    if (location->value == elem)
        return false;
    location->next = newEntry;
    this->numberElements++;
    return true;
}

template <class V>
bool Set<V>::remove(V elem) {
    Node<V>* location = this->head;
    Node<V>* prev = nullptr;
    if (location == nullptr)
        return false;
    while (location != nullptr)
    {
        if (location->value == elem)
        {
            // if we found the element, then we delete it
            if (prev == nullptr)
            {
                // if our element is first in the list
                this->head = location->next;
                delete location;
                this->numberElements--;
                return true;
            }
            prev->next = location->next;
            this->numberElements--;
            delete location;
            return true;
        }
        prev = location;
        location = location->next;
    }
    return false;
}

template <class V>
bool Set<V>::search(V elem) const {
    Node<V>* location = this->head;
    while (location != nullptr)
    {
        if (location->value == elem)
            return true;
        location = location->next;
    }
    return false;
}

template <class V>
int Set<V>::size() const {
    return this->numberElements;
}

template <class V>
bool Set<V>::isEmpty() const {
    if (!this->numberElements)
        return true;
    return false;
}

template <class V>
Set<V>::~Set() = default;

template <class V>
SetIterator<V> Set<V>::iterator() const {
    return SetIterator<V>(*this);
}