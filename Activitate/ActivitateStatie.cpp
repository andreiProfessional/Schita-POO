#include "ActivitateStatie.h"
#include "../Exceptii.h"
#include "../CuloriText.h"
#include <random>
#include <iostream>

ActivitateStatie::ActivitateStatie(Jucator *jucator_, const std::unordered_map<Statie*, std::vector<Statie*>> &listeAdiacenta_):
    Activitate(jucator_) {
    this->statiePlecare = jucator_->getStatie();
    this->statiiVecine = listeAdiacenta_.at(this->statiePlecare);
    this->statieSosire = nullptr;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution distributie(1, 3);
    this->minusViata = distributie(generator);
    this->minusHrana = distributie(generator);
}

void ActivitateStatie::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Aceasta statie te va costa: "
              << ROSU << this->minusViata << RESETARE << " Viata + "
              << ROSU << this->minusHrana << RESETARE << " Hrana" << std::endl;
    std::cout << "Statii vecine:" << std::endl;
    int numarStatiiVecine = static_cast<int>(this->statiiVecine.size());
    for (int index = 0; index < numarStatiiVecine; index ++) {
        std::cout << index + 1 << ". " << *this->statiiVecine[index] << std::endl;
    }
    std::cout << std::endl;
}

void ActivitateStatie::activitate(const int &alegere) {
    if (alegere < 1 || alegere > static_cast<int>(this->statiiVecine.size())) {
        throw OptiuneIndisponibila();
    }
    this->statieSosire = this->statiiVecine[alegere - 1];
    this->jucator->setStatie(this->statieSosire);
    this->jucator->modificareNivelViata(-1 * this->minusViata);
    this->jucator->modificareNivelHrana(-1 * this->minusHrana);
}

void ActivitateStatie::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID() << " a calatorit de la statia [" << *this->statiePlecare << "] la statia [" << *this->statieSosire << "]";
}