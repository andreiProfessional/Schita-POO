#include "Statie.h"
#include <iostream>

int Statie::contorID = 0;

Statie::Statie(const std::string &nume):
    idStatie(++ contorID),
    nume(nume) {}

StatieAutobuz::StatieAutobuz(const std::string &nume):
    Statie(nume) {}

StatieTroleibuz::StatieTroleibuz(const std::string &nume):
    Statie(nume) {}

StatieTramvai::StatieTramvai(const std::string &nume):
    Statie(nume) {}

StatieMetrou::StatieMetrou(const std::string &nume):
    Statie(nume) {}


void StatieAutobuz::afisareStatie() {
    std::cout << nume << " (" << idStatie << ") - ";
}

void StatieTroleibuz::afisareStatie() {
    std::cout << nume << " (" << idStatie << ") - ";
}

void StatieTramvai::afisareStatie() {
    std::cout << nume << " (" << idStatie << ") - ";
}

void StatieMetrou::afisareStatie() {
    std::cout << nume << " (" << idStatie << ") - ";
}

bool Statie::verificareId(const int &idStatie) {
    return (this->idStatie == idStatie);
}

bool Statie::verificareNume(const std::string &nume) {
    return (this->nume == nume);
}