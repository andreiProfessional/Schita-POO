#ifndef MENIU_H
#define MENIU_H
#include "Utilizator.h"
#include "Locatie.h"
#include <vector>

class Meniu {
private:
    std::vector<Utilizator*> utilizatori;
public:
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
