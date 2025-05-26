#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>


class InsuficientaViata: public std::exception {
public:
    virtual const char* what() const throw() {
        return "Ai ramas fara viata!";
    }
};

class InsuficientaHrana: public std::exception {
public:
    virtual const char* what() const throw() {
        return "Ai murit de foame!";
    }
};

class InsuficientaBani: public std::exception {
public:
    virtual const char* what() const throw() {
        return "N-ai destui bani!";
    }
};

class OptiuneIndisponibila: public std::exception {
public:
    virtual const char* what() const throw() {
        return "Optiunea selectata nu este disponibila!";
    }
};

#endif
