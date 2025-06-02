#ifndef ACTIVITATELOCATIE_H
#define ACTIVITATELOCATIE_H
#include "Activitate.h"

class ActivitateLocatie: public Activitate {
private:
    std::vector<std::pair<std::string, int>> optiuni;
    std::pair<std::string, int> optiuneAleasa;
public:
    ActivitateLocatie(Jucator *jucator_, const std::vector<std::pair<std::string, int>> &optiuni_);
    void afisare() override;
    void activitate(const int &alegere) override;
    void afisareRaport() const override;
};



#endif