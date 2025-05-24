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


ActivitateLocatie::ActivitateLocatie(Jucator *jucator_, const std::vector<std::pair<std::string, int>> &optiuni_):
    Activitate(jucator_),
    optiuni(optiuni_) {}

void ActivitateLocatie::afisare() {
    this->jucator->afisare(); std::cout << std::endl;
    std::cout << "Optiunile disponibile:" << std::endl;
    int numarOptiuni = this->optiuni.size();
    for (int index = 0; index < numarOptiuni; ++index) {
        std::cout << index + 1 << ". " << optiuni[index].first << std::endl;
    }
    std::cout << std::endl;
}

void ActivitateLocatie::activitate(const int &alegere) {
    this->jucator->modificareNivelViata(optiuni[alegere - 1].second * this->jucator->getCoeficientViataLocatie());
    this->jucator->modificareNivelHrana(optiuni[alegere - 1].second * this->jucator->getCoeficientHranaLocatie());
    this->jucator->modificareBalantaBani(optiuni[alegere - 1].second * this->jucator->getCoeficientBaniLocatie());
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

ActivitateStatie::ActivitateStatie(Jucator *jucator_, const std::vector<Statie*> &statiiVecine_):
    Activitate(jucator_),
    statiiVecine(statiiVecine_) {}

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
