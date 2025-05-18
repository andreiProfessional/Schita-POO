#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include "Statie.h"
#include "Locatie.h"
#include <string>
#include <vector>


class Jucator {
protected:
    static int contorID;
    const int idJucator;
    std::string nume;
    Locatie *locatie;
    std::pair<Ruta*, int> statie;
    int balantaBani;
    int nivelViata;
    int nivelEnergie;
    int nivelNutritie;
public:
    Jucator(const std::string &nume = "NO NAME",
        Locatie *locatie = nullptr, const std::pair<Ruta*, int> &statie = {nullptr, -1},
        const int &balantaBani = 50,
        const int &nivelViata = 100,
        const int &nivelEnergie = 100,
        const int &nivelNutritie = 100);

    bool verificareId(const int &id);
    void afisareJucator();
    void afisareNivel(const std::string &mesajNivel, const std::string &simbolPozitiv, const std::string &simbolNegativ, const int &nivel);
    void afisareLocatie();
    void afisareOptiuniLocatie();
    Locatie *gasireLocatie();
    std::pair<Ruta*, int> gasireStatie();
    void setareStatie(const std::pair<Ruta*, int> &statie);
    void afisareStatie();

    int calcularePretRuta();
    void modificareBalantaBani(const int &diferentaBani);
    void modificareNivelViata(const int &diferentaViata);
    void modificareNivelEnergie(const int &diferentaEnergie);
    void modificareNivelNutritie(const int &diferentaNutritie);
    void aplicareCoeficienti(const int &optiune);
    void plataMijlocTransport();
};


#endif