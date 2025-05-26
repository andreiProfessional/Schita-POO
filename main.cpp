#include <iostream>

#include "Exceptii.h"
#include "Inventar.h"

int main() {
    Statie *s1 = new Statie("Piata Romana", {"M2"});
    Statie *s2 = new Statie("Piata Unirii", {"M1", "M2", "104"});
    Statie *s3 = new Statie("Piata Victoriei", {"M1", "M2"});
    // std::cout << *s1;
    // std::cout << *s2;
    // std::cout << *s3;

    Locatie *l1 = new Locatie("McDonald's", -20, 15, -25, s1);
    Locatie *l2 = new Locatie("Starbucks", -10, 5, -20, s1);
    Locatie *l3 = new Locatie("JOB", -1, -1, -175, s1);
    // std::cout << *l1 << std::endl;
    // std::cout << *l2 << std::endl;
    // std::cout << *l3 << std::endl;

    // Jucator *j1 = JucatorFactory::tataBogat("Charles");
    // Jucator *j2 = JucatorFactory::tataSarac("Vasile");
    // Jucator *j3 = JucatorFactory::magnatBatran("Klaus");
    // Jucator *j4 = JucatorFactory::omDeRand("John Pork");
    Jucator *j5 = JucatorFactory::pierdeVara("Bula");
    // Jucator *j6 = new Jucator("J66", 70, 80, 100, l1, s1);
    // Jucator *j7 = new Jucator("J7", 70, 80, 100, l2, s1);
    // std::cout << *j1 << std::endl;
    // std::cout << *j2 << std::endl;
    // *j2 += *j1;
    // std::cout << *j1 << std::endl;
    // std::cout << *j2 << std::endl;
    // std::cout << (*j6 > *j7) << std::endl << std::endl;

    Activitate *a1 = new SpawnLocatie(j5, {l1, l2, l3});
    a1->afisare();
    a1->activitate(3);
    // std::cout << *j1 << std::endl;
    // std::unordered_map<Statie*, std::vector<Statie*>> listaAdiacentaStatii;
    // listaAdiacentaStatii[s1] = {s2, s3};
    // listaAdiacentaStatii[s2] = {s1};
    // listaAdiacentaStatii[s3] = {s1};
    // Activitate *a2 = new SpawnStatie(j2, listaAdiacentaStatii);
    // a2->afisare();
    // a2->activitate(3);
    // std::cout << *j2 << std::endl;
    Activitate *a3 = new ActivitateLocatie(j5,
        {{"Suculetz de portocale", 1}, {"Happy meal", 4}, {"Meniu Big Mac", 1}});
    // try {
    //     a3->afisare(); std::cout << std::endl;
    //     a3->activitate(1);
    //     std::cout << *j3 << std::endl;
    //     a3->activitate(1);
    //     std::cout << *j3 << std::endl;
    // } catch (const InsuficientaViata &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }
    // try {
    //     a3->afisare(); std::cout << std::endl;
    //     a3->activitate(1);
    //     std::cout << *j5 << std::endl;
    //     a3->activitate(1);
    //     std::cout << *j5 << std::endl;
    // } catch (const InsuficientaHrana &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }
    // try {
    //     a3->afisare(); std::cout << std::endl;
    //     a3->activitate(3);
    //     std::cout << *j5 << std::endl;
    //     a3->activitate(3);
    //     std::cout << *j5 << std::endl;
    // } catch (const InsuficientaBani &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }
    // Activitate *a4 = new ActivitateStatie(j2, listaAdiacentaStatii);
    // a4->afisare();
    // a4->activitate(2); std::cout << std::endl;
    // std::cout << *j2 << std::endl;
    // Activitate *a5 = new ActivitateTaxi(j1, {l1, l2, l3});
    // a5->afisare();
    // a5->activitate(3);
    // std::cout << *j1 << std::endl;
    // Activitate *a6 = new LocatieCatreStatie(j1);
    // a6->afisare();
    // a6->activitate(1);
    // std::cout << *j1 << std::endl;
    // Activitate *a7 = new StatieCatreLocatie(j2, {l1, l2, l3});
    // a7->afisare();
    // a7->activitate(2);
    // std::cout << *j2 << std::endl;

    // Inventar &inventar = Inventar::acceseazaSingleton();
    // inventar.adaugareJucator(j1);
    // inventar.adaugareJucator(j2);
    // inventar.adaugareJucator(j3);
    // inventar.adaugareJucator(j4);
    // inventar.adaugareJucator(j5);
    // inventar.adaugareJucator(j6);
    // inventar.adaugareJucator(j7);
    // inventar.sortareJucatori();
    // inventar.afisareJucatori();

    // inventar.adaugareLocatie(l1);
    // inventar.adaugareLocatie(l2);
    // // inventar.afisareLocatii();
    // inventar.adaugareMuchieStatii(s1, s2, "M2");
    // inventar.adaugareMuchieStatii(s2, s3, "M1");
    // //inventar.afisareStatii();

    {
        // delete j1;
        // delete j2;
        delete l1;
        delete l2;
        delete l3;
        delete s1;
        delete s2;
        delete s3;
        //delete a1;
        //delete a2;
        // delete a3;
        // delete a4;
        // delete a5;
        // delete a6;
        //delete a7;
    } // deletes

    return 0;
}