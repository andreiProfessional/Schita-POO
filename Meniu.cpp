#include "Meniu.h"
#include "Inventar.h"
#include <iostream>

Meniu::Meniu(): inventar(Inventar::acceseazaSingleton()) {
    std::cout << "God Message: Orasul a fost creat!" << std::endl << std::endl;
    this->inventar.populareInventar();
}

Meniu::~Meniu() {std::cout << "God Message: Orasul a fost distrus!" << std::endl << std::endl;}

void Meniu::afisareInventar() const {
    this->inventar.afisareStatii();
    this->inventar.afisareListeAdiacentaStatii();
    this->inventar.afisareLocatii();
    this->inventar.afisareJucatori();
    this->inventar.afisareIstoricActivitati();
}

void Meniu::creareActivitate(const int& idJucator, const int& tipActivitate, const int& alegerea) {
    inventar.adaugareActivitate(idJucator, tipActivitate, alegerea);
}


void Meniu::run() {
    this->inventar.sortareJucatori();
    this->afisareInventar();
    this->creareActivitate(1, 1, 1);
    this->creareActivitate(1, 3, 2);
    this->creareActivitate(1, 5, 1);
    this->creareActivitate(1, 6, 1);
    this->creareActivitate(2, 2, 3);
    this->creareActivitate(2, 4, 1);
    this->creareActivitate(2, 7, 1);
    this->afisareInventar();

}
