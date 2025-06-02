#ifndef MENIU_H
#define MENIU_H
#include "Inventar.h"

class Meniu {
private:
    Meniu();
    ~Meniu();

    Inventar &inventar;
public:
    Meniu(const Meniu&) = delete;
    Meniu& operator=(const Meniu&) = delete;
    static Meniu& acceseazaSingleton() {
        static Meniu instanta;
        return instanta;
    }

    void afisareInventar() const;

    void creareActivitate(const int& idJucator, const int& tipActivitate, const int& alegerea);

    void run();
};

#endif
