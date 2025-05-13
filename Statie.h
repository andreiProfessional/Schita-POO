#ifndef STATIE_H
#define STATIE_H
#include <string>

class Statie {
protected:
    static int contorID;
    const int idStatie;
    const std::string nume;
public:
    Statie(const std::string &nume);
    virtual void afisareStatie() = 0;
    void obtinereListaLocatii();
    bool verificareId(const int &idStatie);
    bool verificareNume(const std::string &nume);
};

class StatieAutobuz: public Statie {
private:

public:
    StatieAutobuz(const std::string &nume);
    void afisareStatie() override;
};

class StatieTroleibuz: public Statie {
private:

public:
    StatieTroleibuz(const std::string &nume);
    void afisareStatie() override;
};

class StatieTramvai: public Statie {
private:

public:
    StatieTramvai(const std::string &nume);
    void afisareStatie() override;
};

class StatieMetrou: public Statie {
private:

public:
    StatieMetrou(const std::string &nume);
    void afisareStatie() override;
};


#endif