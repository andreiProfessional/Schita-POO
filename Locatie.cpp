#include "Locatie.h"
#include <iostream>

int Locatie::contorID = 0;

Locatie::Locatie(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA):
    idLocatie(++ contorID),
    nume(NUME),
    statieApropiata(STATIE_APROPIATA),
    coeficientOdihna(COEFICIENT_ODIHNA),
    coeficientDistractie(COEFICIENT_DISTRACTIE),
    coeficientViata(COEFICIENT_VIATA) {}

LocatieResedinta::LocatieResedinta(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA):
    Locatie(NUME, STATIE_APROPIATA, COEFICIENT_ODIHNA, COEFICIENT_DISTRACTIE, COEFICIENT_VIATA) {}

LocatieEducatie::LocatieEducatie(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA):
    Locatie(NUME, STATIE_APROPIATA, COEFICIENT_ODIHNA, COEFICIENT_DISTRACTIE, COEFICIENT_VIATA) {}

LocatieMunca::LocatieMunca(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA):
    Locatie(NUME, STATIE_APROPIATA, COEFICIENT_ODIHNA, COEFICIENT_DISTRACTIE, COEFICIENT_VIATA) {}

LocatieRelaxare::LocatieRelaxare(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA):
    Locatie(NUME, STATIE_APROPIATA, COEFICIENT_ODIHNA, COEFICIENT_DISTRACTIE, COEFICIENT_VIATA) {}

LocatieInstitutie::LocatieInstitutie(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA):
    Locatie(NUME, STATIE_APROPIATA, COEFICIENT_ODIHNA, COEFICIENT_DISTRACTIE, COEFICIENT_VIATA) {}

void LocatieResedinta::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": Resedinta " << nume << " - Statia " << statieApropiata << " => " << coeficientOdihna << " | " << coeficientDistractie << " | " << coeficientViata << std::endl;
}

void LocatieEducatie::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": Educatie " << nume << " - Statia " << statieApropiata << " => " << coeficientOdihna << " | " << coeficientDistractie << " | " << coeficientViata << std::endl;
}

void LocatieMunca::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": Munca " << nume << " - Statia " << statieApropiata << " => " << coeficientOdihna << " | " << coeficientDistractie << " | " << coeficientViata << std::endl;
}

void LocatieRelaxare::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": Relaxarea " << nume << " - Statia " << statieApropiata << " => " << coeficientOdihna << " | " << coeficientDistractie << " | " << coeficientViata << std::endl;
}

void LocatieInstitutie::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": Institutia " << nume << " - Statia " << statieApropiata << " => " << coeficientOdihna << " | " << coeficientDistractie << " | " << coeficientViata << std::endl;
}