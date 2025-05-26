#include "Exceptii.h"

const char* InsuficientaViata::what() const throw() {
    return "Ai ramas fara viata!";
}

const char* InsuficientaHrana::what() const throw() {
    return "Ai murit de foame!";
}

const char* InsuficientaBani::what() const throw() {
    return "N-ai destui bani!";
}

const char* OptiuneIndisponibila::what() const throw() {
    return "Optiunea selectata nu este disponibila!";
}