#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include "Locatie.h"
#include "Statie.h"
#include <string>


class Jucator {
private:
    static int contorID;
    const int id;
    std::string nume;
    int nivelViata;
    int nivelHrana;
    int balantaBani;
    Locatie *locatie;
    Statie *statie;
public:
    Jucator(const std::string &nume_, const int &nivelViata_, const int &nivelHrana_, const int &balantaBani_,
        Locatie *locatie_, Statie *statie_);
    void afisare() const;
    void modificareNivelViata(const int &diferentaViata);
    void modificareNivelHrana(const int &diferentaHrana);
    void modificareBalantaBani(const int &diferentaBani);
    int getCoeficientViataLocatie();
    int getCoeficientHranaLocatie();
    int getCoeficientBaniLocatie();
    Locatie *getLocatie();
    Statie *getStatie();
    void setLocatie(Locatie *locatie_);
    void setStatie(Statie *statie_);
};


class JucatorFactory {
public:
    static Jucator* tataBogat(const std::string &nume_);
    static Jucator* tataSarac(const std::string &nume_);
    static Jucator* magnatBatran(const std::string &nume_);
    static Jucator* omDeRand(const std::string &nume);
    static Jucator* pierdeVara(const std::string &nume_);
};

#endif