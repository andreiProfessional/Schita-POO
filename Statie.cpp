#include "Statie.h"
#include <iostream>


int Statie::contorID = 0;

Statie::Statie(const std::string &nume_, const std::vector<std::string> &rute_):
    id(++ contorID),
    nume(nume_),
    rute(rute_)
{}

void Statie::afisare() const {
    std::cout << "Statia " << this->id << " : "
              << this->nume << " | ";
    for (auto &ruta: this->rute) {
        std::cout << ruta << "   ";
    }
    std::cout << std::endl;
}

void Statie::adaugareRuta(const std::string &ruta) {
    this->rute.push_back(ruta);
}