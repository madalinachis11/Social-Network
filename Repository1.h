#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include "Utilizator.h"
#include "MultimeIterator.h"


class Repository1
{
public:
    /// Default constructor for user repo
    Repository1();

    /// Copy constructor for an user repo
    Repository1(const Repository1& other);

    /// Destructor for an user repo
    ~Repository1();

    /// Copy a repo to another
    Repository1& operator=(const Repository1& other);

    /// Equality of two elements
    bool operator==(const Repository1& other) const;

    /// Insertion operator for the repository class
    friend std::ostream& operator<<(std::ostream& os, Repository1& repo);

    SetIterator<Utilizator> GetIterator();

    /// Adds a new user to the repository
    bool AddElement(const Utilizator& user);
    /// Removes an user from the repo
    bool RemoveElement(const Utilizator& user);

    void UpdateId(const Utilizator& elem, int id);

    void UpdateNume(const Utilizator& elem, std::string& newName);

    std::string toString();

    /// Find the position of the element which we want to search for
    Utilizator FindElemByName(const std::string& name);

    size_t GetSize() const;

    Set<Utilizator> GetArray() const;
private:
    Set<Utilizator>* elementsArray;
};