#include "Inventar.h"
#include "Activitate.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

Inventar::Inventar() {std::cout << "Am creat Inventarul!" << std::endl << std::endl;}

Inventar::~Inventar() {
    for (const auto &statie: this->statii) {
        delete statie;
    }
    std::cout << std::endl << "Am distrus Inventarul!" << std::endl << std::endl;
}

void Inventar::adaugareStatie(Statie *statie) {
    this->statii.push_back(statie);
}


void Inventar::adaugareMuchieStatii(Statie *statie1, Statie *statie2, const std::string &ruta) {
    this->listeAdiacentaStatii[statie1].push_back(statie2);
    this->listeAdiacentaStatii[statie2].push_back(statie1);
    statie1->adaugareRuta(ruta);
    statie2->adaugareRuta(ruta);
}

void Inventar::adaugareLocatie(Locatie *locatie) {
    this->locatii.push_back(locatie);
}

void Inventar::adaugareJucator(Jucator *jucator) {
    this->jucatori.push_back(jucator);
}

void Inventar::populareInventar() {
    std::ifstream in("tastatura.txt");
    int numarStatii;
    in >> numarStatii;
    in.get();
    for (int index = 0; index < numarStatii; index ++) {
        Statie *statie = new Statie("", {});
        in >> *statie;
        this->adaugareStatie(statie);
    }
    // int numarMuchiiStatii;
    // in >> numarMuchiiStatii;

    in.close();
}

void Inventar::afisareStatii() const {
    for (const auto &statie: this->statii) {
        std::cout << *statie << std::endl;
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
    std::ranges::sort(this->jucatori, [](const Jucator* jucator1, const Jucator* jucator2) {
            return (*jucator1 > *jucator2);
        });
}
