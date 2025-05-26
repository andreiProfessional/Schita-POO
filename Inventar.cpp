#include "Inventar.h"
#include "Activitate.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ranges>

Inventar::Inventar() {std::cout << "Am creat Inventarul!";}

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
    for (const auto &key: this->statii | std::views::keys) {
        std::cout << *key;
    }
}

void Inventar::afisareLocatii() const {
    for (const Locatie* const locatie: this->locatii) {
        std::cout << *locatie;
    }
}

void Inventar::afisareJucatori() const {
    for (const Jucator* const jucator: this->jucatori) {
        std::cout << *jucator;
    }
}

void Inventar::sortareJucatori() {
    std::ranges::sort(jucatori, [](const Jucator* jucator1, const Jucator* jucator2) {
            return (*jucator1 > *jucator2);
        });
}
