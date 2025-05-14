#include "Locatie.h"
#include <iostream>

int Locatie::contorID = 0;

Locatie::Locatie(const std::string &TIP, const std::string &NUME, const std::string &STATIE):
    idLocatie(++ contorID),
    tip(TIP),
    nume(NUME),
    statie(STATIE) {}

LocatieResedinta::LocatieResedinta(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &PLUS_ENERGIE, const int &PLUS_NUTRITIE, const int &MINUS_INTELIGENTA):
        Locatie(TIP, NUME, STATIE),
        plusEnergie(PLUS_ENERGIE),
        plusNutritie(PLUS_NUTRITIE),
        minusInteligenta(MINUS_INTELIGENTA) {}

LocatieMedicala::LocatieMedicala(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &PLUS_VIATA, const int &PLUS_ENERGIE, const int &MINUS_DISTRACTIE, const int &MINUS_BANI):
        Locatie(TIP, NUME, STATIE),
        plusViata(PLUS_VIATA),
        plusEnergie(PLUS_ENERGIE),
        minusDistractie(MINUS_DISTRACTIE),
        minusBani(MINUS_BANI) {}

LocatieEducatie::LocatieEducatie(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &PLUS_INTELIGENTA, const int &MINUS_ENERGIE, const int &MINUS_NUTRITIE, const int &MINUS_DISTRACTIE):
        Locatie(TIP, NUME, STATIE),
        plusInteligenta(PLUS_INTELIGENTA),
        minusEnergie(MINUS_ENERGIE),
        minusNutritie(MINUS_NUTRITIE),
        minusDistractie(MINUS_DISTRACTIE) {}

LocatieMunca::LocatieMunca(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &PLUS_BANI, const int &MINUS_ENERGIE, const int &MINUS_NUTRITIE, const int &MINUS_DISTRACTIE):
        Locatie(TIP, NUME, STATIE),
        plusBani(PLUS_BANI),
        minusEnergie(MINUS_ENERGIE),
        minusNutritie(MINUS_NUTRITIE),
        minusDistractie(MINUS_DISTRACTIE)
        {}

LocatieHoreca::LocatieHoreca(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &PLUS_NUTRITIE, const int &PLUS_DISTRACTIE, const int &MINUS_BANI):
    Locatie(TIP, NUME, STATIE),
    plusNutritie(PLUS_NUTRITIE),
    plusDistractie(PLUS_DISTRACTIE),
    minusBani(MINUS_BANI) {}

LocatieRelaxare::LocatieRelaxare(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &PLUS_ENERGIE, const int &PLUS_DISTRACTIE, const int &MINUS_BANI):
    Locatie(TIP, NUME, STATIE),
    plusEnergie(PLUS_ENERGIE),
    plusDistractie(PLUS_DISTRACTIE),
    minusBani(MINUS_BANI) {}

void LocatieResedinta::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": (Resedinta) " << nume << " - Statia " << statie;
    std::cout << " => " << plusEnergie << " | " << plusNutritie << " | " << minusInteligenta << std::endl;
}

void LocatieMedicala::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": (Medicala) " << nume << " - Statia " << statie ;
    std::cout << " => " << plusViata << " | " << plusEnergie << " | " << minusDistractie << " | " << minusBani << std::endl;
}

void LocatieEducatie::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": (Educatie) " << nume << " - Statia " << statie << " => ";
    std::cout << plusInteligenta << " | " << minusEnergie << " | " << minusNutritie << " | " << minusDistractie << std::endl;
}

void LocatieMunca::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": (Munca) " << nume << " - Statia " << statie << " => ";
    std::cout << plusBani << " | " << minusEnergie << " | " << minusNutritie << " | " << minusDistractie << std::endl;
}

void LocatieHoreca::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": (Horeca) " << nume << " - Statia " << statie << " => ";
    std::cout << plusNutritie << " | " << plusDistractie << " | " << minusBani << std::endl;
}

void LocatieRelaxare::afisareLocatie() {
    std::cout << "Locatia " << idLocatie << ": (Relaxare) " << nume << " - Statia " << statie << " => ";
    std::cout << plusEnergie << " | " << plusDistractie << " | " << minusBani << std::endl;
}

void LocatieResedinta::aplicaCoeficienti(Jucator *jucator) {
    jucator->modificareNivelEnergie(plusEnergie);
    jucator->modificareNivelNutritie(plusNutritie);
    jucator->modificareNivelInteligenta(minusInteligenta);
}

void LocatieMedicala::aplicaCoeficienti(Jucator *jucator) {
    jucator->modificareNivelViata(plusViata);
    jucator->modificareNivelEnergie(plusEnergie);
    jucator->modificareNivelDistractie(minusDistractie);
    jucator->modificareBalantaBani(minusBani);
}

void LocatieEducatie::aplicaCoeficienti(Jucator *jucator) {
    jucator->modificareNivelInteligenta(plusInteligenta);
    jucator->modificareNivelEnergie(minusEnergie);
    jucator->modificareNivelNutritie(minusNutritie);
    jucator->modificareNivelDistractie(minusDistractie);
}

void LocatieMunca::aplicaCoeficienti(Jucator *jucator) {
    jucator->modificareBalantaCalatorii(plusBani);
    jucator->modificareNivelEnergie(minusEnergie);
    jucator->modificareNivelNutritie(minusNutritie);
    jucator->modificareNivelDistractie(minusDistractie);
}

void LocatieHoreca::aplicaCoeficienti(Jucator *jucator) {
    jucator->modificareNivelNutritie(plusNutritie);
    jucator->modificareNivelDistractie(plusDistractie);
    jucator->modificareBalantaCalatorii(minusBani);
}

void LocatieRelaxare::aplicaCoeficienti(Jucator *jucator) {
    jucator->modificareNivelEnergie(plusEnergie);
    jucator->modificareNivelDistractie(plusDistractie);
    jucator->modificareBalantaCalatorii(minusBani);
}

bool Locatie::verificareId(const int &ID) {
    return (idLocatie == ID);
}