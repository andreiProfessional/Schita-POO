#include "Locatie.h"
#include "CuloriText.h"
#include <iostream>


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

Locatie::Locatie(const Locatie &locatie):
    id(++ contorID),
    nume(locatie.nume),
    coeficientViata(locatie.coeficientViata),
    coeficientHrana(locatie.coeficientHrana),
    coeficientBani(locatie.coeficientBani),
    statie(locatie.statie)
    {}

Locatie& Locatie::operator=(const Locatie &locatie) {
    this->nume = locatie.nume;
    this->coeficientViata = locatie.coeficientViata;
    this->coeficientHrana = locatie.coeficientHrana;
    this->coeficientBani = locatie.coeficientBani;
    this->statie = locatie.statie;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Locatie &locatie) {
    out << locatie.nume << " - ";
    if (locatie.coeficientViata > 0) {
        out << VERDE << "Viata";
    }
    else if (locatie.coeficientViata < 0) {
        out << ROSU << "Viata";
    }
    else {
        out << GALBEN << "Viata";
    }
    out << RESETARE << " | ";
    if (locatie.coeficientHrana > 0) {
        out << VERDE << "Hrana";
    }
    else if (locatie.coeficientHrana < 0) {
        out << ROSU << "Hrana";
    }
    else {
        out << GALBEN << "Hrana";
    }
    out << RESETARE << " | ";
    if (locatie.coeficientBani > 0) {
        out << VERDE << "Bani";
    }
    else if (locatie.coeficientBani < 0) {
        out << ROSU << "Bani";
    }
    else {
        out << GALBEN << "Bani";
    }
    out << RESETARE;
    return out;
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

Statie* Locatie::getStatie() const {
    return this->statie;
}