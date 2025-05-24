#include "Locatie.h"
#include "CuloriText.h"
#include <iostream>
#include <vector>


int Locatie::contorID = 0;

Locatie::Locatie(const std::string &nume_,
    const int &coeficientViata_, const int &coeficientHrana_, const int &coeficientBani_,
    Statie *statie_):
    id(++ contorID),
    nume(nume_),
    coeficientViata(coeficientViata_),
    coeficientHrana(coeficientHrana_),
    coeficientBani(coeficientBani_),
    statie(statie_) {}

void Locatie::afisare() const {
    std::cout << this->nume << " - ";
    if (coeficientViata > 0) {
        std::cout << VERDE << "Viata";
    }
    else if (coeficientViata < 0) {
        std::cout << ROSU << "Viata";
    }
    else {
        std::cout << GALBEN << "Viata";
    }
    std::cout << RESETARE << " | ";
    if (coeficientHrana > 0) {
        std::cout << VERDE << "Hrana";
    }
    else if (coeficientHrana < 0) {
        std::cout << ROSU << "Hrana";
    }
    else {
        std::cout << GALBEN << "Hrana";
    }
    std::cout << RESETARE << " | ";
    if (coeficientBani > 0) {
        std::cout << VERDE << "Bani";
    }
    else if (coeficientBani < 0) {
        std::cout << ROSU << "Bani";
    }
    else {
        std::cout << GALBEN << "Bani";
    }
    std::cout << RESETARE << std::endl;
}

int Locatie::getCoeficientViata() const {
    return this->coeficientViata;
}

int Locatie::getCoeficientHrana() const {
    return this->coeficientHrana;
}

int Locatie::getCoeficientBani() const {
    return this->coeficientBani;
}