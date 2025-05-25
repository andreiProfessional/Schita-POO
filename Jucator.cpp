#include "Jucator.h"
#include "CuloriText.h"
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

Jucator::Jucator(const Jucator &jucator):
    id(++ contorID),
    nume(jucator.nume),
    nivelViata(jucator.nivelViata),
    nivelHrana(jucator.nivelHrana),
    balantaBani(jucator.balantaBani),
    locatie(jucator.locatie),
    statie(jucator.statie)
    {}

Jucator& Jucator::operator=(const Jucator &jucator) {
    this->nume = jucator.nume;
    this->nivelViata = jucator.nivelViata;
    this->nivelHrana = jucator.nivelHrana;
    this->balantaBani = jucator.balantaBani;
    this->locatie = jucator.locatie;
    this->statie = jucator.statie;
    return *this;
}

void Jucator::afisare() const {
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "Nume: " << this->nume << std::endl;
    std::cout << "Bani: " << this->balantaBani << " Lei" << std::endl;
    std::cout << "Viata: " << "[";
    int nivelAfisajViata = (this->nivelViata + 9) / 10;
    for (int i = 0; i < nivelAfisajViata; i ++) {
        std::cout << INIMA_ROSIE;
        if (i != 9) {
            std::cout << "|";
        }
    }
    for (int i = nivelAfisajViata; i < 10; i ++) {
        std::cout << INIMA_NEAGRA;
        if (i != 9) {
            std::cout << "|";
        }
    }
    std::cout << "]" << std::endl;
    std::cout << "Hrana: " << "[";
    int nivelAfisajHrana = (this->nivelHrana + 9) / 10;
    for (int i = 0; i < nivelAfisajHrana; i ++) {
        std::cout << COPAN_PLIN;
        if (i != 9) {
            std::cout << "|";
        }
    }
    for (int i = nivelAfisajHrana; i < 10; i ++) {
        std::cout << COPAN_GOL;
        if (i != 9) {
            std::cout << "|";
        }
    }
    std::cout << "]" << std::endl;
    if (locatie != nullptr) {
        std::cout << "Locatie: ";
        this->locatie->afisare();
    }
    if (statie != nullptr) {
        std::cout << "Statie: ";
        this->statie->afisare();
    }
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
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

Locatie *Jucator::getLocatie() {
    return this->locatie;
}


Statie* Jucator::getStatie() {
    return this->statie;
}


void Jucator::setLocatie(Locatie *locatie_) {
    this->locatie = locatie_;
}

void Jucator::setStatie(Statie *statie_) {
    this->statie = statie_;
}


Jucator* JucatorFactory::tataBogat(const std::string &nume_) {
    return new Jucator(nume_, 90, 80, 2000, nullptr, nullptr);
}

Jucator* JucatorFactory::tataSarac(const std::string &nume_) {
    return new Jucator(nume_, 45, 40, 500, nullptr, nullptr);
}

Jucator* JucatorFactory::magnatBatran(const std::string &nume_) {
    return new Jucator(nume_, 40, 70, 5000, nullptr, nullptr);
}

Jucator* JucatorFactory::omDeRand(const std::string &nume_) {
    return new Jucator(nume_, 75, 75, 750, nullptr, nullptr);
}

Jucator* JucatorFactory::pierdeVara(const std::string &nume_) {
    return new Jucator(nume_, 80, 40, 350, nullptr, nullptr);
}