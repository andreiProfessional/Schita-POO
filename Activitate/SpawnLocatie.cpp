#include "SpawnLocatie.h"
#include "../Exceptii.h"
#include <iostream>

SpawnLocatie::SpawnLocatie(Jucator *jucator_, const std::vector<Locatie*> &locatii_):
    Activitate(jucator_),
    locatii(locatii_) {
    locatieSpawn = nullptr;
}

void SpawnLocatie::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Locatii disponibile: " << std::endl;
    const int numarLocatii = static_cast<int>(this->locatii.size());
    for (int index = 0; index < numarLocatii; index ++) {
        std::cout << index + 1 << ". " << *this->locatii[index] << std::endl;
    }
    std::cout << std::endl;
}

void SpawnLocatie::activitate(const int &alegere) {
    if (alegere < 1 || alegere > static_cast<int>(this->locatii.size())) {
        throw OptiuneIndisponibila();
    }
    this->locatieSpawn = locatii[alegere - 1];
    this->jucator->setLocatie(locatieSpawn);
}

void SpawnLocatie::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID() << " s-a spawnat la locatia: " << *this->locatieSpawn;
}