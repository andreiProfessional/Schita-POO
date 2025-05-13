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

    std::vector<Utilizator*> utilizatori;
public:
    HartaOras(const HartaOras&) = delete;
    HartaOras& operator=(const HartaOras&) = delete;
    static HartaOras& acceseazaSingleton() {
        static HartaOras instanta;
        return instanta;
    }

    void adaugareRuta(const std::string &tip, const std::string &nume, const std::vector<std::string> &listaStatii);
    void creareHartaRute();
    //void afisareStatie(const int &ID);
    void afisareHartaRute();
    void adaugareLocatie(const std::string &tip, const std::string &nume, const std::string &statie, const std::vector<int> &coeficienti);
    void creareHartaLocatii();
    void afisareLocatie(const int &ID);
    void afisareHartaLocatii();
    void adaugareUtilizator(const std::string &tip, const std::string &nume, const std::string &statieApropiata,
        const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie,
        const int &balantaBani, const int &balantaCalatorii);
    void creareListeUtilizatori();
    void afisareUtilizator(const int &ID);
    void afisareListeUtilizatori();
    //Statie* gasireStatie(const int &idStatie);
    Utilizator* gasireUtilizator(const int &idUtilizator);
    Locatie* gasireLocatie(const int &idLocatie);
    void interactiuneUtilizatorLocatie(Utilizator *utilizator, Locatie *locatie);
};

#endif