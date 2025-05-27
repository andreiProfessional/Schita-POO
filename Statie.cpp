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
    const int numarRute = static_cast<int>(statie.rute.size());
    for (int index = 0; index < numarRute - 1; index ++) {
        out << statie.rute[index] << " + ";
    }
    out << statie.rute[numarRute - 1];
    out << std::endl;
    return out;
}

std::istream& operator>>(std::istream &in, Statie &statie) {
    std::string input;
    std::getline(in, input);
    auto pozitieVirgula = input.find(',');
    statie.nume = input.substr(0, pozitieVirgula);
    input = input.erase(0, pozitieVirgula + 1);
    while (input.find(';') != std::string::npos) {
        statie.adaugareRuta(input.substr(0, input.find(';')));
        input = input.erase(0, input.find(';') + 1);
    }
    statie.adaugareRuta(input);
    return in;
}

void Statie::adaugareRuta(const std::string &ruta) {
    this->rute.push_back(ruta);
}