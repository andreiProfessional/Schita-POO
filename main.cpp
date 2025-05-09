#include <iostream>
#include "HartaOras.h"
#include "Utilizator.h"

int main() {
    HartaOras &HO = HartaOras::acceseazaSingleton();

    HO.creareHartaStatii();
    //HO.afisareHartaStatii();
    HO.creareHartaLocatii();
    //HO.afisareHartaLocatii();

    UtilizatorAdmin User1("Nik");
    User1.initializareUtilizator();
    User1.afisareUtilizator();
    std::cout << std::endl;
    UtilizatorStandard User2("Andrei");
    User2.initializareUtilizator();
    User2.afisareUtilizator();
    std::cout << std::endl;
    UtilizatorStandard User3("Maria");
    User3.initializareUtilizator();
    User3.afisareUtilizator();


    return 0;
}

// TODO: Creare Caractere
// TODO: Calculare moarte (+ motivul!!!) -> Meniu
// TODO: Interactiune caracter cu Harta -> Meniu
// TODO: Operator Overload -> De vazut ce operatori si de unde (Eventual '<<' pentru afisarea statisticilor utilizatorilor)
// TODO: etccccc
