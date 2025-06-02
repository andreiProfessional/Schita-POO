#include "StatieCatreLocatie.h"
#include "../Exceptii.h"
#include <iostream>


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