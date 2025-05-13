#ifndef CITYMAP_H
#define CITYMAP_H
#include "Ruta.h"
#include "Locatie.h"
#include "Utilizator.h"
#include <vector>
#include <iostream>

class HartaOras {
private:
    HartaOras();
    ~HartaOras();

    std::vector<Ruta*> rute;
    std::vector<Locatie*> locatii;
public:
    HartaOras(const HartaOras&) = delete;
    HartaOras& operator=(const HartaOras&) = delete;
    static HartaOras& acceseazaSingleton() {
        static HartaOras instanta;
        return instanta;
    }

    void adaugareRuta(const std::string &tip, const std::string &nume, const std::vector<std::string> &listaStatii);
    void creareHartaRute();
    void afisareHartaRute();
    //void afisareStatie(const int &ID);
    void adaugareLocatie(const std::string &tip, const std::string &nume, const std::string &statie, const std::vector<int> &coeficienti);
    void creareHartaLocatii();
    //void afisareLocatie(const int &ID);
    void afisareHartaLocatii();

    //Statie* gasireStatie(const int &idStatie);
    //Locatie* gasireLocatie(const int &idLocatie);
};

#endif