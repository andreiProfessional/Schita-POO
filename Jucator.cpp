#include "Jucator.h"
#include <iostream>


int Jucator::contorID = 0;

Jucator::Jucator(const std::string &tip, const std::string &nume, const std::string &statie,
    const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie):
    idJucator(++ contorID),
    tip(tip),
    nume(nume),
    statie(statie),
    nivelViata(nivelViata),
    nivelEnergie(nivelEnergie),
    nivelNutritie(nivelNutritie),
    nivelInteligenta(nivelInteligenta),
    nivelDistractie(nivelDistractie) {}

JucatorAdmin::JucatorAdmin(const std::string &tip, const std::string &nume, const std::string &statie,
    const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie):
    Jucator(tip, nume, statie, nivelViata, nivelEnergie, nivelNutritie, nivelInteligenta, nivelDistractie) {}

JucatorStandard::JucatorStandard(const std::string &tip, const std::string &nume, const std::string &statie,
    const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie,
    const int &balantaBani, const int &balantaCalatorii):
    Jucator(tip, nume, statie, nivelViata, nivelEnergie, nivelNutritie, nivelInteligenta, nivelDistractie),
    balantaBani(balantaBani),
    balantaCalatorii(balantaCalatorii) {}

void Jucator::afisareNivel(const std::string &mesajNivel, const int &nivel) {
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
        std::cout << "█";
        if (i != 9) {
            std::cout << "|";
        }
    }
    for (int i = nivelAfisaj; i < 10; i++) {
        std::cout << "░";
        if (i != 9) {
            std::cout << "|";
        }
    }
    std::cout << "]" << std::endl;
}

void JucatorAdmin::afisareJucator() {
    std::cout << "Jucatorul " << idJucator << ": " << nume << " | " << tip << std::endl;
    std::cout << "Bani: ∞" << std::endl;
    std::cout << "Calatorii: ∞" << std::endl;
    afisareNivel(std::string("Viata:       "), nivelViata);
    afisareNivel(std::string("Energie:     "), nivelEnergie);
    afisareNivel(std::string("Nutritie:    "), nivelNutritie);
    afisareNivel(std::string("Inteligenta: "), nivelInteligenta);
    afisareNivel(std::string("Distractie:  "), nivelDistractie);
}

void JucatorStandard::afisareJucator() {
    std::cout << "Jucatorul " << idJucator << ": " << nume << " | " << tip << std::endl;
    std::cout << "Bani: " << balantaBani << " Lei" << std::endl;
    std::cout << "Calatorii: " << balantaCalatorii << " Calatorii" << std::endl;
    afisareNivel(std::string("Viata:       "), nivelViata);
    afisareNivel(std::string("Energie:     "), nivelEnergie);
    afisareNivel(std::string("Nutritie:    "), nivelNutritie);
    afisareNivel(std::string("Inteligenta: "), nivelInteligenta);
    afisareNivel(std::string("Distractie:  "), nivelDistractie);
}
/*
std::ostream& operator<<(std::ostream& out, Jucator &jucator) {
    out << "Jucatorul " << jucator.idJucator << ": " << jucator.nume << " (NEFOR)" << std::endl;
    //out << "Bani: " << jucator.balantaBani << " Lei" << std::endl;
    //out << "Calatorii: " << jucator.balantaCalatorii << " Calatorii" << std::endl;
    jucator->afisareNivel(std::string("Nivel viata:      "), nivelViata);
    jucator.afisareNivel(std::string("Nivel distractie: "), jucator.nivelDistractie);
    jucator.afisareNivel(std::string("Nivel bunastare:  "), jucator.nivelViata);
    return out;
}
*/

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

void Jucator::modificareNivelInteligenta(const int &diferentaInteligenta) {
    nivelInteligenta += diferentaInteligenta;
    if (nivelInteligenta > 100) {
        nivelInteligenta = 100;
    }
    else if (nivelInteligenta < 0) {
        nivelInteligenta = 0;
    }
}

void Jucator::modificareNivelDistractie(const int &diferentaDistractie) {
    nivelDistractie += diferentaDistractie;
    if (nivelDistractie > 100) {
        nivelDistractie = 100;
    }
    else if (nivelDistractie < 0) {
        nivelDistractie = 0;
    }
}

void JucatorStandard::modificareBalantaBani(const int &diferentaBani) {
    balantaBani += diferentaBani;
}

void JucatorStandard::modificareBalantaCalatorii(const int &diferentaCalatorii) {
    balantaCalatorii += diferentaCalatorii;
}

bool Jucator::verificareId(const int &ID) {
    return (idJucator == ID);
}