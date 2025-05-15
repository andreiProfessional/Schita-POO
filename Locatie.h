#ifndef LOCATIE_H
#define LOCATIE_H
#include "Statie.h"
#include <string>

class Locatie {
protected:
    static int contorID;
    const int idLocatie;
    const std::string tip;
    const std::string nume;
    Statie *statie;
public:
    Locatie(const std::string &tip, const std::string &nume, Statie *statie);
    virtual void afisareLocatie() = 0;
    virtual void afisareOptiuniLocatie() = 0;
    bool verificareId(const int &idLocatie);
    bool verificareNume(const std::string &nume);
    Statie* gasireStatie();
    std::string gasesteNumeLocatie();
};

class LocatieResedinta: public Locatie {
private:
    const int plusEnergie;
public:
    LocatieResedinta(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusEnergie);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
};

class LocatieSport: public Locatie {
private:
    const int plusViata;
    const int minusBani;
    const int minusEnergie;
    const int minusNutritie;
public:
    LocatieSport(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusViata, const int &minusBani, const int &minusEnergie, const int &minusNutritie);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
};

class LocatieMedicala: public Locatie {
private:
    const int plusViata;
    const int minusBani;
public:
    LocatieMedicala(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusViata, const int &minusBani);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
};

class LocatieMunca: public Locatie {
private:
    const int plusBani;
    const int minusEnergie;
    const int minusNutritie;
public:
    LocatieMunca(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusBani, const int &minusEnergie, const int &minusNutritie);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
};

class LocatieHoreca: public Locatie {
private:
    const int plusNutritie;
    const int minusBani;
public:
    LocatieHoreca(const std::string &tip, const std::string &nume, Statie *statie,
        const int &plusNutritie, const int &minusBani);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
};


#endif