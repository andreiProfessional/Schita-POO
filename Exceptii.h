#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>


class InsuficientaViata: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Ai ramas fara viata!";
    }
};

class InsuficientaHrana: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Ai murit de foame!";
    }
};

class InsuficientaBani: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "N-ai destui bani!";
    }
};

class OptiuneIndisponibila: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Optiunea selectata nu este disponibila!";
    }
};

#endif
