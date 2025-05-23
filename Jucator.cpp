#include "Jucator.h"
#include <iostream>


int Jucator::contorID = 0;

Jucator::Jucator(const std::string &nume_, const int &nivelViata_, const int &nivelHrana_, const int &balantaBani_,
    Locatie *locatie_, Statie *statie_):
    id(++ contorID),
    nume(nume_),
    nivelViata(nivelViata_),
    nivelHrana(nivelHrana_),
    balantaBani(balantaBani_),
    locatie(locatie_),
    statie(statie_)
    {}

void Jucator::afisare() const {
    std::cout << "Jucatorul " << this->id << " : "
              << this->nume << " | "
              << this->nivelViata << " | "
              << this->nivelHrana << " | "
              << this-> balantaBani << std::endl;
    this->locatie->afisare();
    this->statie->afisare();
}

void Jucator::modificareNivelViata(const int &diferentaViata) {
    this->nivelViata += diferentaViata;
    if (nivelViata < 0) {
        nivelViata = 0;
    }
    else if (nivelViata > 100) {
        nivelViata = 100;
    }
}

void Jucator::modificareNivelHrana(const int &diferentaHrana) {
    this->nivelHrana += diferentaHrana;
    if (this->nivelHrana < 0) {
        this->nivelHrana = 0;
    }
    else if (this->nivelHrana > 100) {
        this->nivelHrana = 100;
    }
}

void Jucator::modificareBalantaBani(const int &diferentaBani) {
    this->balantaBani += diferentaBani;
    if (balantaBani < 0) {
        balantaBani = 0;
    }
}

int Jucator::getCoeficientViataLocatie() {
    return this->locatie->getCoeficientViata();
}

int Jucator::getCoeficientHranaLocatie() {
    return this->locatie->getCoeficientHrana();
}

int Jucator::getCoeficientBaniLocatie() {
    return this->locatie->getCoeficientBani();
}

void Jucator::setLocatie(Locatie *locatie) {
    this->locatie = locatie;
}

void Jucator::setStatie(Statie *statie) {
    this->statie = statie;
}


Jucator* JucatorFactory::tataBogat(const std::string &nume_, Locatie *locatie, Statie *statie) {
    return new Jucator(nume_, 90, 80, 2000, locatie, statie);
}

Jucator* JucatorFactory::tataSarac(const std::string &nume_, Locatie *locatie, Statie *statie) {
    return new Jucator(nume_, 45, 40, 500, locatie, statie);
}

Jucator* JucatorFactory::magnatBatran(const std::string &nume_, Locatie *locatie, Statie *statie) {
    return new Jucator(nume_, 40, 70, 5000, locatie, statie);
}

Jucator* JucatorFactory::omDeRand(const std::string &nume_, Locatie *locatie, Statie *statie) {
    return new Jucator(nume_, 75, 75, 750, locatie, statie);
}

Jucator* JucatorFactory::pierdeVara(const std::string &nume_, Locatie *locatie, Statie *statie) {
    return new Jucator(nume_, 80, 40, 350, locatie, statie);
}