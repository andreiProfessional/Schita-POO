#include "Jucator.h"
#include <iostream>


int Jucator::contorID = 0;

Jucator::Jucator(const std::string &nume_, const int &nivelViata_, const int &nivelHrana_, const int &balantaBani_):
    id(++ contorID),
    nume(nume_),
    nivelViata(nivelViata_),
    nivelHrana(nivelHrana_),
    balantaBani(balantaBani_)
{}

void Jucator::afisare() const {
    std::cout << "Jucatorul " << this->id << " : "
              << this->nume << " | "
              << this->nivelViata << " | "
              << this->nivelHrana << " | "
              << this-> balantaBani << std::endl;
}

void Jucator::modificareStatistici(const int &diferentaNivel, const int &diferentaHrana, const int &diferentaBani) {
    this->nivelViata += diferentaNivel;
    this->nivelHrana += diferentaHrana;
    this->balantaBani += diferentaBani;
}