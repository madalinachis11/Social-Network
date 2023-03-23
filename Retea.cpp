#include "Retea.h"

Retea::Retea(const Repository1& users, const Repository2& friends) {
    this->friendLists = friends;
    this->usersList = users;
}

bool Retea::addUser(const Utilizator& user) {
    return this->usersList.AddElement(user);
}

bool Retea::removeUser(const Utilizator& user) {
    SetIterator<Prietenie> it = this->friendLists.GetIterator();
    while (it.valid()) {
        if ( it.getCurrent().getUtilizator1() == user || it.getCurrent().getUtilizator2() == user)
            this->friendLists.RemoveElement(it.getCurrent()), it.first();
        else
            it.next();
    }
    return this->usersList.RemoveElement(user);
}

bool Retea::addFriendship(Prietenie& friendship) {
    if (!this->usersList.GetArray().search(friendship.getUtilizator1()))
        return false;
    if (!this->usersList.GetArray().search(friendship.getUtilizator2()))
        return false;
    return this->friendLists.AddElement(friendship);
}

bool Retea::removeFriendship(const Prietenie& friendship) {
    return this->friendLists.RemoveElement(friendship);
}

Repository1 Retea::getUserList() {
    return this->usersList;
}

Repository2 Retea::getFriendList() {
    return this->friendLists;
}

std::vector<Utilizator> Retea::getSomeonesFriendList(Utilizator user)
{
    std::vector<Utilizator> result;
    SetIterator<Prietenie> it = this->friendLists.GetIterator();
    while (it.valid()) {
        if (it.getCurrent().getUtilizator1() == user)
            result.push_back(it.getCurrent().getUtilizator2());
        if (it.getCurrent().getUtilizator2() == user)
            result.push_back(it.getCurrent().getUtilizator1());
        it.next();
    }
    return result;
}

bool Retea::updateUser(const Utilizator& oldUser, const Utilizator& newUser) {
    if (!this->usersList.RemoveElement(oldUser))
        return false;
    if (!this->usersList.AddElement(newUser)) {
        this->usersList.AddElement(oldUser);
        return false;
    }
    SetIterator<Prietenie> it = this->friendLists.GetIterator();
    Utilizator aux{};
    while (it.valid()) {
        if (it.getCurrent().getUtilizator1() == oldUser || it.getCurrent().getUtilizator2() == oldUser) {
            if (it.getCurrent().getUtilizator1() == oldUser)
                aux = it.getCurrent().getUtilizator2();
            else
                aux = it.getCurrent().getUtilizator1();
            Prietenie p(newUser, aux);
            this->friendLists.RemoveElement(it.getCurrent());
            this->friendLists.AddElement(p);
            it.first();
        }
        else
            it.next();
    }
    return true;
}