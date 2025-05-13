#include "HartaOras.h"
#include "Statie.h"
#include <fstream>
#include <iostream>
#include <string>

HartaOras::HartaOras() {}

HartaOras::~HartaOras() {}

void HartaOras::adaugareRuta(const std::string &tip, const std::string &nume, const std::vector<std::string> &listaStatii) {
    if (tip == "AUTOBUZ") {
        std::vector<Statie*> statii;
        for (const auto &statie: listaStatii) {
            statii.emplace_back(new StatieAutobuz(statie));
        }
        rute.emplace_back(new RutaAutobuz(nume, statii));
    }
    else if (tip == "TROLEIBUZ") {
        std::vector<Statie*> statii;
        for (const auto &statie: listaStatii) {
            statii.emplace_back(new StatieTroleibuz(statie));
        }
        rute.emplace_back(new RutaTroleibuz(nume, statii));
    }
    else if (tip == "TRAMVAI") {
        std::vector<Statie*> statii;
        for (const auto &statie: listaStatii) {
            statii.emplace_back(new StatieTramvai(statie));
        }
        rute.emplace_back(new RutaTramvai(nume, statii));
    }
    else if (tip == "METROU") {
        std::vector<Statie*> statii;
        for (const auto &statie: listaStatii) {
            statii.emplace_back(new StatieMetrou(statie));
        }
        rute.emplace_back(new RutaMetrou(nume, statii));
    }
    else {
        std::cout << "Nu exista acest tip de statie!!!" << std::endl;
    }
}

void HartaOras::creareHartaRute() {
    std::ifstream in("rute.csv");
    std::string input;

    std::getline(in, input);
    while (std::getline(in, input)) {
        const std::string inputTip = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string inputNume = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        std::vector<std::string> inputListaStatii;
        while (input.find(";") != std::string::npos) {
            inputListaStatii.push_back(input.substr(0, input.find(";")));
            input = input.erase(0, input.find(";") + 1);
        }
        inputListaStatii.push_back(input);

        adaugareRuta(inputTip, inputNume, inputListaStatii);
    }

    in.close();
}

/*void HartaOras::afisareStatie(const int &ID) {
    gasireStatie(ID)->afisareStatie();
}*/

void HartaOras::afisareHartaRute() {
    for (auto const &ruta: rute) {
        ruta->afisareRuta();
    }
    std::cout << std::endl;
}

void HartaOras::adaugareLocatie(const std::string &tip, const std::string &nume, const std::string &statie, const std::vector<int> &coeficienti) {
    if (tip == "RESEDINTA") {
        locatii.emplace_back(new LocatieResedinta(tip, nume, statie,
            coeficienti[0], coeficienti[1], coeficienti[2]));
    }
    else if (tip == "MEDICALA") {
        locatii.emplace_back(new LocatieMedicala(tip, nume, statie,
            coeficienti[0], coeficienti[1], coeficienti[2], coeficienti[3]));
    }
    else if (tip == "EDUCATIE") {
        locatii.emplace_back(new LocatieEducatie(tip, nume, statie,
            coeficienti[0], coeficienti[1], coeficienti[2], coeficienti[3]));
    }
    else if (tip == "MUNCA") {
        locatii.emplace_back(new LocatieMunca(tip, nume, statie,
            coeficienti[0], coeficienti[1], coeficienti[2], coeficienti[3]));
    }
    else if (tip == "HORECA") {
        locatii.emplace_back(new LocatieHoreca(tip, nume, statie,
            coeficienti[0], coeficienti[1], coeficienti[2]));
    }
    else if (tip == "RELAXARE") {
        locatii.emplace_back(new LocatieRelaxare(tip, nume, statie,
            coeficienti[0], coeficienti[1], coeficienti[2]));
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

        const std::string INPUT_STATIE = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        std::string inputCoeficienti = input.substr(0, input.find(","));
        std::vector<int> coeficienti;
        while (inputCoeficienti.find(";") != std::string::npos) {
            coeficienti.push_back(std::stoi(inputCoeficienti.substr(0, inputCoeficienti.find(";"))));
            inputCoeficienti = inputCoeficienti.erase(0, inputCoeficienti.find(";") + 1);
        }
        coeficienti.push_back(std::stoi(inputCoeficienti));
        input = input.erase(0, input.find(",") + 1);

        adaugareLocatie(INPUT_TIP, INPUT_NUME, INPUT_STATIE, coeficienti);
    }

    in.close();
}

/*void HartaOras::afisareLocatie(const int &ID) {
    gasireLocatie(ID)->afisareLocatie();
}*/

void HartaOras::afisareHartaLocatii() {
    for (const auto &locatie: locatii) {
        locatie->afisareLocatie();
    }
    std::cout << std::endl;
}

/*
Statie* HartaOras::gasireStatie(const int &idStatie) {
    for (auto &statie: statii) {
        if (statie->verificareId(idStatie)) {
            return statie;
        }
    }
    return nullptr;
}
*/

/*
Locatie* HartaOras::gasireLocatie(const int &idLocatie) {
    for (auto &locatie: locatii) {
        if (locatie->verificareId(idLocatie)) {
            return locatie;
        }
    }
    return nullptr;
}
*/


