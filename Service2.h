#pragma once
#include "Repository2.h"

class Service2 {
    /// Constructor for the service
public:

    explicit Service2(Repository2& repo);


    /// Adds a new friendship to the repository
    int AddFriendship(Utilizator utilizator1, Utilizator utilizator2);

    /// Remove a certain friendship from the repository
    int RemoveFriendship(Utilizator utilizator1, Utilizator utilizator2);

    /// Prints the content of the repo
    Repository2 GetRepo() const;

    /// Adds 10 entries to the repo


private:

    Repository2& repo;
};