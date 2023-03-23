#pragma once
#include <string>
#include <iostream>

class Utilizator {
private:
	int id;
	std::string nume;

public:
	Utilizator();
	Utilizator(int id, std::string nume);
	~Utilizator() = default;
	int getId();
	std::string getNume();
	void setId(int id);
	void setNume(std::string nume);
	bool operator==(const Utilizator& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Utilizator& utilizator);
};