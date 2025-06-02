#include "LocatieCatreStatie.h"
#include "../Exceptii.h"
#include <iostream>

LocatieCatreStatie::LocatieCatreStatie(Jucator *jucator_):
    Activitate(jucator_) {
    this->locatie = jucator_->getLocatie();
    this->statie = nullptr;
}

void LocatieCatreStatie::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Statie apropiata: " << *this->locatie->getStatie() << std::endl;
    std::cout << "1. Mergi la locatie" << std::endl;
    std::cout << "2. Ramai pe loc" << std::endl;
}

void LocatieCatreStatie::activitate(const int &alegere) {
    if (alegere < 1 || alegere > 2) {
        throw OptiuneIndisponibila();
    }
    this->jucator->setLocatie(nullptr);
    this->statie = this->locatie->getStatie();
    this->jucator->setStatie(this->statie);
}

void LocatieCatreStatie::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID()
    << " a mers de la locatia [" << *this->locatie << "] la statia [" << *this->statie << "]";
}