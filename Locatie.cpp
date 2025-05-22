#include "Locatie.h"
#include <iostream>


int Locatie::contorID = 0;

Locatie::Locatie(const std::string &nume_, const int &coeficientViata_, const int &coeficientHrana_, const int &coeficientBani_):
    id(++ contorID),
    nume(nume_),
    coeficientViata(coeficientViata_),
    coeficientHrana(coeficientHrana_),
    coeficientBani(coeficientBani_)
{}

void Locatie::afisare() const {
    std::cout << "Locatia " << this->id << " : "
              << this->nume << " | "
              << this->coeficientViata << " | "
              << this->coeficientHrana << " | "
              << this->coeficientBani << std::endl;
}