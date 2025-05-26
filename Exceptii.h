#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>


class InsuficientaViata: public std::exception {
public:
    virtual const char* what() const throw();
};

class InsuficientaHrana: public std::exception {
public:
    virtual const char* what() const throw();
};

class InsuficientaBani: public std::exception {
public:
    virtual const char* what() const throw();
};

class OptiuneIndisponibila: public std::exception {
public:
    virtual const char* what() const throw();
};

#endif
