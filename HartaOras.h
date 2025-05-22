#ifndef CITYMAP_H
#define CITYMAP_H
#include "Ruta.h"
#include "Locatie.h"
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
    void afisareHartaRute() const;
    //void afisareStatie(const int &id);
    //std::vector <std::pair<Ruta*, int>> gasireStatieDupaNume(const std::string &numeStatie);
    void adaugareLocatie(const std::string &tip, const std::string &nume, const std::string &statie,
        const std::vector<int> &coeficienti);
    void creareHartaLocatii();
    //void afisareLocatie(const int &id);
    void afisareHartaLocatii();

    Locatie* gasireLocatieDupaNume(const std::string &numeLocatie);
    std::vector<std::pair<Ruta*, int>> gasireStatii(const std::string &numeStatieCurenta);
    //Locatie* gasireLocatie(const int &idLocatie);
};

#endif