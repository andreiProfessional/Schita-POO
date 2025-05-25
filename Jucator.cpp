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

std::ostream& operator<<(std::ostream &out, const Jucator &jucator) {
    for (int i = 0; i < 50; i ++) {
        out << "=";
    }
    out << std::endl;
    out << "Nume: " << jucator.nume << std::endl;
    out << "Bani: " << jucator.balantaBani << " Lei" << std::endl;
    out << "Viata: " << "[";
    int nivelAfisajViata = (jucator.nivelViata + 9) / 10;
    for (int i = 0; i < nivelAfisajViata; i ++) {
        out << INIMA_ROSIE;
        if (i != 9) {
            out << "|";
        }
    }
    for (int i = nivelAfisajViata; i < 10; i ++) {
        out << INIMA_NEAGRA;
        if (i != 9) {
            out << "|";
        }
    }
    out << "]" << std::endl;
    out << "Hrana: " << "[";
    int nivelAfisajHrana = (jucator.nivelHrana + 9) / 10;
    for (int i = 0; i < nivelAfisajHrana; i ++) {
        out << COPAN_PLIN;
        if (i != 9) {
            out << "|";
        }
    }
    for (int i = nivelAfisajHrana; i < 10; i ++) {
        out << COPAN_GOL;
        if (i != 9) {
            out << "|";
        }
    }
    out << "]" << std::endl;
    if (jucator.locatie != nullptr) {
        out << "Locatie: " << *jucator.locatie;
    }
    if (jucator.statie != nullptr) {
        out << "Statie: " << *jucator.statie;
    }
    for (int i = 0; i < 50; i ++) {
        out << "=";
    }
    out << std::endl;
    return out;
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