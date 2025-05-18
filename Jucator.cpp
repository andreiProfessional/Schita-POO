#include "Jucator.h"
#include <iostream>


int Jucator::contorID = 0;

Jucator::Jucator(const std::string &nume,
    Locatie *locatie, const std::vector<std::pair<Ruta*, int>> &statii,
    const int &balantaBani, const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie):
    idJucator(++ contorID), nume(nume),
    locatie(locatie), statii(statii),
    balantaBani(balantaBani), nivelViata(nivelViata), nivelEnergie(nivelEnergie), nivelNutritie(nivelNutritie) {}

bool Jucator::verificareId(const int &ID) {
    return (idJucator == ID);
}

void Jucator::afisareNivel(const std::string &mesajNivel, const std::string &simbolPozitiv, const std::string &simbolNegativ, const int &nivel) {
    std::cout << mesajNivel;
    std::cout << "[";
    int nivelAfisaj;
    if (nivel < 10) {
        nivelAfisaj = 1;
    }
    else {
        nivelAfisaj = nivel / 10;
    }
    for (int i = 0; i < nivelAfisaj; i++) {
        std::cout << simbolPozitiv;
        if (i != 9) {
            std::cout << "|";
        }
    }
    for (int i = nivelAfisaj; i < 10; i++) {
        std::cout << simbolNegativ;
        if (i != 9) {
            std::cout << "|";
        }
    }
    std::cout << "]" << std::endl;
}

void Jucator::afisareJucator() {
    for (int i = 0; i < 50; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::cout << "ID Jucator: " << idJucator << std::endl;
    std::cout << "Nume:       " << nume << std::endl;
    std::cout << "Locatie:    " << locatie->gasesteNumeLocatie() << std::endl;
    std::cout << "Bani:       " << balantaBani << " Lei" << std::endl;
    afisareNivel(std::string("Viata:      "), "❤️", "🖤", nivelViata);
    afisareNivel(std::string("Energie:    "), "🔋", "🪫", nivelEnergie);
    afisareNivel(std::string("Nutritie:   "), "🍗", "🦴", nivelNutritie);
    for (int i = 0; i < 50; i++) {
        std::cout << "*";
    }
}

void Jucator::afisareLocatie() {
    locatie->afisareLocatie();
}

void Jucator::afisareOptiuniLocatie() {
    locatie->afisareOptiuniLocatie();
}

Locatie* Jucator::gasireLocatie() {
    return locatie;
}

void Jucator::setareStatii(const std::vector<std::pair<Ruta*, int>> &statii) {
    this->statii = statii;
}

void Jucator::afisareStatii() {
    const int numarStatii = statii.size();
    for (int indice = 0; indice < numarStatii; indice ++) {
        std::cout << indice + 1 << ". ";
        statii[indice].first->afisareDetaliiRuta();
        statii[indice].first->afisareStatie(statii[indice].second);
        std::cout << std::endl;
    }
}


void Jucator::modificareBalantaBani(const int &diferentaBani) {
    balantaBani += diferentaBani;
}

void Jucator::modificareNivelViata(const int &diferentaViata) {
    nivelViata += diferentaViata;
    if (nivelViata > 100) {
        nivelViata = 100;
    }
    else if (nivelViata < 0) {
        nivelViata = 0;
    }
}

void Jucator::modificareNivelEnergie(const int &diferentaEnergie) {
    nivelEnergie += diferentaEnergie;
    if (nivelEnergie > 100) {
        nivelEnergie = 100;
    }
    else if (nivelEnergie < 0) {
        nivelEnergie = 0;
    }
}

void Jucator::modificareNivelNutritie(const int &diferentaNutritie) {
    nivelNutritie += diferentaNutritie;
    if (nivelNutritie > 100) {
        nivelNutritie = 100;
    }
    else if (nivelNutritie < 0) {
        nivelNutritie = 0;
    }
}

void Jucator::aplicareCoeficienti(const int &optiune) {
    this->modificareBalantaBani(locatie->diferentaBani(optiune));
    this->modificareNivelViata(locatie->diferentaViata(optiune));
    this->modificareNivelEnergie(locatie->diferentaEnergie(optiune));
    this->modificareNivelNutritie(locatie->diferentaNutritie(optiune));
}