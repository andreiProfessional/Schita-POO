#include "Activitate.h"
#include "../Jucator/Jucator.h"
#include "../Locatie.h"
#include "../Exceptii.h"
#include "../CuloriText.h"
#include <iostream>
#include <vector>
#include <random>

int Activitate::contorID = 0;

Activitate::Activitate(Jucator *jucator_): id(++ contorID), jucator(jucator_) {}

Activitate::Activitate(const Activitate &activitate):
    id(++ contorID),
    jucator(activitate.jucator) {}

Activitate& Activitate::operator=(const Activitate &activitate) {
    this->jucator = activitate.jucator;
    return *this;
}


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

StatieCatreLocatie::StatieCatreLocatie(Jucator *jucator_, const std::vector<Locatie*> &locatii_):
    Activitate(jucator_) {
    this->statie = this->jucator->getStatie();
    std::vector<Locatie*> locatiiValide;
    for (const auto &locatie_: locatii_) {
        if (locatie_->getStatie() == this->statie) {
            locatiiValide.push_back(locatie_);
        }
    }
    this->locatii = locatiiValide;
    this->locatie = nullptr;
}

void StatieCatreLocatie::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Locatii apropiate: " << std::endl;
    const int numarLocatii = static_cast<int>(this->locatii.size());
    for (int index = 0; index < numarLocatii; index ++) {
        std::cout << index + 1 << ". " << *this->locatii[index] << std::endl;
    }
}

void StatieCatreLocatie::activitate(const int &alegere) {
    if (alegere < 1 || alegere > static_cast<int>(this->locatii.size())) {
        throw OptiuneIndisponibila();
    }
    this->jucator->setStatie(nullptr);
    this->locatie = this->locatii[alegere - 1];
    this->jucator->setLocatie(this->locatie);
}

void StatieCatreLocatie::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID()
    << " a mers de la statia [" << *this->statie << "] la locatia [" << *this->locatie << "]";
}
