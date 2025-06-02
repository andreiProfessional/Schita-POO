#include "ActivitateTaxi.h"
#include "../CuloriText.h"
#include "../Exceptii.h"
#include <iostream>
#include <random>

ActivitateTaxi::ActivitateTaxi(Jucator *jucator_, const std::vector<Locatie*> &locatii_):
    Activitate(jucator_),
    locatii(locatii_) {
    locatiePlecare = jucator_->getLocatie();
    locatieSosire = nullptr;
    const int numarLocatii = static_cast<int>(this->locatii.size());
    const int pretMinim = numarLocatii / 2;
    const int pretMaxim = numarLocatii;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution distributie(pretMinim, pretMaxim);
    this->pret = distributie(generator);
}

void ActivitateTaxi::afisare() {
    std::cout << *this->jucator << std::endl;
    std::cout << "Pret Calatorie = " << ROSU << this->pret << RESETARE  << " Lei." << std::endl;
    std::cout << "Locatii disponibile: " << std::endl;
    int numarLocatii = static_cast<int>(this->locatii.size());
    for (int index = 0; index < numarLocatii; index ++) {
        std::cout << index + 1 << ". " << *this->locatii[index] << std::endl;
    }
    std::cout << std::endl;
}

void ActivitateTaxi::activitate(const int &alegere) {
    if (alegere < 1 || alegere > static_cast<int>(this->locatii.size())) {
        throw OptiuneIndisponibila();
    }
    this->locatieSosire = locatii[alegere - 1];
    this->jucator->setLocatie(this->locatieSosire);
    this->jucator->modificareBalantaBani(-1 * this->pret);
}

void ActivitateTaxi::afisareRaport() const {
    std::cout << "Jucatorul cu ID-ul " << this->jucator->getID() << " a platit " << this->pret << " Lei "
    << "pentru o cursa de la locatia [" << *this->locatiePlecare << "] la locatia [" << *this->locatieSosire << "]";
}