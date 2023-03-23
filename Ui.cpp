#include "Ui.h"



Ui::Ui(const Retea& retea, const Service4& eventCont, const Service3& messageMan) {
    this->retea = retea;
    this->eventController = eventCont;
    this->messageManager = messageMan;
}


void Ui::mainMenuInterface() {
    cout << "\n~~~Main Menu~~~\n";
    cout << "[1] Add new User\n";
    cout << "[2] Remove User\n";
    cout << "[3] Update User\n";
    cout << "[4] Display Users\n";
    cout << "[5] Add new Friendships\n";
    cout << "[6] Remove Friendships\n";
    cout << "[7] Display Friend Lists\n";
    cout << "[8] Display Friend List of Someone\n";
    cout << "[9] Add event\n";
    cout << "[10] Add Interested User\n";
    cout << "[11] Remove Interested User\n";
    cout << "[12] Remove Event\n";
    cout << "[13] Update Event\n";
    cout << "[14] Display Events\n";
    cout << "[15] New Message\n";
    cout << "[16] Delete Message\n";
    cout << "[17] Display All Messages\n";
    cout << "[0] Exit\n";
}

void Ui::mainMenu() {
    while (true)
    {
        mainMenuInterface();
        string option;
        cin >> option;
        if (option == "1")
            this->addUser();
        else if (option == "2")
            this->removeUser();
        else if (option == "3")
            this->updateUser();
        else if (option == "4")
            cout << this->retea.getUserList().toString();
        else if (option == "5")
            this->addFriendship();
        else if (option == "6")
            this->removeFriendship();
        else if (option == "7")
            cout << this->retea.getFriendList().toString();
        else if (option == "8")
            this->DisplayFriendList();
        else if (option == "9")
            this->addNewEvent();
        else if (option == "10")
            this->addUserToEvent();
        else if (option == "11")
            this->removeUserFromEvent();
        else if (option == "12")
            this->removeEvent();
        else if (option == "13")
            this->updateEvent();
        else if (option == "14")
            cout << this->eventController.displayFormat();
        else if (option == "15")
            this->newMessage();
        else if (option == "16")
            this->deleteMessage();
        else if (option == "17")
            cout << this->messageManager.GetRepo();
        else if (option == "0")
            return;
        else
            cout << "Wrong Input! Try again! \n";

    }
}

void Ui::addUser() {
    int id = 0;
    string name;
    cout << "User Id: ";
    cin >> id;
    cout << "User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator newUser(id, name);
    if (this->retea.addUser(newUser))
        cout << "User Added Successfully";
    else
        cout << "User cannot be added";
}

void Ui::removeUser() {
    int id = 0;
    string name;
    cout << "User Id: ";
    cin >> id;
    cout << "User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator newUser(id, name);
    if (this->retea.removeUser(newUser))
        cout << "User Removed Successfully";
    else
        cout << "User cannot be removed";
    this->eventController.RemoveUser(newUser);
    this->messageManager.RemoveUser(newUser);
}

void Ui::updateUser() {
    int id = 0;
    string name;
    cout << "Old User Id: ";
    cin >> id;
    cout << "Old User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator firstUser(id, name);
    cout << "New User Id: ";
    cin >> id;
    cout << "New User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator secondUser(id, name);
    if (this->retea.updateUser(firstUser, secondUser))
        cout << "User modified Successfully";
    else
        cout << "User cannot be modified";
    this->eventController.UpdateUser(firstUser, secondUser);
    this->messageManager.UpdateUser(firstUser, secondUser);
}

void Ui::addFriendship() {
    int id = 0;
    string name;
    cout << "First User Id: ";
    cin >> id;
    cout << "First User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator firstUser(id, name);
    cout << "Second User Id: ";
    cin >> id;
    cout << "Second User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator secondUser(id, name);
    Prietenie p(firstUser, secondUser);
    if (this->retea.addFriendship(p))
        cout << "Friendship Added Successfully";
    else
        cout << "FriendShip cannot be added";
}

void Ui::removeFriendship() {
    int id = 0;
    string name;
    cout << "First User Id: ";
    cin >> id;
    cout << "First User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator firstUser(id, name);
    cout << "Second User Id: ";
    cin >> id;
    cout << "Second User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator secondUser(id, name);
    Prietenie p(firstUser, secondUser);
    if (this->retea.removeFriendship(p))
        cout << "Friendship Removed Successfully";
    else
        cout << "FriendShip cannot be removed";
}

void Ui::DisplayFriendList() {
    int id = 0;
    string name;
    cout << "User Id: ";
    cin >> id;
    cout << "User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator user(id, name);
    if (this->retea.getUserList().GetArray().search(user)) {
        cout << user << "->" << " Lista Prieteni: ";
        for (auto i : this->retea.getSomeonesFriendList(user))
            cout << i.getNume() << " ,";
        cout << "\n";
    }
}

void Ui::addNewEvent() {
    string name, location, details;
    DataC date;
    cout << "Event name: ";
    cin.get();
    getline(cin, name);
    cout << "Date of the event: ";
    cin >> date;
    cout << "Location: ";
    cin.get();
    getline(cin, location);
    cout << "Other details: ";
    getline(cin, details);
    Eveniment e(name, date, location, details);
    this->eventController.AddEvent(e);
}

void Ui::updateEvent() {
    string name, location, details;
    DataC date;
    cout << "Old Event name: ";
    cin.get();
    getline(cin, name);
    Eveniment oldEvent(name, date, location, details);
    cout << "New Event name: ";
    cin.get();
    getline(cin, name);
    cout << "New Date of the event: ";
    cin >> date;
    cin.get();
    cout << "New Location: ";
    getline(cin, location);
    cout << "New details: ";
    getline(cin, details);
    Eveniment e(name, date, location, details);
    this->eventController.UpdateEvent(oldEvent, e);
}


void Ui::removeEvent() {
    string name, location, details;
    DataC date;
    cout << "Event name: ";
    cin.get();
    getline(cin, name);
    Eveniment e(name, date, location, details);
    this->eventController.RemoveEvent(e);
}

void Ui::addUserToEvent() {
    string name, location, details;
    DataC date;
    cout << "Event name: ";
    cin.get();
    getline(cin, name);
    cout << "Date of the event: ";
    cin >> date;
    cout << "Location: ";
    cin.get();
    getline(cin, location);
    cout << "Other details: ";
    getline(cin, details);
    Eveniment e(name, date, location, details);
    int id = 0;
    string userName;
    cout << "User Id: ";
    cin >> id;
    cout << "User Name: ";
    cin.get();
    getline(cin, userName);
    Utilizator user(id, userName);
    if (this->eventController.AddInterestedUser(e, user))
        cout << "User Added Successfully";
    else
        cout << "User cannot be added";
}

void Ui::removeUserFromEvent() {
    string name;
    DataC date(0, 0, 0);
    cout << "Event name: ";
    cin.get();
    getline(cin, name);
    Eveniment e(name, date, "", "");
    int id = 0;
    string userName;
    cout << "User Id: ";
    cin >> id;
    cout << "User Name: ";
    cin.get();
    getline(cin, userName);
    Utilizator user(id, userName);
    if (this->eventController.RemoveInterestedUser(e, user))
        cout << "User Removed Successfully";
    else
        cout << "User cannot be removed";
}

void Ui::newMessage() {
    int id = 0;
    string name;
    cout << "First User Id: ";
    cin >> id;
    cout << "First User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator firstUser(id, name);
    if (!this->retea.getUserList().GetArray().search(firstUser))
    {
        cout << "First User does not exist";
        return;
    }
    cout << "Second User Id: ";
    cin >> id;
    cout << "Second User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator secondUser(id, name);
    if (!this->retea.getUserList().GetArray().search(secondUser))
    {
        cout << "Second User does not exist";
        return;
    }
    string continut;
    cout << "Message content: ";
    cin.get();
    getline(cin, continut);
    this->messageManager.AddMessage(firstUser, secondUser, continut);
}

void Ui::deleteMessage() {
    int id = 0;
    string name;
    cout << "First User Id: ";
    cin >> id;
    cout << "First User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator firstUser(id, name);
    if (!this->retea.getUserList().GetArray().search(firstUser))
    {
        cout << "First User does not exist";
        return;
    }
    cout << "Second User Id: ";
    cin >> id;
    cout << "Second User Name: ";
    cin.get();
    getline(cin, name);
    Utilizator secondUser(id, name);
    if (!this->retea.getUserList().GetArray().search(secondUser))
    {
        cout << "Second User does not exist";
        return;
    }
    string continut;
    cout << "Message content: ";
    getline(cin, continut);
    this->messageManager.RemoveMessage(firstUser, secondUser, continut);
}
