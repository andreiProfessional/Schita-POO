#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <string>

class Jucator {
protected:
    static int contorID;
    const int idJucator;
    std::string nume;
    std::string statie;
    int nivelViata;
    int nivelEnergie;
    int nivelNutritie;
    int nivelInteligenta;
    int nivelDistractie;
    int balantaBani;
    int balantaCalatorii;
public:
    Jucator(const std::string &nume, const std::string &statie,
        const int &nivelViata = 100,
        const int &nivelEnergie = 100,
        const int &nivelNutritie = 100,
        const int &nivelInteligenta = 100,
        const int &nivelDistractie = 100,
        const int &balantaBani = 50, const int &balantaCalatorii = 0);

    bool verificareId(const int &id);
    void afisareJucator();
    void afisareNivel(const std::string &mesajNivel, const int &nivel);

    void modificareNivelViata(const int &diferentaViata);
    void modificareNivelEnergie(const int &diferentaEnergie);
    void modificareNivelNutritie(const int &diferentaNutritie);
    void modificareNivelInteligenta(const int &diferentaInteligenta);
    void modificareNivelDistractie(const int&diferentaDistractie);
    void modificareBalantaBani(const int &diferentaBani);
    void modificareBalantaCalatorii(const int &diferentaCalatorii);

    //friend std::ostream& operator<<(std::ostream& out, const Jucarot& jucator);
};


#endif