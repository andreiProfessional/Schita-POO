#ifndef ACTIVITATE_H
#define ACTIVITATE_H
#include "Jucator.h"
#include "Locatie.h"
#include <vector>
#include <string>

class Activitate {
protected:
    static int contorID;
    const int id;
public:
    Activitate();
    void afisare() const;
    virtual void afisare() = 0;
    virtual void activitate() = 0;
};

class ActivitateLocatie: public Activitate {
private:
    Jucator *jucator;
    Locatie *locatie;
    std::vector<std::pair<std::string, int>> optiuni;
public:
    ActivitateLocatie(Jucator *jucator_, Locatie *locatie_, const std::vector<std::pair<std::string, int>> &optiuni_);
    void afisare() override;
    void activitate() override;
};


#endif
