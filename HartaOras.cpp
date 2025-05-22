#include "HartaOras.h"
#include "Statie.h"
#include <fstream>
#include <iostream>
#include <string>

HartaOras::HartaOras() {std::cout << "Creare Harta" << std::endl << std::endl;}

HartaOras::~HartaOras() {std::cout << "Distrugere Harta" << std::endl << std::endl;}

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
        const std::string inputTip = input.substr(0, input.find(','));
        input = input.erase(0, input.find(',') + 1);

        const std::string inputNume = input.substr(0, input.find(','));
        input = input.erase(0, input.find(',') + 1);

        std::vector<std::string> inputListaStatii;
        while (input.find(';') != std::string::npos) {
            inputListaStatii.push_back(input.substr(0, input.find(';')));
            input = input.erase(0, input.find(';') + 1);
        }
        inputListaStatii.push_back(input);

        adaugareRuta(inputTip, inputNume, inputListaStatii);
    }

    in.close();
}

/*void HartaOras::afisareStatie(const int &ID) {
    gasireStatie(ID)->afisareStatie();
}*/

void HartaOras::afisareHartaRute() const {
    for (auto const &ruta: rute) {
        ruta->afisareRuta();
    }
    std::cout << std::endl;
}
/*
std::vector <std::pair<Ruta*, int>> HartaOras::gasireStatieDupaNume(const std::string &numeStatie) {
    std::vector<std::pair<Ruta*, int>> listaStatii;
    int numarRute = rute.size();
    for (int indice = 0; indice < numarRute; indice ++) {
        Statie *statieNoua = rute[indice]->gasireStatie(numeStatie);
        if (statieNoua != nullptr) {
            listaStatii.push_back(std::make_pair(rute[indice], indice));
        }
    }
    std::cout << "JASFKAJKJDSKJ" << std::endl;
    for (auto &statie: listaStatii) {
        statie.first->afisareStatie(statie.second);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return listaStatii;
}
*/
void HartaOras::adaugareLocatie(const std::string &tip, const std::string &nume, const std::string &statie,
    const std::vector<int> &coeficienti) {
        if (tip == "RESEDINTA") {
            Locatie *locatieNoua = new LocatieResedinta(nume, statie, coeficienti[0]);
            locatii.push_back(locatieNoua);
        }
        else if (tip == "SPORT") {
            Locatie *locatieNoua = new LocatieSport(nume, statie, coeficienti[0], coeficienti[1], coeficienti[2], coeficienti[3]);
            locatii.push_back(locatieNoua);
        }
        else if (tip == "MEDICALA") {
            Locatie *locatieNoua = new LocatieMedicala(nume, statie, coeficienti[0], coeficienti[1]);
            locatii.push_back(locatieNoua);
        }
        else if (tip == "MUNCA") {
            Locatie *locatieNoua = new LocatieMunca(nume, statie, coeficienti[0], coeficienti[1], coeficienti[2]);
            locatii.push_back(locatieNoua);
        }
        else if (tip == "HORECA") {
            Locatie *locatieNoua = new LocatieHoreca(nume, statie, coeficienti[0], coeficienti[1]);
            locatii.push_back(locatieNoua);
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
        const std::string inputTip = input.substr(0, input.find(','));
        input = input.erase(0, input.find(',') + 1);

        const std::string inputNume = input.substr(0, input.find(','));
        input = input.erase(0, input.find(',') + 1);

        const std::string inputStatie = input.substr(0, input.find(','));
        input = input.erase(0, input.find(',') + 1);

        std::string inputCoeficienti = input.substr(0, input.find(','));
        std::vector<int> coeficienti;
        while (inputCoeficienti.find(';') != std::string::npos) {
            coeficienti.push_back(std::stoi(inputCoeficienti.substr(0, inputCoeficienti.find(';'))));
            inputCoeficienti = inputCoeficienti.erase(0, inputCoeficienti.find(';') + 1);
        }
        coeficienti.push_back(std::stoi(inputCoeficienti));
        input = input.erase(0, input.find(',') + 1);

        adaugareLocatie(inputTip, inputNume, inputStatie, coeficienti);
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

Locatie* HartaOras::gasireLocatieDupaNume(const std::string &numeLocatie) {
    for (const auto &locatie: locatii) {
        if (locatie->verificareNume(numeLocatie)) {
            return locatie;
        }
    }
    return nullptr;
}

std::vector<std::pair<Ruta*, int>> HartaOras::gasireStatii(const std::string &numeStatieCurenta) {
    std::vector<std::pair<Ruta*, int>> listaStatii;
    unsigned int numarRute = rute.size();
    for (unsigned indice = 0; indice < numarRute; indice ++) {
        std::pair<Ruta*, int> statieNoua = rute[indice]->gasireStatie(numeStatieCurenta);
        if (statieNoua.first != nullptr) {
            listaStatii.push_back(statieNoua);
        }
    }
    return listaStatii;
}

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


