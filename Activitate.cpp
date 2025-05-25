#include "Activitate.h"
#include "Jucator.h"
#include "Locatie.h"
#include "CuloriText.h"
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

SpawnLocatie::SpawnLocatie(Jucator *jucator_, const std::vector<Locatie*> &locatii_):
    Activitate(jucator_),
    locatii(locatii_) {
    locatieSpawn = nullptr;
}

void SpawnLocatie::afisare() {
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Locatii disponibile: " << std::endl;
    const int numarLocatii = locatii.size();
    for (int index = 0; index < numarLocatii; index ++) {
        std::cout << index + 1 << ". ";
        locatii[index]->afisare();
    }
    std::cout << std::endl;
}

void SpawnLocatie::activitate(const int &alegere) {
    this->locatieSpawn = locatii[alegere - 1];
    this->jucator->setLocatie(locatieSpawn);
}

SpawnStatie::SpawnStatie(Jucator *jucator_, const std::unordered_map<Statie*, std::vector<Statie*>> &listeAdiacenta_):
    Activitate(jucator_) {
    std::vector<Statie*> statii_;
    for (const auto &pereche: listeAdiacenta_) {
        statii_.push_back(pereche.first);
    }
    statii = statii_;
    statieSpawn = nullptr;
}

void SpawnStatie::afisare() {
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Statii disponibile: " << std::endl;
    const int numarStatii = statii.size();
    for (int index = 0; index < numarStatii; index ++) {
        std::cout << index + 1 << ". ";
        statii[index]->afisare();
    }
}

void SpawnStatie::activitate(const int &alegere) {
    this->statieSpawn = this->statii[alegere - 1];
    this->jucator->setStatie(this->statieSpawn);
}

ActivitateLocatie::ActivitateLocatie(Jucator *jucator_, const std::vector<std::pair<std::string, int>> &optiuni_):
    Activitate(jucator_),
    optiuni(optiuni_) {}

void ActivitateLocatie::afisare() {
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Optiunile disponibile:" << std::endl;
    int numarOptiuni = this->optiuni.size();
    for (int index = 0; index < numarOptiuni; ++index) {
        std::cout << index + 1 << ". " << this->optiuni[index].first << std::endl;
    }
    std::cout << std::endl;
}

void ActivitateLocatie::activitate(const int &alegere) {
    this->optiuneAleasa = this->optiuni[alegere - 1];
    this->jucator->modificareNivelViata(this->optiuneAleasa.second * this->jucator->getCoeficientViataLocatie());
    this->jucator->modificareNivelHrana(this->optiuneAleasa.second * this->jucator->getCoeficientHranaLocatie());
    this->jucator->modificareBalantaBani(this->optiuneAleasa.second * this->jucator->getCoeficientBaniLocatie());
}

ActivitateStatie::ActivitateStatie(Jucator *jucator_, const std::unordered_map<Statie*, std::vector<Statie*>> &listeAdiacenta_):
    Activitate(jucator_) {
    this->statiePlecare = jucator_->getStatie();
    this->statiiVecine = listeAdiacenta_.at(this->statiePlecare);
    this->statieSosire = nullptr;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distributie(1, 3);
    this->minusViata = distributie(generator);
    this->minusHrana = distributie(generator);
}

void ActivitateStatie::afisare() {
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Aceasta statie te va costa: "
              << ROSU << this->minusViata << RESETARE << " Viata + "
              << ROSU << this->minusHrana << RESETARE << " Hrana" << std::endl;
    std::cout << "Statii vecine:" << std::endl;
    int numarStatiiVecine = statiiVecine.size();
    for (int index = 0; index < numarStatiiVecine; index ++) {
        std::cout << index + 1 << ". ";
        statiiVecine[index]->afisare();
    }
    std::cout << std::endl;
}

void ActivitateStatie::activitate(const int &alegere) {
    this->statieSosire = this->statiiVecine[alegere - 1];
    this->jucator->setStatie(this->statieSosire);
    this->jucator->modificareNivelViata(-1 * this->minusViata);
    this->jucator->modificareNivelHrana(-1 * this->minusHrana);
}

ActivitateTaxi::ActivitateTaxi(Jucator *jucator_, const std::vector<Locatie*> &locatii_):
    Activitate(jucator_),
    locatii(locatii_) {
    locatiePlecare = jucator_->getLocatie();
    locatieSosire = nullptr;
    const int numarLocatii = locatii.size();
    const int pretMinim = numarLocatii / 2;
    const int pretMaxim = numarLocatii;
    std::random_device rd;  // Non-deterministic seed
    std::mt19937 generator(rd()); // Mersenne Twister generator
    std::uniform_int_distribution<> distributie(pretMinim, pretMaxim);
    this->pret = distributie(generator);
}

void ActivitateTaxi::afisare() {
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Pret Calatorie = " << ROSU << this->pret << RESETARE  << " Lei." << std::endl;
    std::cout << "Locatii disponibile: " << std::endl;
    int numarLocatii = this->locatii.size();
    for (int index = 0; index < numarLocatii; index ++) {
        std::cout << index + 1 << ". ";
        locatii[index]->afisare();
    }
    std::cout << std::endl;
}

void ActivitateTaxi::activitate(const int &alegere) {
    this->locatieSosire = locatii[alegere - 1];
    this->jucator->setLocatie(this->locatieSosire);
    this->jucator->modificareBalantaBani(-1 * this->pret);
}

LocatieCatreStatie::LocatieCatreStatie(Jucator *jucator_):
    Activitate(jucator_) {
    this->locatie = jucator_->getLocatie();
    this->statie = nullptr;
}

void LocatieCatreStatie::afisare() {
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Statie apropiata: ";
    this->locatie->getStatie()->afisare();
    std::cout << std::endl;
    std::cout << "1. Mergi la locatie" << std::endl;
    std::cout << "2. Ramai pe loc" << std::endl;
}

void LocatieCatreStatie::activitate(const int &alegere) {
    if (alegere == 1) {
        this->jucator->setLocatie(nullptr);
        this->statie = this->locatie->getStatie();
        this->jucator->setStatie(this->statie);
    }
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
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Locatii apropiate: " << std::endl;
    const int numarLocatii = this->locatii.size();
    for (int index = 0; index < numarLocatii; index ++) {
        std::cout << index + 1 << ". ";
        this->locatii[index]->afisare();
    }
}

void StatieCatreLocatie::activitate(const int &alegere) {
    this->jucator->setStatie(nullptr);
    this->locatie = this->locatii[alegere - 1];
    this->jucator->setLocatie(this->locatie);
}
