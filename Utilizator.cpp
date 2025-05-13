#include "Utilizator.h"
#include <iostream>


int Utilizator::contorID = 0;

Utilizator::Utilizator(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &NIVEL_VIATA, const int &NIVEL_ENERGIE, const int &NIVEL_NUTRITIE, const int &NIVEL_INTELIGENTA, const int &NIVEL_DISTRACTIE):
    idUtilizator(++ contorID),
    tip(TIP),
    nume(NUME),
    statie(STATIE),
    nivelViata(NIVEL_VIATA),
    nivelEnergie(NIVEL_ENERGIE),
    nivelNutritie(NIVEL_NUTRITIE),
    nivelInteligenta(NIVEL_INTELIGENTA),
    nivelDistractie(NIVEL_DISTRACTIE) {}

UtilizatorAdmin::UtilizatorAdmin(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &NIVEL_VIATA, const int &NIVEL_ENERGIE, const int &NIVEL_NUTRITIE, const int &NIVEL_INTELIGENTA, const int &NIVEL_DISTRACTIE):
    Utilizator(TIP, NUME, STATIE, NIVEL_VIATA, NIVEL_ENERGIE, NIVEL_NUTRITIE, NIVEL_INTELIGENTA, NIVEL_DISTRACTIE) {}

UtilizatorStandard::UtilizatorStandard(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
    const int &NIVEL_VIATA, const int &NIVEL_ENERGIE, const int &NIVEL_NUTRITIE, const int &NIVEL_INTELIGENTA, const int &NIVEL_DISTRACTIE,
    const int &BALANTA_BANI, const int &BALANTA_CALATORII):
    Utilizator(TIP, NUME, STATIE, NIVEL_VIATA, NIVEL_ENERGIE, NIVEL_NUTRITIE, NIVEL_INTELIGENTA, NIVEL_DISTRACTIE),
    balantaBani(BALANTA_BANI),
    balantaCalatorii(BALANTA_CALATORII) {}

void Utilizator::afisareNivel(const std::string &mesajNivel, const int &nivel) {
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

void UtilizatorAdmin::afisareUtilizator() {
    std::cout << "Utilizatorul " << idUtilizator << ": " << nume << " | " << tip << std::endl;
    std::cout << "Bani: ∞" << std::endl;
    std::cout << "Calatorii: ∞" << std::endl;
    afisareNivel(std::string("Viata:       "), nivelViata);
    afisareNivel(std::string("Energie:     "), nivelEnergie);
    afisareNivel(std::string("Nutritie:    "), nivelNutritie);
    afisareNivel(std::string("Inteligenta: "), nivelInteligenta);
    afisareNivel(std::string("Distractie:  "), nivelDistractie);
}

void UtilizatorStandard::afisareUtilizator() {
    std::cout << "Utilizatorul " << idUtilizator << ": " << nume << " | " << tip << std::endl;
    std::cout << "Bani: " << balantaBani << " Lei" << std::endl;
    std::cout << "Calatorii: " << balantaCalatorii << " Lei" << std::endl;
    afisareNivel(std::string("Viata:       "), nivelViata);
    afisareNivel(std::string("Energie:     "), nivelEnergie);
    afisareNivel(std::string("Nutritie:    "), nivelNutritie);
    afisareNivel(std::string("Inteligenta: "), nivelInteligenta);
    afisareNivel(std::string("Distractie:  "), nivelDistractie);
}
/*
std::ostream& operator<<(std::ostream& out, Utilizator &utilizator) {
    out << "Utilizatorul " << utilizator.idUtilizator << ": " << utilizator.nume << " (NEFOR)" << std::endl;
    //out << "Bani: " << utilizator.balantaBani << " Lei" << std::endl;
    //out << "Calatorii: " << utilizator.balantaCalatorii << " Lei" << std::endl;
    utilizator->afisareNivel(std::string("Nivel viata:      "), nivelViata);
    utilizator.afisareNivel(std::string("Nivel distractie: "), utilizator.nivelDistractie);
    utilizator.afisareNivel(std::string("Nivel bunastare:  "), utilizator.nivelViata);
    return out;
}
*/

void Utilizator::modificareNivelViata(const int &diferentaViata) {
    nivelViata += diferentaViata;
    if (nivelViata > 100) {
        nivelViata = 100;
    }
    else if (nivelViata < 0) {
        nivelViata = 0;
    }
}

void Utilizator::modificareNivelEnergie(const int &diferentaEnergie) {
    nivelEnergie += diferentaEnergie;
    if (nivelEnergie > 100) {
        nivelEnergie = 100;
    }
    else if (nivelEnergie < 0) {
        nivelEnergie = 0;
    }
}

void Utilizator::modificareNivelNutritie(const int &diferentaNutritie) {
    nivelNutritie += diferentaNutritie;
    if (nivelNutritie > 100) {
        nivelNutritie = 100;
    }
    else if (nivelNutritie < 0) {
        nivelNutritie = 0;
    }
}

void Utilizator::modificareNivelInteligenta(const int &diferentaInteligenta) {
    nivelInteligenta += diferentaInteligenta;
    if (nivelInteligenta > 100) {
        nivelInteligenta = 100;
    }
    else if (nivelInteligenta < 0) {
        nivelInteligenta = 0;
    }
}

void Utilizator::modificareNivelDistractie(const int &diferentaDistractie) {
    nivelDistractie += diferentaDistractie;
    if (nivelDistractie > 100) {
        nivelDistractie = 100;
    }
    else if (nivelDistractie < 0) {
        nivelDistractie = 0;
    }
}

void UtilizatorStandard::modificareBalantaBani(const int &diferentaBani) {
    balantaBani += diferentaBani;
}

void UtilizatorStandard::modificareBalantaCalatorii(const int &diferentaCalatorii) {
    balantaCalatorii += diferentaCalatorii;
}

bool Utilizator::verificareId(const int &ID) {
    return (idUtilizator == ID);
}