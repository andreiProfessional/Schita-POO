#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <string>


class Jucator {
private:
    static int contorID;
    const int id;
    std::string nume;
    int nivelViata;
    int nivelHrana;
    int balantaBani;
public:
    Jucator(const std::string &nume_, const int &nivelViata_, const int &nivelHrana_, const int &balantaBani_);
    void afisare() const;
    void modificareStatistici(const int &diferentaNivel, const int &diferentaHrana, const int &diferentaBani);
};

class JucatorFactory {
public:
    static Jucator* tataBogat(const std::string &nume_) {return new Jucator(nume_, 90, 80, 2000);}
    static Jucator* tataSarac(const std::string &nume_) {return new Jucator(nume_, 45, 40, 500);}
    static Jucator* magnatBatran(const std::string &nume_) {return new Jucator(nume_, 40, 70, 5000);}
    static Jucator* omDeRand(const std::string &nume_) {return new Jucator(nume_, 75, 75, 750);}
    static Jucator* pierdeVara(const std::string &nume_) {return new Jucator(nume_, 80, 40, 350);}
};

#endif