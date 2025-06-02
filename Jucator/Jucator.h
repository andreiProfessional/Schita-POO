#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include "../Locatie.h"
#include "../Statie.h"
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
    Jucator(const Jucator &jucator);
    Jucator& operator=(const Jucator &jucator);
    ~Jucator() = default;
    friend std::ostream& operator<<(std::ostream &out, const Jucator &jucator);
    friend bool operator>(const Jucator &jucator1, const Jucator &jucator2);
    Jucator& operator+=(const Jucator &jucator);
    void modificareNivelViata(const int &diferentaViata);
    void modificareNivelHrana(const int &diferentaHrana);
    void modificareBalantaBani(const int &diferentaBani);
    int getCoeficientViataLocatie() const;
    int getCoeficientHranaLocatie() const;
    int getCoeficientBaniLocatie() const;
    Locatie *getLocatie() const;
    Statie *getStatie() const;
    void setLocatie(Locatie *locatie_);
    void setStatie(Statie *statie_);
    bool verificaID(const int& id);
    int getID() const;
};

#endif