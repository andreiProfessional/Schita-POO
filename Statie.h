#ifndef STATIE_H
#define STATIE_H
#include <string>

class Statie {
protected:
    static int contorID;
    const int idStatie;
    const std::string nume;
    const std::string tip;
    const std::string linie;
    const std::string predecesor;
    const std::string succesor;
public:
    Statie(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR);
    virtual void afisareStatie() = 0;
    void obtinereListaLocatii();
    bool verificareId(const int &id_statie);
};

class StatieAutobuz: public Statie {
private:

public:
    StatieAutobuz(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR);
    void afisareStatie() override;
};

class StatieTroleibuz: public Statie {
private:

public:
    StatieTroleibuz(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR);
    void afisareStatie() override;
};

class StatieTramvai: public Statie {
private:

public:
    StatieTramvai(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR);
    void afisareStatie() override;
};

class StatieMetrou: public Statie {
private:

public:
    StatieMetrou(const std::string &TIP, const std::string &LINIE, const std::string &NUME,
    const std::string &PREDECESOR, const std::string &SUCCESOR);
    void afisareStatie() override;
};


#endif