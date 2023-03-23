#include "Repository4.h"
#include "MultiMapIt.h"
#include <sstream>
#include <algorithm>

Repository4::Repository4() :
    elementsArray{ new MultiMap<Eveniment, Utilizator> }
{
}

Repository4::Repository4(const Repository4& other) :
    elementsArray{ new MultiMap<Eveniment, Utilizator>(*other.elementsArray) }
{
}

Repository4::~Repository4() = default;


void Repository4::AddInterestedPerson(Eveniment event, Utilizator user)
{
    this->elementsArray->add(event, user);
}

bool Repository4::RemoveInterestedPerson(const Eveniment & elem, const Utilizator & user)
{
    return this->elementsArray->remove(elem, user);
}

void Repository4::RemoveEvent(const Eveniment & elem)
{
    std::vector<Utilizator> toDelete = this->elementsArray->search(elem);
    for (const auto& a : toDelete)
        this->elementsArray->remove(elem, a);
}

bool Repository4::UpdateEventData(const Eveniment & oldEvent, const Eveniment & newEvent) {
    return this->elementsArray->updateKey(oldEvent, newEvent);
}

vector<Utilizator> Repository4::FindInterestedToEvent(const Eveniment & event) const
{
    return this->elementsArray->search(event);
}

size_t Repository4::GetSize() const
{
    return this->elementsArray->size();
}

MultiMap<Eveniment, Utilizator> Repository4::GetArray() const {
    return *this->elementsArray;
}

MultiMapIterator<Eveniment, Utilizator> Repository4::GetIterator() {
    return this->elementsArray->iterator();
}

std::string Repository4::toString() {
    stringstream os;
    std::vector<Eveniment> events = this->elementsArray->getKeys();
    for (const auto& ev : events)
    {
        os << ev << "; Utilizator interesati: \n";
        for (const auto& us : this->elementsArray->search(ev))
            os << us << "\n";
    }
    return os.str();
}