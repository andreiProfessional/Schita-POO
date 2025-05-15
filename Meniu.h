#ifndef MENIU_H
#define MENIU_H
#include "Jucator.h"
#include "HartaOras.h"
#include <vector>

class Meniu {
private:
    Meniu();
    ~Meniu();

    HartaOras& hartaOras;
    std::vector<Jucator*> jucatori;
    Jucator* jucatorCurent;
public:
    Meniu(const Meniu&) = delete;
    Meniu& operator=(const Meniu&) = delete;
    static Meniu& acceseazaSingleton() {
        static Meniu instanta;
        return instanta;
    }

    void golireEcran();

    void creareHartaOras();
    // void adaugareJucator(const std::string &tip, const std::string &nume, const std::string &statie,
    //     const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie,
    //     const int &balantaBani, const int &balantaCalatorii);
    void creareListaJucatori();
    //void afisareJucator(const int &idJucator);
    void afisareListaJucatori();
    Jucator* gasireJucator(const int &idJucator);

    Locatie* gasireLocatieDupaNume(const std::string &numeLocatie);
    Statie* gasireStatieDupaLocatie(Locatie *locatie);

    bool existaStatie(const std::string &statie);

    void meniuInceput();
    void meniuSfarsit();
    void meniuJucatorVechi();
    void meniuJucatorNou();
    void meniuStartJoc();
    void meniuLocatie();
};


#endif
