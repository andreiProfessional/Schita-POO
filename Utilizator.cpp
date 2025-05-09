#include "Utilizator.h"
#include <iostream>


int Utilizator::contorID = 0;

Utilizator::Utilizator(const std::string &NUME):
    idUtilizator(++ contorID),
    nume(NUME) {}

UtilizatorAdmin::UtilizatorAdmin(const std::string &NUME):
    Utilizator(NUME),
    NIVEL_ODIHNA(49),
    NIVEL_DISTRACTIE(50),
    NIVEL_VIATA(60) {}

UtilizatorStandard::UtilizatorStandard(const std::string &NUME):
    Utilizator(NUME),
    BALANTA_BANI(100),
    BALANTA_CALATORII(2),
    NIVEL_ODIHNA(90),
    NIVEL_DISTRACTIE(85),
    NIVEL_VIATA(80) {}

void UtilizatorAdmin::initializareUtilizator() {
    nivelOdihna = NIVEL_ODIHNA;
    nivelDistractie = NIVEL_DISTRACTIE;
    nivelViata = NIVEL_VIATA;
}

void UtilizatorStandard::initializareUtilizator() {
    balantaBani = BALANTA_BANI;
    balantaCalatorii = BALANTA_CALATORII;
    nivelOdihna = NIVEL_ODIHNA;
    nivelDistractie = NIVEL_DISTRACTIE;
    nivelViata = NIVEL_VIATA;
}

void Utilizator::afisareNivel(const std::string &mesajNivel, int nivel) {
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
    std::cout << "Utilizatorul " << idUtilizator << ": " << nume << " (ADMIN)" << std::endl;
    std::cout << "Bani: ∞" << std::endl;
    std::cout << "Calatorii: ∞" << std::endl;
    afisareNivel(std::string("Nivel odihna:     "), nivelOdihna);
    afisareNivel(std::string("Nivel distractie: "), nivelDistractie);
    afisareNivel(std::string("Nivel bunastare:  "), nivelViata);
}

void UtilizatorStandard::afisareUtilizator() {
    std::cout << "Utilizatorul " << idUtilizator << ": " << nume << " (NEFOR)" << std::endl;
    std::cout << "Bani: " << balantaBani << " Lei" << std::endl;
    std::cout << "Calatorii: " << balantaCalatorii << " Lei" << std::endl;
    afisareNivel(std::string("Nivel odihna:     "), nivelOdihna);
    afisareNivel(std::string("Nivel distractie: "), nivelDistractie);
    afisareNivel(std::string("Nivel bunastare:  "), nivelViata);
}

/*std::ostream& operator<<(std::ostream& out, const Utilizator& utilizator) {
    out << "Utilizatorul " << utilizator.idUtilizator << ": " << utilizator.nume << " (NEFOR)" << std::endl;
    out << "Bani: " << utilizator.balantaBani << " Lei" << std::endl;
    out << "Calatorii: " << utilizator.balantaCalatorii << " Lei" << std::endl;
    utilizator.afisareNivel(std::string("Nivel odihna:     "), utilizator.nivelOdihna);
    utilizator.afisareNivel(std::string("Nivel distractie: "), utilizator.nivelDistractie);
    utilizator.afisareNivel(std::string("Nivel bunastare:  "), utilizator.nivelViata);
    return out;
}*/

void UtilizatorStandard::modificareBalantaBani(int diferentaBani) {
    balantaBani += diferentaBani;
}

void UtilizatorStandard::modificareBalantaCalatorii(int diferentaCalatorii) {
    balantaCalatorii += diferentaCalatorii;
}

void Utilizator::modificareNivelOdihna(int diferentaOdihna) {
    nivelOdihna += diferentaOdihna;
}

void Utilizator::modificareNivelDistractie(int diferentaDistractie) {
    nivelDistractie += diferentaDistractie;
}

void Utilizator::modificareNivelViata(int diferentaViata) {
    nivelViata += diferentaViata;
}


