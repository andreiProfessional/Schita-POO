#ifndef JUCATORFACTORY_H
#define JUCATORFACTORY_H
#include "Jucator.h"

class JucatorFactory {
public:
    static Jucator* tataBogat(const std::string &nume_);
    static Jucator* tataSarac(const std::string &nume_);
    static Jucator* magnatBatran(const std::string &nume_);
    static Jucator* omDeRand(const std::string &nume);
    static Jucator* pierdeVara(const std::string &nume_);
};



#endif