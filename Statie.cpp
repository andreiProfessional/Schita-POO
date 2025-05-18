#include "Statie.h"
#include "CuloriText.h"
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
    std::cout << nume;
}

void StatieTroleibuz::afisareStatie() {
    std::cout << nume;
}

void StatieTramvai::afisareStatie() {
    std::cout << nume;
}

void StatieMetrou::afisareStatie() {
    std::cout << nume;
}

bool Statie::verificareId(const int &idStatie) {
    return (this->idStatie == idStatie);
}

bool Statie::verificareNume(const std::string &nume) {
    return (this->nume == nume);
}

std::string Statie::gasireNumeStatie() {
    return nume;
}