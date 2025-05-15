#include "Locatie.h"
#include <iostream>

int Locatie::contorID = 0;

Locatie::Locatie(const std::string &tip, const std::string &nume, Statie *statie):
    idLocatie(++ contorID),
    tip(tip),
    nume(nume),
    statie(statie) {}

LocatieResedinta::LocatieResedinta(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusEnergie):
        Locatie(tip, nume, statie),
        plusEnergie(plusEnergie) {}

LocatieSport::LocatieSport(const std::string &tip, const std::string &nume, Statie *statie,
    const int &plusViata, const int &minusBani, const int &minusEnergie, const int &minusNutritie):
    Locatie(tip, nume, statie),
    plusViata(plusViata),
    minusBani(minusBani),
    minusEnergie(minusEnergie),
    minusNutritie(minusNutritie) {}

LocatieMedicala::LocatieMedicala(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusViata, const int &minusBani):
        Locatie(tip, nume, statie),
        plusViata(plusViata),
        minusBani(minusBani) {}

LocatieMunca::LocatieMunca(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusBani, const int &minusEnergie, const int &minusNutritie):
        Locatie(tip, nume, statie),
        plusBani(plusBani),
        minusEnergie(minusEnergie),
        minusNutritie(minusNutritie) {}

LocatieHoreca::LocatieHoreca(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusNutritie, const int &minusBani):
    Locatie(tip, nume, statie),
    plusNutritie(plusNutritie),
    minusBani(minusBani) {}

void LocatieResedinta::afisareLocatie() {
    std::cout << "Locatia: " << nume << " (Resedinta)" << std::endl;
}

void LocatieSport::afisareLocatie() {
    std::cout << "Locatia: " << nume << " (Sport)" << std::endl;
}

void LocatieMedicala::afisareLocatie() {
    std::cout << "Locatia: " << nume << " (Medical)" << std::endl;
}

void LocatieMunca::afisareLocatie() {
    std::cout << "Locatia: " << nume << " (Munca)" << std::endl;
}

void LocatieHoreca::afisareLocatie() {
    std::cout << "Locatia: " << nume << " (Horeca)" << std::endl;
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