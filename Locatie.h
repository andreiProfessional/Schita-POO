#ifndef LOCATIE_H
#define LOCATIE_H
#include "Jucator.h"
#include <string>

class Locatie {
protected:
    static int contorID;
    const int idLocatie;
    const std::string tip;
    const std::string nume;
    const std::string statie;
public:
    Locatie(const std::string &TIP, const std::string &NUME, const std::string &STATIE);
    virtual void afisareLocatie() = 0;
    virtual void aplicaCoeficienti(Jucator *jucator) = 0;
    bool verificareId(const int &ID);
};

class LocatieResedinta: public Locatie {
private:
    const int plusEnergie;
    const int plusNutritie;
    const int minusInteligenta;
public:
    LocatieResedinta(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &PLUS_ENERGIE, const int &PLUS_NUTRITIE, const int &MINUS_INTELIGENTA);

    void afisareLocatie() override;
    void aplicaCoeficienti(Jucator *jucator) override;
};

class LocatieMedicala: public Locatie {
private:
    const int plusViata;
    const int plusEnergie;
    const int minusDistractie;
    const int minusBani;
public:
    LocatieMedicala(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &PLUS_VIATA, const int &PLUS_ENERGIE, const int &MINUS_DISTRACTIE, const int &MINUS_BANI);

    void afisareLocatie() override;
    void aplicaCoeficienti(Jucator *jucator) override;
};

class LocatieEducatie: public Locatie {
private:
    const int plusInteligenta;
    const int minusEnergie;
    const int minusNutritie;
    const int minusDistractie;
public:
    LocatieEducatie(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &PLUS_INTELIGENTA, const int &MINUS_ENERGIE, const int &MINUS_NUTRITIE, const int &MINUS_DISTRACTIE);

    void afisareLocatie() override;
    void aplicaCoeficienti(Jucator *jucator) override;
};

class LocatieMunca: public Locatie {
private:
    const int plusBani;
    const int minusEnergie;
    const int minusNutritie;
    const int minusDistractie;
public:
    LocatieMunca(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &PLUS_BANI, const int &MINUS_ENERGIE, const int &MINUS_NUTRITIE, const int &MINUS_DISTRACTIE);

    void afisareLocatie() override;
    void aplicaCoeficienti(Jucator *jucator) override;
};

class LocatieHoreca: public Locatie {
private:
    const int plusNutritie;
    const int plusDistractie;
    const int minusBani;
public:
    LocatieHoreca(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &PLUS_NUTRITIE, const int &PLUS_DISTRACTIE, const int &MINUS_BANI);

    void afisareLocatie() override;
    void aplicaCoeficienti(Jucator *jucator) override;
};

class LocatieRelaxare: public Locatie {
private:
    const int plusEnergie;
    const int plusDistractie;
    const int minusBani;
public:
    LocatieRelaxare(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &PLUS_ENERGIE, const int &PLUS_DISTRACTIE, const int &MINUS_BANI);

    void afisareLocatie() override;
    void aplicaCoeficienti(Jucator *jucator) override;
};



#endif