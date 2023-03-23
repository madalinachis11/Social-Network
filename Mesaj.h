#pragma once
#include <string>
#include<iostream>
#include "Utilizator.h"

using namespace std;

class Mesaj {
private:
	Utilizator expeditor;
	Utilizator destinatar;
	string continut;
public:
	Mesaj();
	Mesaj(Utilizator expeditor, Utilizator destinatar, string continut);
	~Mesaj();
	Utilizator getExpeditor();
	Utilizator getDestinatar();
	string getContinut();
	void setExpeditor(Utilizator expeditor);
	void setDestinatar(Utilizator destinatar);
	void setContinut(string continut);
	bool operator==(const Mesaj& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Mesaj& mesaj);
};