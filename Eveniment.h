#pragma once
#include "DataC.h"

class Eveniment {
private:
    string nume;
    DataC data;
    string locatie;
    string detalii;
public:
    Eveniment();
    Eveniment(string nume, DataC data, string locatie, string detalii);
    ~Eveniment();
    string getNume();
    DataC getData();
    string getLocatie();
    string getDetalii();
    void setNume(string nume);
    void setData(DataC data);
    void setLocatie(string locatie);
    void setDetalii(string detalii);
    bool operator==(const Eveniment& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Eveniment& eveniment);
};