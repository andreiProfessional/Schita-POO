#ifndef ACTIVITATETAXI_H
#define ACTIVITATETAXI_H
#include "Activitate.h"

class ActivitateTaxi: public Activitate {
private:
    std::vector<Locatie*> locatii;
    Locatie *locatiePlecare;
    Locatie *locatieSosire;
    int pret;
public:
    ActivitateTaxi(Jucator *jucator_, const std::vector<Locatie*> &locatii_);
    void afisare() override;
    void activitate(const int &alegere) override;
    void afisareRaport() const override;
};



#endif