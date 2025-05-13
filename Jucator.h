#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <string>

class Jucator {
protected:
    static int contorID;
    const int idJucator;
    const std::string tip;
    std::string nume;
    std::string statie;
    int nivelViata;
    int nivelEnergie;
    int nivelNutritie;
    int nivelInteligenta;
    int nivelDistractie;
public:
    Jucator(const std::string &tip, const std::string &nume, const std::string &statie,
        const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie);
    virtual void afisareJucator() = 0;
    void modificareNivelViata(const int &diferentaViata);
    void modificareNivelEnergie(const int &diferentaEnergie);
    void modificareNivelNutritie(const int &diferentaNutritie);
    void modificareNivelInteligenta(const int &diferentaInteligenta);
    void modificareNivelDistractie(const int&diferentaDistractie);
    void afisareNivel(const std::string &mesajNivel, const int &nivel);
    bool verificareId(const int &ID);
    //friend std::ostream& operator<<(std::ostream& out, const Jucarot& jucator);
};

class JucatorAdmin: public Jucator {
private:
    std::string parola;

public:
    JucatorAdmin(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &NIVEL_VIATA, const int &NIVEL_ENERGIE, const int &NIVEL_NUTRITIE, const int &NIVEL_INTELIGENTA, const int &NIVEL_DISTRACTIE);

    void afisareJucator() override;
};

class JucatorStandard: public Jucator {
private:
    int balantaBani;
    int balantaCalatorii;
public:
    JucatorStandard(const std::string &TIP, const std::string &NUME, const std::string &STATIE,
        const int &NIVEL_VIATA, const int &NIVEL_ENERGIE, const int &NIVEL_NUTRITIE, const int &NIVEL_INTELIGENTA, const int &NIVEL_DISTRACTIE,
        const int &BALANTA_BANI, const int &BALANTA_CALATORII);

    void afisareJucator() override;
    void modificareBalantaBani(const int &diferentaBani);
    void modificareBalantaCalatorii(const int &diferentaCalatorii);
};


#endif