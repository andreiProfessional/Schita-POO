#ifndef SPAWNLOCATIE_H
#define SPAWNLOCATIE_H
#include "Activitate.h"
#include <vector>


class SpawnLocatie: public Activitate {
private:
    std::vector<Locatie*> locatii;
    Locatie *locatieSpawn;
public:
    SpawnLocatie(Jucator *jucator_, const std::vector<Locatie*> &locatii_);
    void afisare() override;
    void activitate(const int &alegere) override;
    void afisareRaport() const override;
};


#endif
