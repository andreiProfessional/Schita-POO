#ifndef LOCATIE_H
#define LOCATIE_H
#include "Statie.h"
#include <string>

class Locatie {
protected:
    static int contorID;
    const int idLocatie;
    const std::string nume;
    Statie *statie;
public:
    Locatie(const std::string &nume, Statie *statie);
    virtual void afisareLocatie() = 0;
    virtual void afisareOptiuniLocatie() = 0;
    virtual int diferentaBani(const int &optiune) = 0;
    virtual int diferentaViata(const int &optiune) = 0;
    virtual int diferentaEnergie(const int &optiune) = 0;
    virtual int diferentaNutritie(const int &optiune) = 0;
    bool verificareId(const int &idLocatie);
    bool verificareNume(const std::string &nume);
    Statie* gasireStatie();
    std::string gasesteNumeLocatie();
};

class LocatieResedinta: public Locatie {
private:
    const int plusEnergie;
public:
    LocatieResedinta(const std::string &nume, Statie *statie,
        const int &plusEnergie);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
    int diferentaBani(const int &optiune) override;
    int diferentaViata(const int &optiune) override;
    int diferentaEnergie(const int &optiune) override;
    int diferentaNutritie(const int &optiune) override;
};

class LocatieSport: public Locatie {
private:
    const int plusViata;
    const int minusBani;
    const int minusEnergie;
    const int minusNutritie;
public:
    LocatieSport(const std::string &nume, Statie *statie,
        const int &plusViata, const int &minusBani, const int &minusEnergie, const int &minusNutritie);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
    int diferentaBani(const int &optiune) override;
    int diferentaViata(const int &optiune) override;
    int diferentaEnergie(const int &optiune) override;
    int diferentaNutritie(const int &optiune) override;
};

class LocatieMedicala: public Locatie {
private:
    const int plusViata;
    const int minusBani;
public:
    LocatieMedicala(const std::string &nume, Statie *statie,
        const int &plusViata, const int &minusBani);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
    int diferentaBani(const int &optiune) override;
    int diferentaViata(const int &optiune) override;
    int diferentaEnergie(const int &optiune) override;
    int diferentaNutritie(const int &optiune) override;
};

class LocatieMunca: public Locatie {
private:
    const int plusBani;
    const int minusEnergie;
    const int minusNutritie;
public:
    LocatieMunca(const std::string &nume, Statie *statie,
        const int &plusBani, const int &minusEnergie, const int &minusNutritie);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
    int diferentaBani(const int &optiune) override;
    int diferentaViata(const int &optiune) override;
    int diferentaEnergie(const int &optiune) override;
    int diferentaNutritie(const int &optiune) override;
};

class LocatieHoreca: public Locatie {
private:
    const int plusNutritie;
    const int minusBani;
public:
    LocatieHoreca(const std::string &nume, Statie *statie,
        const int &plusNutritie, const int &minusBani);

    void afisareLocatie() override;
    void afisareOptiuniLocatie() override;
    int diferentaBani(const int &optiune) override;
    int diferentaViata(const int &optiune) override;
    int diferentaEnergie(const int &optiune) override;
    int diferentaNutritie(const int &optiune) override;
};


#endif