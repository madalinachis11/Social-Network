#include "Service3.h"


Service3::Service3(const Repository3& repository)
{
    this->repo = repository;
}

int Service3::AddMessage(Utilizator expeditor, Utilizator destinatar, string continut)
{

    Mesaj newMessage = Mesaj(expeditor, destinatar, continut);


    this->repo.AddElement(newMessage);

    return 0;
}

int Service3::RemoveMessage(Utilizator expeditor, Utilizator destinatar, string continut)
{
    Mesaj to_find(expeditor, destinatar, continut);
    this->repo.RemoveElement(to_find);
    return 0;
}

Repository3 Service3::GetRepo() const
{
    return this->repo;
}

void Service3::UpdateUser(Utilizator oldUser, Utilizator newUser) {

    for (int i = 0; i < this->GetRepo().GetSize(); i++)
    {
        if (this->repo[i].getDestinatar() == oldUser)
            this->repo[i].setDestinatar(newUser);
        if (this->repo[i].getExpeditor() == oldUser)
            this->repo[i].setExpeditor(newUser);
    }
}

void Service3::RemoveUser(Utilizator User) {
    for (auto i : this->repo.GetArray())
        if (i.getExpeditor() == User || i.getDestinatar() == User)
            this->repo.RemoveElement(i);
}