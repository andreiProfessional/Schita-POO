#include "Statie.h"
#include <iostream>

int Statie::contorID = 0;

Statie::Statie(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR):
    idStatie(++ contorID),
    tip(TIP),
    linie(LINIE),
    nume(NUME),
    predecesor(PREDECESOR),
    succesor(SUCCESOR) {}

StatieAutobuz::StatieAutobuz(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR):
    Statie(TIP, LINIE, NUME, PREDECESOR, SUCCESOR) {}

StatieTroleibuz::StatieTroleibuz(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR):
    Statie(TIP, LINIE, NUME, PREDECESOR, SUCCESOR) {}

StatieTramvai::StatieTramvai(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR):
    Statie(TIP, LINIE, NUME, PREDECESOR, SUCCESOR) {}

StatieMetrou::StatieMetrou(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR):
    Statie(TIP, LINIE, NUME, PREDECESOR, SUCCESOR) {}


void StatieAutobuz::afisareStatie() {
    std::cout << idStatie << ": " << nume << " | " << tip << " | " << linie << " | " << predecesor << " | " << succesor << std::endl;
}

void StatieTroleibuz::afisareStatie() {
    std::cout << idStatie << ": " << nume << " | " << tip << " | " << linie << " | " << predecesor << " | " << succesor << std::endl;
}

void StatieTramvai::afisareStatie() {
    std::cout << idStatie << ": " << nume << " | " << tip << " | " << linie << " | " << predecesor << " | " << succesor << std::endl;
}

void StatieMetrou::afisareStatie() {
    std::cout << idStatie << ": " << nume << " | " << tip << " | " << linie << " | " << predecesor << " | " << succesor << std::endl;
}

bool Statie::verificareId(const int &ID) {
    return (idStatie == ID);
}