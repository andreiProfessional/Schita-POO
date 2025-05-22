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
}

void Jucator::modificareStatistici(const int &multiplicator) {
    this->nivelViata += multiplicator * this->locatie->getCoeficientViata();
    if (this->nivelViata < 0) {
        this->nivelViata = 0;
    }
    else if (this->nivelViata > 100) {
        this->nivelViata = 100;
    }
    this->nivelHrana += multiplicator * this->locatie->getCoeficientHrana();
    if (this->nivelHrana < 0) {
        this->nivelHrana = 0;
    }
    else if (this->nivelHrana > 100) {
        this->nivelHrana = 100;
    }
    this->balantaBani += multiplicator * this->locatie->getCoeficientBani();
    if (this->balantaBani < 0) {
        this->balantaBani = 0;
    }
}

void Jucator::setLocatie(Locatie *locatie) {
    this->locatie = locatie;
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