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
    virtual ~Activitate() = default;
    void afisare() const;
    virtual void afisare() = 0;
    virtual void activitate(const int &optiune) = 0;
};

class ActivitateLocatie: public Activitate {
private:
    Jucator *jucator;
    std::vector<std::pair<std::string, int>> optiuni;
public:
    ActivitateLocatie(Jucator *jucator_, const std::vector<std::pair<std::string, int>> &optiuni_);
    void afisare() override;
    void activitate(const int &alegere) override;
};

class ActivitateTaxi: public Activitate {
private:
    Jucator *jucator;
    std::vector<Locatie*> locatii;
public:
    ActivitateTaxi(Jucator *jucator_, const std::vector<Locatie*> &locatii_);
    void afisare() override;
    void activitate(const int &alegere) override;
};


#endif
