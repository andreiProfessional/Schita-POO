#include "Statie.h"
#include <iostream>


int Statie::contorID = 0;

Statie::Statie(const std::string &nume_, const std::vector<std::string> &rute_):
    id(++ contorID),
    nume(nume_),
    rute(rute_)
{}

Statie::Statie(const Statie &statie):
    id(++ contorID),
    nume(statie.nume),
    rute(statie.rute)
    {}

Statie& Statie::operator=(const Statie &statie) {
    this->nume = statie.nume;
    this->rute = statie.rute;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Statie &statie) {
    out << statie.nume << " - ";
    const int numarRute = statie.rute.size();
    for (int index = 0; index < numarRute - 1; index ++) {
        out << statie.rute[index] << " + ";
    }
    out << statie.rute[numarRute - 1];
    out << std::endl;
    return out;
}

void Statie::adaugareRuta(const std::string &ruta) {
    this->rute.push_back(ruta);
}