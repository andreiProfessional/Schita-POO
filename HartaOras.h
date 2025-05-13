#ifndef CITYMAP_H
#define CITYMAP_H
#include "Statie.h"
#include "Locatie.h"
#include <vector>
#include <iostream>

#include "Utilizator.h"

class HartaOras {
private:
    HartaOras();
    ~HartaOras();

    std::vector<Statie*> statii;
    std::vector<Locatie*> locatii;
    std::vector<Utilizator*> utilizatori;
public:
    HartaOras(const HartaOras&) = delete;
    HartaOras& operator=(const HartaOras&) = delete;
    static HartaOras& acceseazaSingleton() {
        static HartaOras instanta;
        return instanta;
    }

    void adaugareStatie(const std::string &tip, const std::string &linie, const std::string &nume,
        const std::string &predecesor, const std::string &succesor);
    void creareHartaStatii();
    void afisareStatie(const int &ID);
    void afisareHartaStatii();
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
    Statie* gasireStatie(const int &idStatie);
    Utilizator* gasireUtilizator(const int &idUtilizator);
    Locatie* gasireLocatie(const int &idLocatie);
    void interactiuneUtilizatorLocatie(Utilizator *utilizator, Locatie *locatie);
};

#endif