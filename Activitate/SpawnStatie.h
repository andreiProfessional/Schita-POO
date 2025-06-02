#ifndef SPAWNSTATIE_H
#define SPAWNSTATIE_H
#include "Activitate.h"


class SpawnStatie: public Activitate {
private:
    std::vector<Statie*> statii;
    Statie *statieSpawn;
public:
    SpawnStatie(Jucator *jucator_, const std::unordered_map<Statie*, std::vector<Statie*>> &statii);
    void afisare() override;
    void activitate(const int &alegere) override;
    void afisareRaport() const override;
};



#endif
