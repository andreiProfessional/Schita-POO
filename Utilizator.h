#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <string>

class Utilizator {
protected:
    static int contorID;
    const int idUtilizator;
    const std::string tip;
    std::string nume;
    std::string statie;
    int nivelViata;
    int nivelEnergie;
    int nivelNutritie;
    int nivelInteligenta;
    int nivelDistractie;
public:
    Utilizator(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &NIVEL_VIATA, const int &NIVEL_ENERGIE, const int &NIVEL_NUTRITIE, const int &NIVEL_INTELIGENTA, const int &NIVEL_DISTRACTIE);
    virtual void afisareUtilizator() = 0;
    void modificareNivelViata(const int &diferentaViata);
    void modificareNivelEnergie(const int &diferentaEnergie);
    void modificareNivelNutritie(const int &diferentaNutritie);
    void modificareNivelInteligenta(const int &diferentaInteligenta);
    void modificareNivelDistractie(const int &diferentaDistractie);
    void afisareNivel(const std::string &mesajNivel, const int &nivel);
    bool verificareId(const int &ID);
    //friend std::ostream& operator<<(std::ostream& out, const Utilizator& utilizator);
};

class UtilizatorAdmin: public Utilizator {
private:
    std::string parola;

public:
    UtilizatorAdmin(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &NIVEL_VIATA, const int &NIVEL_ENERGIE, const int &NIVEL_NUTRITIE, const int &NIVEL_INTELIGENTA, const int &NIVEL_DISTRACTIE);

    void afisareUtilizator() override;
};

class UtilizatorStandard: public Utilizator {
private:
    int balantaBani;
    int balantaCalatorii;
public:
    UtilizatorStandard(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &NIVEL_VIATA, const int &NIVEL_ENERGIE, const int &NIVEL_NUTRITIE, const int &NIVEL_INTELIGENTA, const int &NIVEL_DISTRACTIE,
        const int &BALANTA_BANI, const int &BALANTA_CALATORII);

    void afisareUtilizator() override;
    void modificareBalantaBani(const int &diferentaBani);
    void modificareBalantaCalatorii(const int &diferentaCalatorii);
};


#endif