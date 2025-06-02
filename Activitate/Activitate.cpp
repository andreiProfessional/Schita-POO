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





ActivitateStatie::ActivitateStatie(Jucator *jucator_, const std::unordered_map<Statie*, std::vector<Statie*>> &listeAdiacenta_):
    Activitate(jucator_) {
    this->statiePlecare = jucator_->getStatie();
    this->statiiVecine = listeAdiacenta_.at(this->statiePlecare);
    this->statieSosire = nullptr;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution distributie(1, 3);
    this->minusViata = distributie(generator);
    this->minusHrana = distributie(generator);
}

void ActivitateStatie::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Aceasta statie te va costa: "
              << ROSU << this->minusViata << RESETARE << " Viata + "
              << ROSU << this->minusHrana << RESETARE << " Hrana" << std::endl;
    std::cout << "Statii vecine:" << std::endl;
    int numarStatiiVecine = static_cast<int>(this->statiiVecine.size());
    for (int index = 0; index < numarStatiiVecine; index ++) {
        std::cout << index + 1 << ". " << *this->statiiVecine[index] << std::endl;
    }
    std::cout << std::endl;
}

void ActivitateStatie::activitate(const int &alegere) {
    if (alegere < 1 || alegere > static_cast<int>(this->statiiVecine.size())) {
        throw OptiuneIndisponibila();
    }
    this->statieSosire = this->statiiVecine[alegere - 1];
    this->jucator->setStatie(this->statieSosire);
    this->jucator->modificareNivelViata(-1 * this->minusViata);
    this->jucator->modificareNivelHrana(-1 * this->minusHrana);
}

void ActivitateStatie::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID() << " a calatorit de la statia [" << *this->statiePlecare << "] la statia [" << *this->statieSosire << "]";
}

ActivitateTaxi::ActivitateTaxi(Jucator *jucator_, const std::vector<Locatie*> &locatii_):
    Activitate(jucator_),
    locatii(locatii_) {
    locatiePlecare = jucator_->getLocatie();
    locatieSosire = nullptr;
    const int numarLocatii = static_cast<int>(this->locatii.size());
    const int pretMinim = numarLocatii / 2;
    const int pretMaxim = numarLocatii;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution distributie(pretMinim, pretMaxim);
    this->pret = distributie(generator);
}

void ActivitateTaxi::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Pret Calatorie = " << ROSU << this->pret << RESETARE  << " Lei." << std::endl;
    std::cout << "Locatii disponibile: " << std::endl;
    int numarLocatii = static_cast<int>(this->locatii.size());
    for (int index = 0; index < numarLocatii; index ++) {
        std::cout << index + 1 << ". " << *this->locatii[index] << std::endl;
    }
    std::cout << std::endl;
}

void ActivitateTaxi::activitate(const int &alegere) {
    if (alegere < 1 || alegere > static_cast<int>(this->locatii.size())) {
        throw OptiuneIndisponibila();
    }
    this->locatieSosire = locatii[alegere - 1];
    this->jucator->setLocatie(this->locatieSosire);
    this->jucator->modificareBalantaBani(-1 * this->pret);
}

void ActivitateTaxi::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID() << " a platit " << this->pret << " Lei "
    << "pentru o cursa de la locatia [" << *this->locatiePlecare << "] la locatia [" << *this->locatieSosire << "]";
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
