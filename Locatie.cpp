#include "Locatie.h"
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
    std::cout << "Locatie: " << nume << std::endl;
    std::cout << "Tip:     " << "Resedinta" << std::endl;
    std::cout << "Energie: +" << plusEnergie << std::endl;
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
    std::cout << "Locatie:  " << nume << std::endl;
    std::cout << "Tip:      " << "Sport" << std::endl;
    std::cout << "Viata:    +" << plusViata << std::endl;
    std::cout << "Bani:     " << minusBani << std::endl;
    std::cout << "Energie:  " << minusEnergie << std::endl;
    std::cout << "Nutritie: " << minusNutritie << std::endl;
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
    std::cout << "Locatie: " << nume << std::endl;
    std::cout << "Tip:     " << "Medicala" << std::endl;
    std::cout << "Viata:   +" << plusViata << std::endl;
    std::cout << "Bani:    " << minusBani << std::endl;
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
    std::cout << "Locatie:  " << nume << std::endl;
    std::cout << "Tip:      " << "Munca" << std::endl;
    std::cout << "Bani:     +" << plusBani << std::endl;
    std::cout << "Energie:  " << minusEnergie << std::endl;
    std::cout << "Nutritie: " << minusNutritie << std::endl;
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
    std::cout << "Locatie:  " << nume << std::endl;
    std::cout << "Tip:      " << "Horeca" << std::endl;
    std::cout << "Nutritie: +" << plusNutritie << std::endl;
    std::cout << "Bani:     " << minusBani << std::endl;
    for (int i = 0; i < 50; i ++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void LocatieResedinta::afisareOptiuniLocatie() {
    std::cout << "1. Dormi ( +++ Energie +++ )" << std::endl;
    std::cout << "2. Du-te afara" << std::endl;
}

void LocatieSport::afisareOptiuniLocatie() {
    std::cout << "OPTIUNI LOCATIE SPORT" << std::endl;
}

void LocatieMedicala::afisareOptiuniLocatie() {
    std::cout << "OPTIUNI LOCATIE MEDICALA" << std::endl;
}

void LocatieMunca::afisareOptiuniLocatie() {
    std::cout << "OPTIUNI LOCATIE MUNCA" << std::endl;
}

void LocatieHoreca::afisareOptiuniLocatie() {
    std::cout << "OPTIUNI LOCATIE HORECA" << std::endl;
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