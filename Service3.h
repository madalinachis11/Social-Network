#pragma once
#include "Repository3.h"

class Service3 {
    /// Constructor for the service
public:

    explicit Service3(const Repository3& repo);


    /// Adds a new user to the repository
    int AddMessage(Utilizator expeditor, Utilizator destinatar, string continut);

    /// Remove a certain user from the repository
    int RemoveMessage(Utilizator expeditor, Utilizator destinatar, string continut);

    void UpdateUser(Utilizator oldUser, Utilizator newUser);
    /// Prints the content of the repo

    void RemoveUser(Utilizator User);
    /// Prints the content of the repo
    Repository3 GetRepo() const;


private:

    Repository3 repo;
};