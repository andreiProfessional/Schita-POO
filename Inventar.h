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

    std::vector<Jucator*> jucatori;
    std::vector<Locatie*> locatii;
    std::unordered_map<Statie*, std::vector<Statie*>> statii;
    std::vector<Activitate*> istoricActivitati;
public:
    Inventar(const Inventar&) = delete;
    Inventar& operator=(const Inventar&) = delete;
    static Inventar& acceseazaSingleton() {
        static Inventar instanta;
        return instanta;
    }

    void adaugareJucator(Jucator *jucator);
    void adaugareLocatie(Locatie *locatie);
    void adaugareMuchieStatii(Statie *statie1, Statie *statie2, const std::string &ruta);
    void afisareJucatori() const;
    void afisareLocatii() const;
    void afisareStatii() const;
};



#endif