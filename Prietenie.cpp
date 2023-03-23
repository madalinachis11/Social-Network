#include "Prietenie.h"

Prietenie::Prietenie() :
	utilizator1{}, utilizator2{}
{
}

Prietenie::Prietenie(Utilizator utilizator1, Utilizator utilizator2) :
	utilizator1{ utilizator1 }, utilizator2{ utilizator2 }
{
}

Prietenie::~Prietenie()
{
}

Utilizator Prietenie::getUtilizator1()
{
	return this->utilizator1;
}

Utilizator Prietenie::getUtilizator2()
{
	return this->utilizator2;
}

void Prietenie::setUtilizator1(Utilizator utilizator1)
{
	this->utilizator1 = utilizator1;
}

void Prietenie::setUtilizator2(Utilizator utilizator2)
{
	this->utilizator2 = utilizator2;
}

bool Prietenie::operator==(const Prietenie& other) const
{
	if (this->utilizator1 == other.utilizator1)
		if (this->utilizator2 == other.utilizator2)
			return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Prietenie& prietenie)
{
	return os << "Prietenie intre utilizatorul: " << prietenie.utilizator1 << " si utilizatorul: " << prietenie.utilizator2;
}