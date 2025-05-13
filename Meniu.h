#ifndef MENIU_H
#define MENIU_H
#include "Jucator.h"
#include "HartaOras.h"
#include "Locatie.h"
#include <vector>

class Meniu {
private:
    Meniu();
    ~Meniu();

    HartaOras& hartaOras;
    std::vector<Jucator*> jucatori;
public:
    Meniu(const Meniu&) = delete;
    Meniu& operator=(const Meniu&) = delete;
    static Meniu& acceseazaSingleton() {
        static Meniu instanta;
        return instanta;
    }

    void adaugareJucator(const std::string &tip, const std::string &nume, const std::string &statie,
        const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie,
        const int &balantaBani, const int &balantaCalatorii);
    void creareListeJucatori();
    void afisareJucator(const int &ID);
    void afisareListeJucatori();
    Jucator* gasireJucator(const int &idJucator);

    void interactiuneJucatorLocatie(Jucator *jucator, Locatie *locatie);
};


#endif
