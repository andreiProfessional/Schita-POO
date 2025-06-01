#ifndef LOCATIE_H
#define LOCATIE_H
#include "Statie.h"
#include <string>

class Locatie {
private:
    static int contorID;
    const int id;
    std::string nume;
    int coeficientViata;
    int coeficientHrana;
    int coeficientBani;
    Statie *statie;
public:
    Locatie(const std::string &nume_,
        const int &coeficientViata_, const int &coeficientHrana_, const int &coeficientBani_,
        Statie *statie_);
    Locatie(const Locatie &locatie);
    Locatie& operator=(const Locatie &locatie);
    ~Locatie() = default;
    friend std::ostream& operator<<(std::ostream &out, const Locatie &locatie);
    int getCoeficientViata() const;
    int getCoeficientHrana() const;
    int getCoeficientBani() const;
    Statie *getStatie() const;
};


#endif