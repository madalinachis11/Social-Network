#include "Repository3.h"
#include <sstream>
#include <algorithm>

Repository3::Repository3() :
    elementsArray{ new std::vector<Mesaj> }
{
}

Repository3::Repository3(const Repository3& other) :
    elementsArray{ new std::vector<Mesaj>(*other.elementsArray) }
{
}

Repository3::~Repository3()
{
    delete this->elementsArray;
    this->elementsArray = nullptr;
}

Repository3& Repository3::operator=(const Repository3& other)
{
    if (this == &other) return *this;

    if (this->elementsArray == nullptr) this->elementsArray = new std::vector<Mesaj>();
    *this->elementsArray = *other.elementsArray;

    return *this;
}

Mesaj& Repository3:: operator[](size_t position)
{
    return (*this->elementsArray)[position];
}

bool Repository3::operator==(const Repository3& other) const
{
    return *this->elementsArray == *other.elementsArray;
}

std::ostream& operator<<(std::ostream& os, const Repository3& repo)
{
    for (int i = 0; i < repo.GetSize(); i++)
        os << (*repo.elementsArray)[i], os << "\n";
    return os;
}

void Repository3::AddElement(const Mesaj& mesaj)
{
    this->elementsArray->push_back(mesaj);
}

void Repository3::RemoveElement(const Mesaj& elem)
{
    auto a = std::remove(this->elementsArray->begin(), this->elementsArray->end(), elem);
    this->elementsArray->erase(a, this->elementsArray->end());
}

size_t Repository3::GetSize() const
{
    return this->elementsArray->size();
}

std::vector<Mesaj> Repository3::GetArray() const {
    return *this->elementsArray;
}