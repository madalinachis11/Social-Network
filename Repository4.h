#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include "Eveniment.h"
#include "Utilizator.h"
#include "MultiMap.h"

class Repository4
{
public:
    /// Default constructor for event repo
    Repository4();

    /// Constructor which initialize the repo with a dynamic array of a given size
    explicit Repository4(size_t maxSize);

    /// Copy constructor for an event repo
    Repository4(const Repository4& other);

    /// Destructor for an event repo
    ~Repository4();

    /// Insertion operator for the repository class
    std::string toString();

    /// Adds a new event to the repository
    void AddInterestedPerson(Eveniment event, Utilizator user);

    /// Removes an event from the repo
    bool RemoveInterestedPerson(const Eveniment& event, const Utilizator& user);

    bool UpdateEventData(const Eveniment& oldEvent, const Eveniment& newEvent);

    vector<Utilizator> FindInterestedToEvent(const Eveniment& event) const;


    size_t GetSize() const;

    MultiMap<Eveniment, Utilizator> GetArray() const;

    MultiMapIterator<Eveniment, Utilizator> GetIterator();

    void RemoveEvent(const Eveniment& elem);

private:
    MultiMap<Eveniment, Utilizator>* elementsArray;
};