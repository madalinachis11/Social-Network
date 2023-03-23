#include "Eveniment.h"

#include <utility>

Eveniment::Eveniment() :
    nume{}, data{}, locatie{ " " }, detalii{ " " }
{
}

Eveniment::Eveniment(string nume, DataC data, string locatie, string detalii) :
    nume{ nume }, data{ data }, locatie{ std::move(locatie) }, detalii{ std::move(detalii) }
{
}

Eveniment::~Eveniment()
{
}

string Eveniment::getNume()
{
    return this->nume;
}

DataC Eveniment::getData()
{
    return this->data;
}

string Eveniment::getLocatie()
{
    return this->locatie;
}

string Eveniment::getDetalii()
{
    return this->detalii;
}

void Eveniment::setNume(string nume)
{
    this->nume = nume;
}

void Eveniment::setData(DataC data)
{
    this->data = data;
}

void Eveniment::setLocatie(string locatie)
{
    this->locatie = locatie;
}

void Eveniment::setDetalii(string detalii)
{
    this->detalii = detalii;
}

bool Eveniment::operator==(const Eveniment& other) const
{
    return this->nume == other.nume;
}

ostream& operator<<(std::ostream& os, const Eveniment& eveniment)
{
    return os << "Evenimentul: " << eveniment.nume << " din data: " << eveniment.data << ", care are loc: " << eveniment.locatie << " detalii: " << eveniment.detalii;
}