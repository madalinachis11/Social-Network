#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include "Prietenie.h"
#include "Multime.h"
#include "MultimeIterator.h"

class Repository2
{
public:
    /// Default constructor for user repo
    Repository2();

    /// Copy constructor for an user repo
    Repository2(const Repository2& other);

    /// Destructor for an user repo
    ~Repository2();

    /// Copy a repo to another
    Repository2& operator=(const Repository2& other);

    /// Equality of two elements
    bool operator==(const Repository2& other) const;

    /// Insertion operator for the repository class
    friend std::ostream& operator<<(std::ostream& os, Repository2& repo);

    SetIterator<Prietenie> GetIterator();

    /// Adds a new user to the repository
    bool AddElement(const Prietenie& p);
    /// Removes an user from the repo
    bool RemoveElement(const Prietenie& p);

    size_t GetSize() const;

    Set<Prietenie> GetArray() const;

    std::string toString();
private:
    Set<Prietenie>* elementsArray;
};