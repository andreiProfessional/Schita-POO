#include "Meniu.h"
#include "Inventar.h"
#include <iostream>

Meniu::Meniu(): inventar(Inventar::acceseazaSingleton()) {
    std::cout << "God Message: Orasul a fost creat!" << std::endl << std::endl;
    this->inventar.populareInventar();
}

Meniu::~Meniu() {std::cout << "God Message: Orasul a fost distrus!" << std::endl << std::endl;}


void Meniu::golireEcran() {
    system("clear");
}

void Meniu::afisareInventar() const {
    this->inventar.afisareStatii();
    this->inventar.afisareListeAdiacentaStatii();
    this->inventar.afisareLocatii();
    this->inventar.afisareJucatori();
}

void Meniu::run() {
    this->inventar.sortareJucatori();
    this->afisareInventar();

}
