#pragma once
#include "Repository1.h"
#include "Repository2.h"

class Retea {
private:
    Repository1 usersList;
    Repository2 friendLists;

public:
    Retea(const Repository1& users, const Repository2& friends);

    ~Retea() = default;

    bool addUser(const Utilizator& user);

    bool removeUser(const Utilizator& user);

    bool addFriendship(Prietenie& friendship);

    bool updateUser(const Utilizator& oldUser, const Utilizator& newUser);

    bool removeFriendship(const Prietenie& friendship);

    Repository2 getFriendList();

    Repository1 getUserList();

    std::vector<Utilizator> getSomeonesFriendList(Utilizator user);
};