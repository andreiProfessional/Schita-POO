#ifndef CITYMAP_H
#define CITYMAP_H
#include "Statie.h"
#include "Locatie.h"
#include <vector>
#include <iostream>

class HartaOras {
private:
    HartaOras();
    ~HartaOras();

    std::vector<StatieAutobuz*> statiiAutobuz;
    std::vector<StatieTroleibuz*> statiiTroleibuz;
    std::vector<StatieTramvai*> statiiTramvai;
    std::vector<StatieMetrou*> statiiMetrou;
    std::vector<LocatieResedinta*> locatiiResedinta;
    std::vector<LocatieEducatie*> locatiiEducatie;
    std::vector<LocatieMunca*> locatiiMunca;
    std::vector<LocatieRelaxare*> locatiiRelaxare;
    std::vector<LocatieInstitutie*> locatiiInstitutie;
public:
    HartaOras(const HartaOras&) = delete;
    HartaOras& operator=(const HartaOras&) = delete;
    static HartaOras& acceseazaSingleton() {
        static HartaOras instanta;
        return instanta;
    }

    void adaugareStatie(std::string tip, std::string linie, std::string nume, std::string predecesor, std::string succesor);
    void creareHartaStatii();
    void afisareHartaStatii();
    void adaugareLocatie(std::string tip, std::string nume, std::string statieApropiata, int coeficientOdihna, int coeficientDistractie, int coeficientViata);
    void creareHartaLocatii();
    void afisareHartaLocatii();
};

#endif