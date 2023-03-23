#include "Service4.h"
#include <algorithm>
#include <utility>
#include <sstream>


Service4::Service4(const Repository4& interested, vector<Eveniment> evList) {
    this->interestedUsers = interested;
    this->eventsList = std::move(evList);
}


int Service4::AddEvent(const Eveniment& e)
{
    this->eventsList.push_back(e);

    return 0;
}

void Service4::RemoveEvent(const Eveniment& e)
{
    auto a = remove(this->eventsList.begin(), this->eventsList.end(), e);
    this->eventsList.erase(a, this->eventsList.end());
    this->interestedUsers.RemoveEvent(e);
}

void Service4::RemoveUser(const Utilizator& user)
{
    for (const auto& e : this->eventsList)
        this->interestedUsers.RemoveInterestedPerson(e, user);
}

bool Service4::UpdateEvent(const Eveniment& oldEvent, const Eveniment& newEvent)
{
    bool updated = false;
    for (auto& i : this->eventsList)
        if (i == oldEvent)
            i = newEvent, updated = true;
    if (updated)
        this->interestedUsers.UpdateEventData(oldEvent, newEvent);
    return updated;
}

bool Service4::AddInterestedUser(const Eveniment& event, const Utilizator& user)
{
    for (const auto& e : this->eventsList)
        if (e == event)
        {
            this->interestedUsers.AddInterestedPerson(event, user);
            return true;
        }
    return false;
}

void Service4::UpdateUser(const Utilizator& user, const Utilizator& user2)
{
    for (const auto& e : this->eventsList) {
        this->interestedUsers.RemoveInterestedPerson(e, user);
        this->interestedUsers.AddInterestedPerson(e, user2);
    }
}

Repository4 Service4::GetInterestedUsers()
{
    return this->interestedUsers;
}

vector<Eveniment> Service4::GetEvents() const
{
    return this->eventsList;
}

std::string Service4::displayFormat() {
    stringstream os;
    for (const auto& ev : this->eventsList)
    {
        os << ev << "; Utilizatori interesati: \n";
        for (const auto& us : this->interestedUsers.FindInterestedToEvent(ev))
            os << us << "\n";
    }
    return os.str();
}

bool Service4::RemoveInterestedUser(const Eveniment& event, const Utilizator& user) {
    for (const auto& e : this->eventsList)
        if (e == event)
        {
            this->interestedUsers.RemoveInterestedPerson(event, user);
            return true;
        }
    return false;
}