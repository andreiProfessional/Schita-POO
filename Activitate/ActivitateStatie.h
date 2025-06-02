#ifndef ACTIVITATESTATIE_H
#define ACTIVITATESTATIE_H
#include "Activitate.h"
#include <unordered_map>

class ActivitateStatie: public Activitate {
private:
    std::vector<Statie*> statiiVecine;
    Statie *statiePlecare;
    Statie *statieSosire;
    int minusViata;
    int minusHrana;
public:
    ActivitateStatie(Jucator *jucator_, const std::unordered_map<Statie*, std::vector<Statie*>> &statii);
    void afisare() override;
    void activitate(const int &alegere) override;
    void afisareRaport() const override;
};



#endif