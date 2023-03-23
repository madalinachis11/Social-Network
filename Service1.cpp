#include "Service1.h"


Service1::Service1(Repository1& repository) :
    repo{ repository }
{
}

int Service1::AddUser(int id, const std::string& nume)
{

    Utilizator newUser = Utilizator(id, nume);


    this->repo.AddElement(newUser);

    return 0;
}

int Service1::RemoveUser(int id, const std::string& nume)
{
    Utilizator to_find(id, nume);
    this->repo.RemoveElement(to_find);
    return 0;
}

int Service1::UpdateUserName(const std::string& name, std::string newName)
{
    Utilizator elem = this->repo.FindElemByName(name);
    this->repo.UpdateNume(elem, newName);
    return 0;
}

int Service1::UpdateUserId(const std::string& name, int new_id)
{
    Utilizator elem = this->repo.FindElemByName(name);

    this->repo.UpdateId(elem, new_id);
    return 0;
}


Repository1 Service1::GetRepo() const
{
    return this->repo;
}