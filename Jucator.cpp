#include "Jucator.h"

#include <algorithm>

#include "CuloriText.h"
#include <iostream>

#include "Exceptii.h"


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

bool operator>(const Jucator &jucator1, const Jucator &jucator2) {
    if ((jucator1.nivelViata + 9) / 10 > (jucator2.nivelViata + 9) / 10) {
        return true;
    }
    if ((jucator1.nivelViata + 9) / 10 < (jucator2.nivelViata + 9) / 10) {
        return false;
    }
    if ((jucator1.nivelHrana + 9) / 10 > (jucator2.nivelHrana + 9) / 10) {
        return true;
    }
    if ((jucator1.nivelHrana + 9) / 10 < (jucator2.nivelHrana + 9) / 10) {
        return false;
    }
    if (jucator1.balantaBani > jucator2.balantaBani) {
        return true;
    }
    if (jucator1.balantaBani < jucator2.balantaBani) {
        return false;
    }
    return jucator1.nume.length() <= jucator2.nume.length();
}

Jucator& Jucator::operator+=(const Jucator &jucator) {
    this->nivelViata = (this->nivelViata + jucator.nivelViata) / 2;
    this->nivelHrana = (this->nivelHrana + jucator.nivelHrana) / 2;
    this->balantaBani = std::max(this->balantaBani, jucator.balantaBani);
    return *this;
}

void Jucator::modificareNivelViata(const int &diferentaViata) {
    if (this->nivelViata + diferentaViata <= 0) {
        throw InsuficientaViata();
    }
    this->nivelViata += diferentaViata;
    if (this->nivelViata > 100) {
        this->nivelViata = 100;
    }
}

void Jucator::modificareNivelHrana(const int &diferentaHrana) {
    if (this->nivelHrana + diferentaHrana <= 0) {
        throw InsuficientaHrana();
    }
    this->nivelHrana += diferentaHrana;
    if (this->nivelHrana > 100) {
        this->nivelHrana = 100;
    }
}

void Jucator::modificareBalantaBani(const int &diferentaBani) {
    if (this->balantaBani + diferentaBani <= 0) {
        throw InsuficientaBani();
    }
    this->balantaBani += diferentaBani;
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