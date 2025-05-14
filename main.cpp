#include <iostream>
#include "HartaOras.h"
#include "Meniu.h"
#include "Jucator.h"

int main() {
    Meniu &Meniu = Meniu::acceseazaSingleton();
    //Meniu.creareListeJucatori();
    //Meniu.afisareListeJucatori();
    //Meniu.afisareJucator(1);
    //Meniu.creareHartaOras();

    Meniu.meniuInceput();

    //Meniu.interactiuneJucatorLocatie(Meniu.gasireUtilizator(2), Meniu.gasireLocatie(3));

    return 0;
}