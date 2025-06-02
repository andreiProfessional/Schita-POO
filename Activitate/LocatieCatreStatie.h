#ifndef LOCATIECATRESTATIE_H
#define LOCATIECATRESTATIE_H
#include "Activitate.h"


class LocatieCatreStatie: public Activitate {
private:
    Locatie *locatie;
    Statie *statie;
public:
    explicit LocatieCatreStatie(Jucator *jucator_);
    void afisare() override;
    void activitate(const int &alegere) override;
    void afisareRaport() const override;
};



#endif
