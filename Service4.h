#pragma once
#include "Repository4.h"

class Service4 {
public:

    Service4(const Repository4& interested, vector<Eveniment> evList);

    vector<Eveniment> GetEvents() const;

    Repository4 GetInterestedUsers();

    bool UpdateEvent(const Eveniment& oldEvent, const Eveniment& newEvent);

    void RemoveEvent(const Eveniment& e);

    int AddEvent(const Eveniment& e);

    bool AddInterestedUser(const Eveniment& event, const Utilizator& user);

    bool RemoveInterestedUser(const Eveniment& event, const Utilizator& user);

    std::string displayFormat();

    void RemoveUser(const Utilizator& user);

    void UpdateUser(const Utilizator& user, const Utilizator& user2);

private:

    Repository4 interestedUsers;
    vector<Eveniment> eventsList;


};