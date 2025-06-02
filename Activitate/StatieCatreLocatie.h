#ifndef STATIECATRELOCATIE_H
#define STATIECATRELOCATIE_H
#include "Activitate.h"

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
