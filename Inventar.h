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

    std::unordered_map<Statie*, std::vector<Statie*>> statii;
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

    void adaugareMuchieStatii(Statie *statie1, Statie *statie2, const std::string &ruta);
    void adaugareLocatie(Locatie *locatie);
    void adaugareJucator(Jucator *jucator);

    void afisareStatii() const;
    void afisareLocatii() const;
    void afisareJucatori() const;
};



#endif