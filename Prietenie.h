#pragma once
#include "Utilizator.h"
class Prietenie {
private:
	Utilizator utilizator1;
	Utilizator utilizator2;
public:
	Prietenie();
	Prietenie(Utilizator utilizator1, Utilizator utilizator2);
	~Prietenie();
	Utilizator getUtilizator1();
	Utilizator getUtilizator2();
	void setUtilizator1(Utilizator utilizator1);
	void setUtilizator2(Utilizator utilizator2);
	bool operator==(const Prietenie& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Prietenie& prietenie);
};