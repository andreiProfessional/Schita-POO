#include "Statie.h"
#include <iostream>


int Statie::contorID = 0;

Statie::Statie(const std::string &nume_, const std::vector<std::string> &rute_):
    id(++ contorID),
    nume(nume_),
    rute(rute_)
{}

void Statie::afisare() const {
    std::cout << this->nume << " - ";
    const int numarRute = this->rute.size();
    for (int index = 0; index < numarRute - 1; index ++) {
        std::cout << rute[index] << " + ";
    }
    std::cout << rute[numarRute - 1];
    std::cout << std::endl;
}

void Statie::adaugareRuta(const std::string &ruta) {
    this->rute.push_back(ruta);
}