#ifndef RUTA_H
#define RUTA_H
#include "Statie.h"
#include <string>
#include <vector>

class Ruta {
protected:
    static int contorID;
    const int idRuta;
    std::string nume;
    std::vector<Statie*> statii;
public:
    Ruta(const std::string &nume, const std::vector<Statie*> &statii);

    virtual void afisareRuta() = 0;
};

class RutaAutobuz: public Ruta {
private:

public:
    RutaAutobuz(const std::string &nume, const std::vector<Statie*> &statii);

    void afisareRuta() override;
};


class RutaTroleibuz: public Ruta {
private:

public:
    RutaTroleibuz(const std::string &nume, const std::vector<Statie*> &statii);

    void afisareRuta() override;
};

class RutaTramvai: public Ruta {
private:

public:
    RutaTramvai(const std::string &nume, const std::vector<Statie*> &statii);

    void afisareRuta() override;
};

class RutaMetrou: public Ruta {
private:

public:
    RutaMetrou(const std::string &nume, const std::vector<Statie*> &statii);

    void afisareRuta() override;
};


#endif