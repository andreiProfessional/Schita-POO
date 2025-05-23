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
    void modificareStatistici(const int &multiplicator);
    void modificareBalantaBani(const int &diferentaBani);
    void setLocatie(Locatie *locatie);
    void setStatie(Statie *statie);
};


class JucatorFactory {
public:
    static Jucator* tataBogat(const std::string &nume_, Locatie *locatie, Statie *statie);
    static Jucator* tataSarac(const std::string &nume_, Locatie *locatie, Statie *statie);
    static Jucator* magnatBatran(const std::string &nume_, Locatie *locatie, Statie *statie);
    static Jucator* omDeRand(const std::string &nume, Locatie *locatie, Statie *statie);
    static Jucator* pierdeVara(const std::string &nume_, Locatie *locatie, Statie *statie);
};

#endif