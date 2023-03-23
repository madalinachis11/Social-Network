#include "Repository2.h"
#include <sstream>
#include <algorithm>

Repository2::Repository2() :
    elementsArray{ new Set<Prietenie> }
{
}

Repository2::Repository2(const Repository2& other) :
    elementsArray{ new Set<Prietenie >(*other.elementsArray) }
{
}

Repository2::~Repository2() = default;

Repository2& Repository2::operator=(const Repository2 & other)
{
    if (this == &other) return *this;

    if (this->elementsArray == nullptr) this->elementsArray = new Set<Prietenie>();
    *this->elementsArray = *other.elementsArray;

    return *this;
}


bool Repository2::operator==(const Repository2 & other) const
{
    // return *this->elementsArray == *other.elementsArray;
    return true;
}

std::ostream& operator<<(std::ostream & os, Repository2 & repo)
{
    SetIterator<Prietenie> it = repo.GetIterator();
    while (it.valid()) {
        os << it.getCurrent(), os << "\n";
        it.next();
    }
    return os;
}

std::string Repository2::toString()
{
    std::stringstream os;
    SetIterator<Prietenie> it = this->elementsArray->iterator();
    while (it.valid()) {
        os << it.getCurrent(), os << "\n";
        it.next();
    }
    return os.str();
}

SetIterator<Prietenie> Repository2::GetIterator()
{
    return this->elementsArray->iterator();
}

bool Repository2::AddElement(const Prietenie & p)
{
    return this->elementsArray->add(p);
}

bool Repository2::RemoveElement(const Prietenie & p)
{
    return this->elementsArray->remove(p);
}

size_t Repository2::GetSize() const
{
    return this->elementsArray->size();
}

Set<Prietenie> Repository2::GetArray() const {
    return *this->elementsArray;
}