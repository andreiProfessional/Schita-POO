#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <string>

class Utilizator {
protected:
    static int contorID;
    const int idUtilizator;
    std::string nume;
    int nivelOdihna;
    int nivelDistractie;
    int nivelViata;
public:
    Utilizator(const std::string &NUME);
    virtual void initializareUtilizator() = 0;
    virtual void afisareUtilizator() = 0;
    void modificareNivelOdihna(int diferentaOdihna);
    void modificareNivelDistractie(int diferentaDistractie);
    void modificareNivelViata(int diferentaViata);
    void afisareNivel(const std::string &mesajNivel, int nivel);
    // friend std::ostream& operator<<(std::ostream& out, const Utilizator& utilizator);
};

class UtilizatorAdmin: public Utilizator {
private:
    const int NIVEL_ODIHNA;
    const int NIVEL_DISTRACTIE;
    const int NIVEL_VIATA;
public:
    UtilizatorAdmin(const std::string &NUME);
    void initializareUtilizator() override;
    void afisareUtilizator() override;
};

class UtilizatorStandard: public Utilizator {
private:
    const int BALANTA_BANI;
    const int BALANTA_CALATORII;
    const int NIVEL_ODIHNA;
    const int NIVEL_DISTRACTIE;
    const int NIVEL_VIATA;
    int balantaBani;
    int balantaCalatorii;
public:
    UtilizatorStandard(const std::string &NUME);
    void initializareUtilizator() override;
    void afisareUtilizator() override;
    void modificareBalantaBani(int diferentaBani);
    void modificareBalantaCalatorii(int diferentaCalatorii);
};


#endif