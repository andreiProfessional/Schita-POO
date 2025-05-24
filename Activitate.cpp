#include "Activitate.h"
#include "Jucator.h"
#include "Locatie.h"
#include "CuloriText.h"
#include <iostream>
#include <vector>
#include <random>

int Activitate::contorID = 0;

Activitate::Activitate(Jucator *jucator_): id(++ contorID), jucator(jucator_) {}

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
}

void ActivitateStatie::afisare() {
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Statii vecine:" << std::endl;
    int numarStatiiVecine = statiiVecine.size();
    for (int index = 0; index < numarStatiiVecine; index ++) {
        std::cout << index + 1 << ". ";
        statiiVecine[index]->afisare();
    }
    std::cout << std::endl;
}

void ActivitateStatie::activitate(const int &alegere) {
    this->jucator->setStatie(statiiVecine[alegere - 1]);
}

ActivitateTaxi::ActivitateTaxi(Jucator *jucator_, const std::vector<Locatie*> &locatii_):
    Activitate(jucator_),
    locatii(locatii_) {
    const int numarLocatii = locatii.size();
    const int pretMinim = numarLocatii / 2;
    const int pretMaxim = numarLocatii;
    std::random_device rd;  // Non-deterministic seed
    std::mt19937 gen(rd()); // Mersenne Twister generator
    std::uniform_int_distribution<> distrib(pretMinim, pretMaxim);
    this->pret = distrib(gen);
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
    this->jucator->setLocatie(locatii[alegere - 1]);
    this->jucator->modificareBalantaBani(-1 * this->pret);
}
