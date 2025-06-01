#include <iostream>
#include <fstream>
#include "Exceptii.h"
#include "Inventar.h"
#include "Meniu.h"

int main() {

    // Jucator *j1 = JucatorFactory::tataBogat("Charles");
    // Jucator *j2 = JucatorFactory::tataSarac("Vasile");
    // Jucator *j3 = JucatorFactory::magnatBatran("Klaus");
    // Jucator *j4 = JucatorFactory::omDeRand("John Pork");
    // Jucator *j5 = JucatorFactory::pierdeVara("Bula");

    // Activitate *a1 = new SpawnLocatie(j1, {l1, l2, l3});
    // try {
    //     a1->afisare();
    //     a1->activitate(2);
    // } catch (const OptiuneIndisponibila &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }
    // std::cout << *j1 << std::endl;
    // std::unordered_map<Statie*, std::vector<Statie*>> listaAdiacentaStatii;
    // listaAdiacentaStatii[s1] = {s2, s3};
    // listaAdiacentaStatii[s2] = {s1};
    // listaAdiacentaStatii[s3] = {s1};
    // Activitate *a2 = new SpawnStatie(j1, listaAdiacentaStatii);
    // try {
    //     a2->afisare();
    //     a2->activitate(3);
    //     std::cout << *j1 << std::endl;
    // } catch (const OptiuneIndisponibila &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }
    // Activitate *a3 = new ActivitateLocatie(j1,
    //     {{"Suculetz de portocale", 1}, {"Happy meal", 4}, {"Meniu Big Mac", 1}});
    // try {
    //     a3->afisare(); std::cout << std::endl;
    //     a3->activitate(3);
    //     std::cout << *j1 << std::endl;
    //     a3->activitate(3);
    //     std::cout << *j1 << std::endl;
    // } catch (const InsuficientaViata &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // } catch (const InsuficientaHrana &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // } catch (const InsuficientaBani &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // } catch (const OptiuneIndisponibila &exceptie) {
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
    // Activitate *a4 = new ActivitateStatie(j1, listaAdiacentaStatii);
    // try {
    //     a4->afisare();
    //     a4->activitate(2);
    //     std::cout << std::endl;
    //     std::cout << *j1 << std::endl;
    // } catch (const OptiuneIndisponibila &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }
    // Activitate *a5 = new ActivitateTaxi(j1, {l1, l2, l3});
    // try {
    //     a5->afisare();
    //     a5->activitate(-1);
    //     std::cout << *j1 << std::endl;
    // } catch (const OptiuneIndisponibila &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }
    // Activitate *a6 = new LocatieCatreStatie(j1);
    // try {
    //     a6->afisare();
    //     a6->activitate(-1);
    //     std::cout << *j1 << std::endl;
    // } catch (const OptiuneIndisponibila &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }
    // Activitate *a7 = new StatieCatreLocatie(j1, {l1, l2, l3});
    // try {
    //     a7->afisare();
    //     a7->activitate(3);
    //     std::cout << *j1 << std::endl;
    // } catch (const OptiuneIndisponibila &exceptie) {
    //     std::cout << exceptie.what() << std::endl;
    // }

    Meniu &meniu = Meniu::acceseazaSingleton();
    meniu.run();


    /*{
        delete j1;
        delete j2;
        delete j3;
        delete j4;
        delete j5;
        delete j6;
        delete j7;
        delete l1;
        delete l2;
        delete l3;
        delete s1;
        delete s2;
        delete s3;
        delete a1;
        delete a2;
        delete a3;
        delete a4;
        delete a5;
        delete a6;
        delete a7;
    }*/ // deletes

    return 0;
}
