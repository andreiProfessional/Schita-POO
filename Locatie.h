#ifndef LOCATIE_H
#define LOCATIE_H
#include <string>

class Locatie {
private:
    static int contorID;
    const int id;
    const std::string nume;
    int coeficientViata;
    int coeficientHrana;
    int coeficientBani;
public:
    Locatie(const std::string &nume_, const int &coeficientViata_, const int &coeficientHrana_, const int &coeficientBani_);
    void afisare() const;
    int getCoeficientViata() const;
    int getCoeficientHrana() const;
    int getCoeficientBani() const;
};


#endif