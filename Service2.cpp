#include "Service2.h"


Service2::Service2(Repository2& repository) :
    repo{ repository }
{
}

int Service2::AddFriendship(Utilizator utilizator1, Utilizator utilizator2)
{

    Prietenie newFriendship = Prietenie(utilizator1, utilizator2);


    this->repo.AddElement(newFriendship);

    return 0;
}

int Service2::RemoveFriendship(Utilizator utilizator1, Utilizator utilizator2)
{
    Prietenie to_find(utilizator1, utilizator2);
    this->repo.RemoveElement(to_find);
    return 0;
}

Repository2 Service2::GetRepo() const
{
    return this->repo;
}