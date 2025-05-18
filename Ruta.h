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
    virtual void afisareDetaliiRuta() = 0;
    virtual int gasirePret(const int &balantaBani) = 0;

    std::pair<Ruta*, int> gasireStatie(const std::string &numeStatie);
    void afisareStatie(const int &pozitie);
};

class RutaAutobuz: public Ruta {
private:

public:
    RutaAutobuz(const std::string &nume, const std::vector<Statie*> &statii);

    void afisareRuta() override;
    void afisareDetaliiRuta() override;
    int gasirePret(const int &balantaBani) override;
};


class RutaTroleibuz: public Ruta {
private:

public:
    RutaTroleibuz(const std::string &nume, const std::vector<Statie*> &statii);

    void afisareRuta() override;
    void afisareDetaliiRuta() override;
    int gasirePret(const int &balantaBani) override;
};

class RutaTramvai: public Ruta {
private:

public:
    RutaTramvai(const std::string &nume, const std::vector<Statie*> &statii);

    void afisareRuta() override;
    void afisareDetaliiRuta() override;
    int gasirePret(const int &balantaBani) override;
};

class RutaMetrou: public Ruta {
private:

public:
    RutaMetrou(const std::string &nume, const std::vector<Statie*> &statii);

    void afisareRuta() override;
    void afisareDetaliiRuta() override;
    int gasirePret(const int &balantaBani) override;
};


#endif