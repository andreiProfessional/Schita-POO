#ifndef MENIU_H
#define MENIU_H
#include "Utilizator.h"
#include "HartaOras.h"
#include "Locatie.h"
#include <vector>

class Meniu {
private:
    Meniu();
    ~Meniu();

    HartaOras& hartaOras;
    std::vector<Utilizator*> utilizatori;
public:
    Meniu(const Meniu&) = delete;
    Meniu& operator=(const Meniu&) = delete;
    static Meniu& acceseazaSingleton() {
        static Meniu instanta;
        return instanta;
    }

    void adaugareUtilizator(const std::string &tip, const std::string &nume, const std::string &statieApropiata,
        const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie,
        const int &balantaBani, const int &balantaCalatorii);
    void creareListeUtilizatori();
    void afisareUtilizator(const int &ID);
    void afisareListeUtilizatori();
    Utilizator* gasireUtilizator(const int &idUtilizator);

    void interactiuneUtilizatorLocatie(Utilizator *utilizator, Locatie *locatie);
};


#endif
