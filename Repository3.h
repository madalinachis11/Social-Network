#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include "Mesaj.h"

class Repository3
{
public:
    /// Default constructor for message repo
    Repository3();

    /// Copy constructor for a message repo
    Repository3(const Repository3& other);

    /// Destructor for a message repo
    ~Repository3();

    /// Copy a repo to another
    Repository3& operator=(const Repository3& other);

    /// Indexing operator for message repository
    Mesaj& operator[](size_t position);

    /// Equality of two elements
    bool operator==(const Repository3& other) const;

    /// Insertion operator for the repository class
    friend std::ostream& operator<<(std::ostream& os, const Repository3& repo);

    /// Adds a new message to the repository
    virtual void AddElement(const Mesaj& user);

    /// Removes a message from the repo
    virtual void RemoveElement(const Mesaj& user);

    size_t GetSize() const;

    std::vector<Mesaj> GetArray() const;
private:
    std::vector<Mesaj>* elementsArray;
};