#ifndef STATIE_H
#define STATIE_H
#include <vector>
#include <string>

class Statie {
private:
    static int contorID;
    const int id;
    std::string nume;
    std::vector<std::string> rute;
public:
    Statie(const std::string &nume_, const std::vector<std::string> &rute_);
    void afisare() const;
    void adaugareRuta(const std::string &ruta);
};


#endif