#include "SpawnStatie.h"
#include "../Exceptii.h"
#include <iostream>

SpawnStatie::SpawnStatie(Jucator *jucator_, const std::unordered_map<Statie*, std::vector<Statie*>> &listeAdiacenta_):
    Activitate(jucator_) {
    std::vector<Statie*> statii_;
    for (const auto &statie: listeAdiacenta_) {
        statii_.push_back(statie.first);
    }
    statii = statii_;
    statieSpawn = nullptr;
}

void SpawnStatie::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Statii disponibile: " << std::endl;
    const int numarStatii = static_cast<int>(this->statii.size());
    for (int index = 0; index < numarStatii; index ++) {
        std::cout << index + 1 << ". " << *this->statii[index] << std::endl;
    }
}

void SpawnStatie::activitate(const int &alegere) {
    if (alegere < 1 || alegere > static_cast<int>(this->statii.size())) {
        throw OptiuneIndisponibila();
    }
    this->statieSpawn = this->statii[alegere - 1];
    this->jucator->setStatie(this->statieSpawn);
}

void SpawnStatie::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID() << " s-a spawnat la statia: " << *this->statieSpawn;
}