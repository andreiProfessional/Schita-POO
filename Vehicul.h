#ifndef VEHICUL_H
#define VEHICUL_H
#include <string>


class Vehicul {
protected:
    static int idContor;
    const int idVehicul;
    int consum;
    int capacitateMaximaPasageri;
public:
    Vehicul():idVehicul(idContor ++){}
    virtual void Calatorie() = 0;
    virtual void sunetMotor() = 0;
};

class VehiculRoti: public Vehicul {
protected:
    int capacitateMotor;
    std::string tipMotor;
public:
    void Calatorie() override;
    virtual void sunetRoti() = 0;
};

class Autobuz: public VehiculRoti {
protected:

public:
    void Calatorie() override;
    void sunetRoti() override;
};

class AutobuzFosil: public Autobuz {
private:

public:

};

class AutobuzElectric: public Autobuz {
private:

public:
    void sunetMotor() override;
};

class Troleibuz: public VehiculRoti {
private:

public:
    void Calatorie() override;
    void sunetRoti() override;
};

class VehiculSine: public Vehicul {
protected:
    int numarVagoane;
public:
    virtual void sunetSine() = 0;
};

class Tramvai: public VehiculSine {
private:

public:
    void Calatorie() override;
    void sunetSine() override;
};

class Metrou: public VehiculSine {
private:

public:
    void Calatorie() override;
    void sunetSine() override;
};


#endif