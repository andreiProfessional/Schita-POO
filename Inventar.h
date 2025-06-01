#ifndef INVENTAR_H
#define INVENTAR_H
#include "Jucator.h"
#include "Locatie.h"
#include "Statie.h"
#include "Activitate.h"
#include <unordered_map>

class Inventar {
private:
    Inventar();
    ~Inventar();

    std::vector<Statie*> statii;
    std::unordered_map<Statie*, std::vector<Statie*>> listeAdiacentaStatii;
    std::vector<Locatie*> locatii;
    std::vector<Jucator*> jucatori;
    std::vector<Activitate*> istoricActivitati;
public:
    Inventar(const Inventar&) = delete;
    Inventar& operator=(const Inventar&) = delete;
    static Inventar& acceseazaSingleton() {
        static Inventar instanta;
        return instanta;
    }

    void adaugareStatie(Statie *statie);
    void adaugareMuchieStatii(Statie *statie1, Statie *statie2);
    void adaugareLocatie(Locatie *locatie);
    void adaugareJucator(Jucator *jucator);

    void populareInventar();

    void afisareStatii() const;
    void afisareListeAdiacentaStatii() const;
    void afisareLocatii() const;
    void afisareJucatori() const;

    void sortareJucatori();

    Statie* getStatieDupaID(const int &idStatie);
};



#endif