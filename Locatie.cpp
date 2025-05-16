#include "Locatie.h"
#include "CuloriText.h"
#include <iostream>

int Locatie::contorID = 0;

Locatie::Locatie(const std::string &nume, Statie *statie):
    idLocatie(++ contorID),
    nume(nume),
    statie(statie) {}

LocatieResedinta::LocatieResedinta(const std::string &nume, Statie *statie,
        const int &plusEnergie):
        Locatie(nume, statie),
        plusEnergie(plusEnergie) {}

LocatieSport::LocatieSport(const std::string &nume, Statie *statie,
    const int &plusViata, const int &minusBani, const int &minusEnergie, const int &minusNutritie):
    Locatie(nume, statie),
    plusViata(plusViata),
    minusBani(minusBani),
    minusEnergie(minusEnergie),
    minusNutritie(minusNutritie) {}

LocatieMedicala::LocatieMedicala(const std::string &nume, Statie *statie,
        const int &plusViata, const int &minusBani):
        Locatie(nume, statie),
        plusViata(plusViata),
        minusBani(minusBani) {}

LocatieMunca::LocatieMunca(const std::string &nume, Statie *statie,
        const int &plusBani, const int &minusEnergie, const int &minusNutritie):
        Locatie(nume, statie),
        plusBani(plusBani),
        minusEnergie(minusEnergie),
        minusNutritie(minusNutritie) {}

LocatieHoreca::LocatieHoreca(const std::string &nume, Statie *statie,
        const int &plusNutritie, const int &minusBani):
    Locatie(nume, statie),
    plusNutritie(plusNutritie),
    minusBani(minusBani) {}

void LocatieResedinta::afisareLocatie() {
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "Locatie:  " << nume << std::endl;
    std::cout << "Tip:      " << "Resedinta" << std::endl;
    std::cout << "Avantaje: " << VERDE << "Energie" << RESETARE << std::endl;
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void LocatieSport::afisareLocatie() {
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "Locatie:     " << nume << std::endl;
    std::cout << "Tip:         " << "Sport" << std::endl;
    std::cout << "Avantaje:    " << VERDE << "Viata" << RESETARE << std::endl;
    std::cout << "Dezavantaje: " << ROSU << "Bani" << RESETARE << " | "
                                 << ROSU << "Energie" << RESETARE << " | "
                                 << ROSU << "Nutritie" << RESETARE << std::endl;
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void LocatieMedicala::afisareLocatie() {
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "Locatie:     " << nume << std::endl;
    std::cout << "Tip:         " << "Medicala" << std::endl;
    std::cout << "Avantaje:    " << VERDE << "Viata" << RESETARE << std::endl;
    std::cout << "Dezavantaje: " << ROSU << "Bani" << RESETARE << std::endl;
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void LocatieMunca::afisareLocatie() {
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "Locatie:     " << nume << std::endl;
    std::cout << "Tip:         " << "Munca" << std::endl;
    std::cout << "Avantaje:    " << VERDE << "Bani" << RESETARE << std::endl;
    std::cout << "Dezavantaje: " << ROSU << "Energie" << RESETARE << " | "
                                 << ROSU << "Nutritie" << RESETARE << std::endl;
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void LocatieHoreca::afisareLocatie() {
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "Locatie:     " << nume << std::endl;
    std::cout << "Tip:         " << "Horeca" << std::endl;
    std::cout << "Avantaje:    " << VERDE << "Nutritie" << RESETARE << std::endl;
    std::cout << "Dezavantaje: " << ROSU << "Bani" << RESETARE << std::endl;
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void LocatieResedinta::afisareOptiuniLocatie() {
    std::cout << "1. Pui de somn "
              << "(" << VERDE << "+" << plusEnergie << " Energie" << RESETARE << ")" << std::endl;
    std::cout << "2. Somn de frumusete "
              << "(" << VERDE << "+" << 2 * plusEnergie << " Energie" << RESETARE << ")" << std::endl;
    std::cout << "3. Somn de noapte "
              << "(" << VERDE << "+" << 4 * plusEnergie << " Energie" << RESETARE << ")" << std::endl;
    std::cout << "0. Du-te afara" << std::endl;
}

void LocatieSport::afisareOptiuniLocatie() {
    std::cout << "1. Antrenament de tonifiere "
              << "(" << VERDE << "+" << plusViata << " Viata" << RESETARE
              << " | " << ROSU << minusBani << " Lei" << RESETARE
              << " | " << ROSU << minusEnergie << " Energie" << RESETARE
              << " | " << ROSU << minusNutritie << " Nutritie" << RESETARE << ")" << std::endl;
    std::cout << "2. Antrenament mediu "
              << "(" << VERDE << "+" << 2 * plusViata << " Viata" << RESETARE
              << " | " << ROSU << 2 * minusBani << " Lei" << RESETARE
              << " | " << ROSU << 2 * minusEnergie << " Energie" << RESETARE
              << " | " << ROSU << 3 * minusNutritie << " Nutritie" << RESETARE << ")" << std::endl;
    std::cout << "3. Antrenamentul campionilor "
              << "(" << VERDE << "+" << 4 * plusViata << " Viata" << RESETARE
              << " | " << ROSU << 3 * minusBani << " Lei" << RESETARE
              << " | " << ROSU << 3 * minusEnergie << " Energie" << RESETARE
              << " | " << ROSU << 4 * minusNutritie << " Nutritie" << RESETARE << ")" << std::endl;
    std::cout << "0. Du-te afara" << std::endl;
}

void LocatieMedicala::afisareOptiuniLocatie() {
    std::cout << "1. Consultatie "
              << "(" << VERDE << "+" << plusViata << " Viata" << RESETARE
              << " | " << ROSU << minusBani << " Lei" << RESETARE << ")" << std::endl;
    std::cout << "2. Tratament periodic "
              << "(" << VERDE << "+" << 3 * plusViata << " Viata" << RESETARE
              << " | " << ROSU << 2 * minusBani << " Lei" << RESETARE << ")" << std::endl;
    std::cout << "3. Operatie "
              << "(" << VERDE << "+" << 6 * plusViata << " Viata" << RESETARE
              << " | " << ROSU << 5 * minusBani << " Lei" << RESETARE << ")" << std::endl;
    std::cout << "0. Du-te afara" << std::endl;
}

void LocatieMunca::afisareOptiuniLocatie() {
    std::cout << "1. Zi de munca ";
    std::cout << "(+" << plusBani << " Lei) ";
    std::cout << "(" << minusEnergie << " Energie) ";
    std::cout << "(" << minusNutritie << " Nutritie) ";
    std::cout << std::endl;
    std::cout << "0. Du-te afara" << std::endl;
}

void LocatieHoreca::afisareOptiuniLocatie() {
    std::cout << "1. Mananca portie normala ";
    std::cout << "(+" << plusNutritie << " Nutritie) ";
    std::cout << "(" << minusBani << " Lei) ";
    std::cout << std::endl;
    std::cout << "0. Du-te afara" << std::endl;
}

bool Locatie::verificareId(const int &idLocatie) {
    return (this->idLocatie == idLocatie);
}

bool Locatie::verificareNume(const std::string &nume) {
    return (this->nume == nume);
}

Statie* Locatie::gasireStatie() {
    return this->statie;
}

std::string Locatie::gasesteNumeLocatie() {
    return nume;
}