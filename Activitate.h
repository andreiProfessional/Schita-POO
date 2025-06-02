#ifndef ACTIVITATE_H
#define ACTIVITATE_H
#include "Jucator.h"
#include "Locatie.h"
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

class LocatieCatreStatie: public Activitate {
private:
    Locatie *locatie;
    Statie *statie;
public:
    LocatieCatreStatie(Jucator *jucator_);
    void afisare() override;
    void activitate(const int &alegere) override;
    void afisareRaport() const override;
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