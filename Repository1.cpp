#include "Repository1.h"
#include <sstream>
#include <algorithm>
#include "Multime.h"

Repository1::Repository1() :
    elementsArray{ new Set<Utilizator> }
{
}

Repository1::Repository1(const Repository1& other) :
    elementsArray{ new Set<Utilizator >(*other.elementsArray) }
{
}

Repository1::~Repository1() = default;

Repository1& Repository1::operator=(const Repository1 & other)
{
    if (this == &other) return *this;

    if (this->elementsArray == nullptr) this->elementsArray = new Set<Utilizator>();
    *this->elementsArray = *other.elementsArray;

    return *this;
}


bool Repository1::operator==(const Repository1 & other) const
{
    // return *this->elementsArray == *other.elementsArray;
    return true;
}

std::ostream& operator<<(std::ostream & os, Repository1 & repo)
{
    SetIterator<Utilizator> it = repo.GetIterator();
    while (it.valid()) {
        os << it.getCurrent(), os << "\n";
        it.next();
    }
    return os;
}

SetIterator<Utilizator> Repository1::GetIterator()
{
    return this->elementsArray->iterator();
}

bool Repository1::AddElement(const Utilizator & user)
{
    return this->elementsArray->add(user);
}

bool Repository1::RemoveElement(const Utilizator & elem)
{
    return this->elementsArray->remove(elem);
}

void Repository1::UpdateId(const Utilizator & elem, int id)
{

    SetIterator<Utilizator> it = this->GetIterator();
    while (it.valid()) {
        if (it.getCurrent() == elem)
            it.getCurrent().setId(id);
        it.next();
    }
}

void Repository1::UpdateNume(const Utilizator & elem, std::string & newName)
{
    SetIterator<Utilizator> it = this->GetIterator();
    while (it.valid()) {
        if (it.getCurrent() == elem)
            it.getCurrent().setNume(newName);
        it.next();
    }
}

Utilizator Repository1::FindElemByName(const std::string & name)
{
    SetIterator<Utilizator> it = this->GetIterator();
    while (it.valid()) {
        if (it.getCurrent().getNume() == name)
            return it.getCurrent();
        it.next();
    }
    return Utilizator(0, name);
}

size_t Repository1::GetSize() const
{
    return this->elementsArray->size();
}

Set<Utilizator> Repository1::GetArray() const {
    return *this->elementsArray;
}

std::string Repository1::toString() {
    std::stringstream os;
    SetIterator<Utilizator> it = this->elementsArray->iterator();
    while (it.valid()) {
        os << it.getCurrent() << "\n";
        it.next();
    }
    return os.str();
}