#ifndef ACTIVITATE_H
#define ACTIVITATE_H
#include "../Jucator/Jucator.h"
#include "../Locatie.h"
#include <vector>
#include <string>
#include <unordered_map>


class Activitate {
protected:
    static int contorID;
    const int id;
    Jucator *jucator;
public:
    explicit Activitate(Jucator *jucator_);
    Activitate(const Activitate &activitate);
    Activitate& operator=(const Activitate &activitate);
    virtual ~Activitate() = default;
    virtual void afisare() = 0;
    virtual void activitate(const int &optiune) = 0;
    virtual void afisareRaport() const = 0;
};




class StatieCatreLocatie: public Activitate {
private:
    std::vector<Locatie*> locatii;
    Statie *statie;
    Locatie *locatie;
public:
    StatieCatreLocatie(Jucator *jucator_, const std::vector<Locatie*> &locatii_);
    void afisare() override;
    void activitate(const int &alegere) override;
    void afisareRaport() const override;
};

#endif