#ifndef VEHICUL_H
#define VEHICUL_H
#include "Ruta.h"
#include "Statie.h"


class Vehicul {
protected:
    static int idContor;
    const int idVehicul;
    Ruta* ruta;
    Statie* statieCurenta;
public:
    Vehicul():idVehicul(idContor ++){}

};


class Autobuz: public Vehicul {
private:

public:

};

class Troleibuz: public Vehicul {
private:

public:

};

class Tramvai: public Vehicul {
private:

public:

};

class Metrou: public Vehicul {
private:

public:

};


#endif