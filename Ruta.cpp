#include "Ruta.h"

#include <iostream>
#include <ostream>

int Ruta::contorID = 0;

Ruta::Ruta(const std::string &nume, const std::vector<Statie*> &statii):
    idRuta(++ contorID),
    nume(nume),
    statii(statii) {}

RutaAutobuz::RutaAutobuz(const std::string &nume, const std::vector<Statie *> &statii):
    Ruta(nume, statii) {}

RutaTroleibuz::RutaTroleibuz(const std::string &nume, const std::vector<Statie *> &statii):
    Ruta(nume, statii) {}

RutaTramvai::RutaTramvai(const std::string &nume, const std::vector<Statie *> &statii):
    Ruta(nume, statii) {}

RutaMetrou::RutaMetrou(const std::string &nume, const std::vector<Statie *> &statii):
    Ruta(nume, statii) {}

void RutaAutobuz::afisareRuta() {
    std::cout << "Ruta " << idRuta << " (" << nume << "): ";
    for (const auto &statie: statii) {
        statie->afisareStatie();
    }
    std::cout << std::endl;
}

void RutaTroleibuz::afisareRuta() {
    std::cout << "Ruta " << idRuta << " (" << nume << "): ";
    for (const auto &statie: statii) {
        statie->afisareStatie();
    }
    std::cout << std::endl;
}

void RutaTramvai::afisareRuta() {
    std::cout << "Ruta " << idRuta << " (" << nume << "): ";
    for (const auto &statie: statii) {
        statie->afisareStatie();
    }
    std::cout << std::endl;
}

void RutaMetrou::afisareRuta() {
    std::cout << "Ruta " << idRuta << " (" << nume << "): ";
    for (const auto &statie: statii) {
        statie->afisareStatie();
    }
    std::cout << std::endl;
}