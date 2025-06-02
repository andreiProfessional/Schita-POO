#include "JucatorFactory.h"

Jucator* JucatorFactory::tataBogat(const std::string &nume_) {
    return new Jucator(nume_, 90, 80, 2000, nullptr, nullptr);
}

Jucator* JucatorFactory::tataSarac(const std::string &nume_) {
    return new Jucator(nume_, 45, 40, 500, nullptr, nullptr);
}

Jucator* JucatorFactory::magnatBatran(const std::string &nume_) {
    return new Jucator(nume_, 40, 70, 5000, nullptr, nullptr);
}

Jucator* JucatorFactory::omDeRand(const std::string &nume_) {
    return new Jucator(nume_, 75, 75, 750, nullptr, nullptr);
}

Jucator* JucatorFactory::pierdeVara(const std::string &nume_) {
    return new Jucator(nume_, 80, 40, 350, nullptr, nullptr);
}