#include <iostream>
#include "HartaOras.h"
#include "Meniu.h"
#include "Jucator.h"

int main() {
    //HartaOras &HO = HartaOras::acceseazaSingleton();

    //HO.creareHartaRute();
    //HO.afisareHartaRute();
    //HO.creareHartaLocatii();
    //HO.afisareHartaLocatii();
    //HO.creareListeUtilizatori();
    //HO.afisareListeUtilizatori();

    //HO.afisareStatie(32);
    //HO.afisareLocatie(15);
    //HO.afisareUtilizator(3);

    //HO.interactiuneUtilizatorLocatie(HO.gasireUtilizator(2), HO.gasireLocatie(3));
    //HO.afisareListeUtilizatori();


    Meniu &Meniu = Meniu::acceseazaSingleton();
    Meniu.creareListeJucatori();
    Meniu.afisareListeJucatori();
    Meniu.afisareJucator(5);

    return 0;
}