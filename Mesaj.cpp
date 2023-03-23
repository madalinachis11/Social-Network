#include "Mesaj.h"

Mesaj::Mesaj() :
	expeditor{}, destinatar{}, continut{ " " }
{
}

Mesaj::Mesaj(Utilizator expeditor, Utilizator destinatar, string continut) :
	expeditor{ expeditor }, destinatar{ destinatar }, continut{ continut }
{
}

Mesaj::~Mesaj()
{
}

Utilizator Mesaj::getExpeditor()
{
	return this->expeditor;
}

Utilizator Mesaj::getDestinatar()
{
	return this->destinatar;
}

string Mesaj::getContinut()
{
	return this->continut;
}

void Mesaj::setExpeditor(Utilizator expeditor)
{
	this->expeditor = expeditor;
}

void Mesaj::setDestinatar(Utilizator destinatar)
{
	this->destinatar = destinatar;
}

void Mesaj::setContinut(string continut)
{
	this->continut = continut;
}

bool Mesaj::operator==(const Mesaj& other) const
{
	if (this->expeditor == other.expeditor && this->destinatar == other.destinatar && this->continut == other.continut)
		return 1;
	return 0;
}

std::ostream& operator<<(std::ostream& os, const Mesaj& mesaj)
{
	return os << "Expeditor: " << mesaj.expeditor << ", destinatar: " << mesaj.destinatar << ", continut: " << mesaj.continut;
}