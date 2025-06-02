#include "Activitate.h"
#include "../Jucator/Jucator.h"

int Activitate::contorID = 0;

Activitate::Activitate(Jucator *jucator_): id(++ contorID), jucator(jucator_) {}

Activitate::Activitate(const Activitate &activitate):
    id(++ contorID),
    jucator(activitate.jucator) {}

Activitate& Activitate::operator=(const Activitate &activitate) {
    this->jucator = activitate.jucator;
    return *this;
}

