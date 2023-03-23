#include "Retea.h"
#include "Service4.h"
#include "Service3.h"
#include <iostream>

using namespace std;

class Ui {
private:
    Retea retea = Retea(Repository1(), Repository2());
    Service4 eventController = Service4(Repository4(), vector<Eveniment>());
    Service3 messageManager = Service3(Repository3());
public:

    Ui(const Retea& retea, const Service4& eventCont, const Service3& messageMan);

    static void mainMenuInterface();
    void mainMenu();
    void addUser();

    void addFriendship();

    void updateUser();

    void DisplayFriendList();

    void removeUser();

    void removeFriendship();

    void addNewEvent();

    void removeEvent();

    void addUserToEvent();

    void removeUserFromEvent();

    void updateEvent();

    void newMessage();

    void deleteMessage();
};