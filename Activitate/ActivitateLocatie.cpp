#include "ActivitateLocatie.h"
#include "../Exceptii.h"
#include <iostream>


ActivitateLocatie::ActivitateLocatie(Jucator *jucator_, const std::vector<std::pair<std::string, int>> &optiuni_):
    Activitate(jucator_),
    optiuni(optiuni_) {}

void ActivitateLocatie::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Optiunile disponibile:" << std::endl;
    int numarOptiuni = static_cast<int>(this->optiuni.size());
    for (int index = 0; index < numarOptiuni; ++index) {
        std::cout << index + 1 << ". " << this->optiuni[index].first << std::endl;
    }
    std::cout << std::endl;
}

void ActivitateLocatie::activitate(const int &alegere) {
    if (alegere < 1 || alegere > static_cast<int>(this->optiuni.size())) {
        throw OptiuneIndisponibila();
    }
    this->optiuneAleasa = this->optiuni[alegere - 1];
    this->jucator->modificareNivelViata(this->optiuneAleasa.second * this->jucator->getCoeficientViataLocatie());
    this->jucator->modificareNivelHrana(this->optiuneAleasa.second * this->jucator->getCoeficientHranaLocatie());
    this->jucator->modificareBalantaBani(this->optiuneAleasa.second * this->jucator->getCoeficientBaniLocatie());
}

void ActivitateLocatie::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID() << " a ales optiunea " << this->optiuneAleasa.first << " (" << this->optiuneAleasa.second << ")";
}