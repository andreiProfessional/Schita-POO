#include <iostream>
#include "Inventar.h"

int main() {
    Locatie *l1 = new Locatie("McDonald's", -20, 15, -25);
    Locatie *l2 = new Locatie("Starbucks", -10, 5, -20);
    Locatie *l3 = new Locatie("Luca Patiserie", -5, 10, -15);
    // l1->afisare();
    // l2->afisare();
    // l3->afisare();

    Statie *s1 = new Statie("Piata Romana", {});
    Statie *s2 = new Statie("Piata Unirii", {});
    Statie *s3 = new Statie("Eroilor", {});
    // s1->afisare();
    // s2->afisare();
    // s3->afisare();

    Jucator *j1 = JucatorFactory::tataBogat("Charles", l1, s1);
    Jucator *j2 = JucatorFactory::omDeRand("John Pork", l2, s2);
    // j1->afisare();
    // j2->afisare();

    Activitate *a1 = new ActivitateLocatie(j1,
        {{"Suculetz de portocale", 2}, {"Happy meal", 4}, {"Meniu Big Mac", 8}});
    a1->afisare(); std::cout << std::endl;
    a1->activitate(2); std::cout << std::endl;
    a1->afisare();
    // Activitate *a2 = new ActivitateTaxi(j2, {l1, l2, l3});
    // a2->afisare();
    // a2->activitate(1);
    // std::cout << std::endl;
    // a2->afisare();

    // Inventar &inventar = Inventar::acceseazaSingleton();
    // inventar.adaugareJucator(j1);
    // inventar.adaugareJucator(j2);
    // // inventar.afisareJucatori();
    // inventar.adaugareLocatie(l1);
    // inventar.adaugareLocatie(l2);
    // // inventar.afisareLocatii();
    // inventar.adaugareMuchieStatii(s1, s2, "M2");
    // inventar.adaugareMuchieStatii(s2, s3, "M1");
    // //inventar.afisareStatii();

    {
        delete j1;
        delete j2;
        delete l1;
        delete l2;
        delete l3;
        delete s1;
        delete s2;
        delete s3;
        delete a1;
        // delete a2;
    } // deletes

    return 0;
}