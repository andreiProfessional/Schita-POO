#include "Inventar.h"
#include "Activitate.h"
#include <iostream>
#include <vector>
#include <unordered_map>

Inventar::Inventar() {
    jucatori = std::vector<Jucator*>();
    locatii = std::vector<Locatie*>();
    statii = std::unordered_map<Statie*, std::vector<Statie*>>();
    istoricActivitati = std::vector<Activitate*>();
}

Inventar::~Inventar(){std::cout << std::endl << "Gata joaca!";}

void Inventar::adaugareMuchieStatii(Statie *statie1, Statie *statie2, const std::string &ruta) {
    statii[statie1].push_back(statie2);
    statii[statie2].push_back(statie1);
    statie1->adaugareRuta(ruta);
    statie2->adaugareRuta(ruta);
}

void Inventar::adaugareLocatie(Locatie *locatie) {
    locatii.push_back(locatie);
}

void Inventar::adaugareJucator(Jucator *jucator) {
    jucatori.push_back(jucator);
}

void Inventar::afisareStatii() const {
    for (const auto &statie: this->statii) {
        statie.first->afisare();
    }
}

void Inventar::afisareLocatii() const {
    for (const auto &locatie: this->locatii) {
        locatie->afisare();
    }
}

void Inventar::afisareJucatori() const {
    for (const auto &jucator: this->jucatori) {
        jucator->afisare();
    }
}
