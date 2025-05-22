#include "Activitate.h"
#include "Jucator.h"
#include "Locatie.h"
#include <iostream>
#include <vector>


int Activitate::contorID = 0;

Activitate::Activitate(): id(++ contorID) {}

ActivitateLocatie::ActivitateLocatie(Jucator *jucator_, const std::vector<std::pair<std::string, int>> &optiuni_):
    jucator(jucator_),
    optiuni(optiuni_) {}

void ActivitateLocatie::afisare() {
    this->jucator->afisare();
    std::cout << "Activitatea " << this->id << " :" << std::endl;
    int numarOptiuni = this->optiuni.size();
    for (int index = 0; index < numarOptiuni; ++index) {
        std::cout << index + 1 << ". " << optiuni[index].first << std::endl;
    }
}

void ActivitateLocatie::activitate(const int &alegere) {
    this->jucator->modificareStatistici(optiuni[alegere - 1].second);
    // TODO: Caz Moarte
}

ActivitateTaxi::ActivitateTaxi(Jucator *jucator_, const std::vector<Locatie*> &locatii_):
    jucator(jucator_),
    locatii(locatii_) {}

void ActivitateTaxi::afisare() {
    this->jucator->afisare();
    std::cout << std::endl << "Locatii disponibile: " << std::endl;
    for (const auto &locatie: this->locatii) {
        locatie->afisare();
    }
}

void ActivitateTaxi::activitate(const int &alegere) {
    this->jucator->setLocatie(locatii[alegere - 1]);
}

