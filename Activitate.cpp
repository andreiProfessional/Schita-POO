#include "Activitate.h"
#include "Jucator.h"
#include "Locatie.h"
#include <iostream>
#include <vector>


int Activitate::contorID = 0;

Activitate::Activitate(): id(++ contorID) {}

ActivitateLocatie::ActivitateLocatie(Jucator *jucator_, Locatie *locatie_,
    const std::vector<std::pair<std::string, int>> &optiuni_):
    jucator(jucator_),
    locatie(locatie_),
    optiuni(optiuni_) {}

void ActivitateLocatie::afisare() {
    this->jucator->afisare();
    this->locatie->afisare();
    std::cout << "Activitatea " << this->id << " :" << std::endl;
    int numarOptiuni = this->optiuni.size();
    for (int index = 0; index < numarOptiuni; ++index) {
        std::cout << index + 1 << ". " << optiuni[index].first << std::endl;
    }
}

void ActivitateLocatie::activitate() {
    //this->jucator->modificareStatistici()
}
