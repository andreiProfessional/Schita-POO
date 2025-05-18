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


void RutaAutobuz::afisareDetaliiRuta() {
    std::cout << "Autobuz " << nume << ": ";
}

void RutaTroleibuz::afisareDetaliiRuta() {
    std::cout << "Troleibuz " << nume << ": ";
}

void RutaTramvai::afisareDetaliiRuta() {
    std::cout << "Tramvai " << nume << ": ";
}

void RutaMetrou::afisareDetaliiRuta() {
    std::cout << "Metrou " << nume << ": ";
}


int RutaAutobuz::gasirePret(const int &balantaBani) {
    if (balantaBani < 100) {
        return -5;
    }
    if (balantaBani > 1000) {
        return -1 * balantaBani * 5 / 100;
    }
    return -1 * balantaBani * 3 / 100;
}

int RutaTroleibuz::gasirePret(const int &balantaBani) {
    if (balantaBani < 150) {
        return -4;
    }
    if (balantaBani > 750) {
        return -1 * balantaBani * 4 / 100;
    }
    return -1 * balantaBani * 2 / 100;
}

int RutaTramvai::gasirePret(const int &balantaBani) {
    if (balantaBani < 200) {
        return -3;
    }
    if (balantaBani > 500) {
        return -1 * balantaBani * 3 / 100;
    }
    return -1 * balantaBani * 2 / 100;
}

int RutaMetrou::gasirePret(const int &balantaBani) {
    if (balantaBani < 500) {
        return -10;
    }
    if (balantaBani > 2500) {
        return -1 * balantaBani * 8 / 100;
    }
    return -1 * balantaBani * 5 / 100;
}


std::pair<Ruta*, int> Ruta::gasireStatie(const std::string &numeStatie) {
    const int numarStatii = statii.size();
    for (int indice = 0; indice < numarStatii; indice ++) {
        if (statii[indice]->verificareNume(numeStatie)) {
            return std::make_pair(this, indice);
        }
    }
    return std::make_pair(nullptr, -1);
}

void Ruta::afisareStatie(const int &pozitie) {
    statii[pozitie]->afisareStatie();
}