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
    Statie(const Statie &statie);
    Statie& operator=(const Statie &statie);
    ~Statie() = default;
    friend std::ostream& operator<<(std::ostream &out, const Statie &statie);
    friend std::istream& operator>>(std::istream &in, Statie &statie);
    void adaugareRuta(const std::string &ruta);
};


#endif