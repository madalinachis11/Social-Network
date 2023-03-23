#include "Utilizator.h"

#include <utility>

Utilizator::Utilizator()
{
	this->id = 0;
	this->nume = "";
}

Utilizator::Utilizator(int id, std::string nume)
{
	this->id = id;
	this->nume = std::move(nume);
}

int Utilizator::getId()
{
	return this->id;
}

std::string Utilizator::getNume()
{
	return this->nume;
}

void Utilizator::setId(int id)
{
	this->id == id;
}

void Utilizator::setNume(std::string nume)
{
	this->nume = nume;
}

bool Utilizator::operator==(const Utilizator& other) const
{
	return this->id == other.id;
}

std::ostream& operator<<(std::ostream& os, const Utilizator& utilizator)
{
	return os << "Id: " << utilizator.id << " Utilizatorul: " << utilizator.nume;
}