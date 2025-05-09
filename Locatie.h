#ifndef LOCATIE_H
#define LOCATIE_H
#include <string>

class Locatie {
protected:
    static int contorID;
    const int idLocatie;
    const std::string nume;
    const std::string statieApropiata;
    const int coeficientOdihna;
    const int coeficientDistractie;
    const int coeficientViata;
public:
    Locatie(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA);
    virtual void afisareLocatie() = 0;
};

class LocatieResedinta: public Locatie {
private:

public:
    LocatieResedinta(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA);
    void afisareLocatie() override;
};

class LocatieEducatie: public Locatie {
private:

public:
    LocatieEducatie(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA);
    void afisareLocatie() override;
};

class LocatieMunca: public Locatie {
private:

public:
    LocatieMunca(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA);
    void afisareLocatie() override;
};

class LocatieRelaxare: public Locatie {
private:

public:
    LocatieRelaxare(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA);
    void afisareLocatie() override;
};

class LocatieInstitutie: public Locatie {
private:

public:
    LocatieInstitutie(const std::string &NUME, const std::string &STATIE_APROPIATA, int COEFICIENT_ODIHNA, int COEFICIENT_DISTRACTIE, int COEFICIENT_VIATA);
    void afisareLocatie() override;
};

#endif