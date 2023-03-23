#pragma once
#include "Repository1.h"

class Service1 {
    /// Constructor for the service
public:

    explicit Service1(Repository1& repo);


    /// Adds a new user to the repository
    int AddUser(int id, const std::string& nume);

    /// Remove a certain user from the repository
    int RemoveUser(int id, const std::string& nume);

    /// Updates the id of an user from the repository
    int UpdateUserId(const std::string& name, int newId);

    /// Updates the name of an user from the repository
    int UpdateUserName(const std::string& name, std::string newName);

    /// Prints the content of the repo
    Repository1 GetRepo() const;


private:

    Repository1& repo;
};