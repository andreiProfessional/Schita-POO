#include "HartaOras.h"
#include <fstream>
#include <iostream>
#include <string>

HartaOras::HartaOras() {
    std::cout << std::endl << "GOD MESSAGE: A FOST CREAT ORASUL!" << std::endl << std::endl;
}

HartaOras::~HartaOras() {
    std::cout << std::endl << "GOD MESSAGE: A FOST DISTRUS ORASUL!" << std::endl;
}

void HartaOras::adaugareStatie(const std::string tip, const std::string linie, const std::string nume, const std::string predecesor, const std::string succesor) {
    if (tip == "AUTOBUZ") {
        Statie *statieNoua = new StatieAutobuz(nume, tip, linie, predecesor, succesor);
        statiiAutobuz.emplace_back(static_cast<StatieAutobuz*>(statieNoua));
    }
    else if (tip == "TROLEIBUZ") {
        Statie *statieNoua = new StatieTroleibuz(nume, tip, linie, predecesor, succesor);
        statiiTroleibuz.emplace_back(static_cast<StatieTroleibuz*>(statieNoua));
    }
    else if (tip == "TRAMVAI") {
        Statie *statieNoua = new StatieTramvai(nume, tip, linie, predecesor, succesor);
        statiiTramvai.emplace_back(static_cast<StatieTramvai*>(statieNoua));
    }
    else if (tip == "METROU") {
        Statie *statieNoua = new StatieMetrou(nume, tip, linie, predecesor, succesor);
        statiiMetrou.emplace_back(static_cast<StatieMetrou*>(statieNoua));
    }
    else {
        std::cout << "Nu exista acest tip de statie!!!" << std::endl;
    }
}

void HartaOras::creareHartaStatii() {
    std::ifstream in("statii.csv");
    std::string input;

    std::getline(in, input);
    while (std::getline(in, input)) {
        const std::string INPUT_TIP = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string INPUT_LINIE = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string INPUT_NUME = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string INPUT_PREDECESOR = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string INPUT_SUCCESOR = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        adaugareStatie(INPUT_TIP, INPUT_LINIE, INPUT_NUME, INPUT_PREDECESOR, INPUT_SUCCESOR);
    }

    in.close();
}

void HartaOras::afisareHartaStatii() {
    for (auto const &statie: statiiAutobuz) {
        statie->afisareStatie();
    }
    std::cout << std::endl;
    for (auto const &statie: statiiTroleibuz) {
        statie->afisareStatie();
    }
    std::cout << std::endl;
    for (auto const &statie: statiiTramvai) {
        statie->afisareStatie();
    }
    std::cout << std::endl;
    for (auto const &statie: statiiMetrou) {
        statie->afisareStatie();
    }
    std::cout << std::endl;
}

void HartaOras::adaugareLocatie(const std::string tip, const std::string nume, const std::string statieApropiata, int coeficientOdihna, int coeficientDistractie, int coeficientViata) {
    if (tip == "RESEDINTA") {
        Locatie *locatieNoua = new LocatieResedinta(nume, statieApropiata, coeficientOdihna, coeficientDistractie, coeficientViata);
        locatiiResedinta.emplace_back(static_cast<LocatieResedinta*>(locatieNoua));
    }
    else if (tip == "EDUCATIE") {
        Locatie *locatieNoua = new LocatieEducatie(nume, statieApropiata, coeficientOdihna, coeficientDistractie, coeficientViata);
        locatiiEducatie.emplace_back(static_cast<LocatieEducatie*>(locatieNoua));
    }
    else if (tip == "MUNCA") {
        Locatie *locatieNoua = new LocatieMunca(nume, statieApropiata, coeficientOdihna, coeficientDistractie, coeficientViata);
        locatiiMunca.emplace_back(static_cast<LocatieMunca*>(locatieNoua));
    }
    else if (tip == "RELAXARE") {
        Locatie *locatieNoua = new LocatieRelaxare(nume, statieApropiata, coeficientOdihna, coeficientDistractie, coeficientViata);
        locatiiRelaxare.emplace_back(static_cast<LocatieRelaxare*>(locatieNoua));
    }
    else if (tip == "INSTITUTIE") {
        Locatie *locatieNoua = new LocatieInstitutie(nume, statieApropiata, coeficientOdihna, coeficientDistractie, coeficientViata);
        locatiiInstitutie.emplace_back(static_cast<LocatieInstitutie*>(locatieNoua));
    }
    else {
        std::cout << "Nu exista acest tip de locatie!!!" << std::endl;
    }
}

void HartaOras::creareHartaLocatii() {
    std::ifstream in("locatii.csv");
    std::string input;

    std::getline(in, input);
    while (std::getline(in, input)) {
        const std::string INPUT_TIP = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string INPUT_NUME = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string INPUT_STATIE_APROPIATA = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_COEFICIENT_ODIHNA = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_COEFICIENT_DISTRACTIE = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_COEFICIENT_VIATA = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        adaugareLocatie(INPUT_TIP, INPUT_NUME, INPUT_STATIE_APROPIATA, INPUT_COEFICIENT_ODIHNA, INPUT_COEFICIENT_DISTRACTIE, INPUT_COEFICIENT_VIATA);
    }

    in.close();
}

void HartaOras::afisareHartaLocatii() {
    std::cout << "LOCATIILE DE RESEDINTA:" << std::endl;
    for (auto const &locatie: locatiiResedinta) {
        locatie->afisareLocatie();
    }
    std::cout << std::endl;
    std::cout << "LOCATIILE DE EDUCATIE:" << std::endl;
    for (auto const &locatie: locatiiEducatie) {
        locatie->afisareLocatie();
    }
    std::cout << std::endl;
    std::cout << "LOCATIILE DE MUNCA:" << std::endl;
    for (auto const &locatie: locatiiMunca) {
        locatie->afisareLocatie();
    }
    std::cout << std::endl;
    std::cout << "LOCATIILE DE RELAXARE:" << std::endl;
    for (auto const &locatie: locatiiRelaxare) {
        locatie->afisareLocatie();
    }
    std::cout << std::endl;
    std::cout << "LOCATIILE DE INSTITUTIE:" << std::endl;
    for (auto const &locatie: locatiiInstitutie) {
        locatie->afisareLocatie();
    }
    std::cout << std::endl;
}