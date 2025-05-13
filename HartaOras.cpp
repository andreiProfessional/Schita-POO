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

void HartaOras::adaugareStatie(const std::string &tip, const std::string &linie, const std::string &nume, const std::string &predecesor, const std::string &succesor) {
    if (tip == "AUTOBUZ") {
        statii.emplace_back(new StatieAutobuz(tip, linie, nume, predecesor, succesor));
    }
    else if (tip == "TROLEIBUZ") {
        statii.emplace_back(new StatieTroleibuz(tip, linie, nume, predecesor, succesor));
    }
    else if (tip == "TRAMVAI") {
        statii.emplace_back(new StatieTramvai(tip, linie, nume, predecesor, succesor));
    }
    else if (tip == "METROU") {
        statii.emplace_back(new StatieMetrou(tip, linie, nume, predecesor, succesor));
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

void HartaOras::afisareStatie(const int &ID) {
    gasireStatie(ID)->afisareStatie();
}

void HartaOras::afisareHartaStatii() {
    for (auto const &statie: statii) {
        statie->afisareStatie();
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

void HartaOras::afisareLocatie(const int &ID) {
    gasireLocatie(ID)->afisareLocatie();
}

void HartaOras::afisareHartaLocatii() {
    for (const auto &locatie: locatii) {
        locatie->afisareLocatie();
    }
    std::cout << std::endl;
}

void HartaOras::adaugareUtilizator(const std::string &tip, const std::string &nume, const std::string &statie,
    const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie,
    const int &balantaBani, const int &balantaCalatorii) {
    if (tip == "ADMIN") {
        utilizatori.emplace_back(new UtilizatorAdmin(tip, nume, statie,
            nivelViata, nivelEnergie, nivelNutritie, nivelInteligenta, nivelDistractie));
    }
    else if (tip == "STANDARD") {
        utilizatori.emplace_back(new UtilizatorStandard(tip, nume, statie,
            nivelViata, nivelEnergie, nivelNutritie, nivelInteligenta, nivelDistractie,
            balantaBani, balantaCalatorii));
    }
    else {
        std::cout << "Nu exista acest tip de utilizator!!!" << std::endl;
    }
}

void HartaOras::creareListeUtilizatori() {
    std::ifstream in("utilizatori.csv");
    std::string input;

    std::getline(in, input);
    while (std::getline(in, input)) {
        const std::string INPUT_TIP = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string INPUT_NUME = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string INPUT_STATIE = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_NIVEL_VIATA = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_NIVEL_ENERGIE = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_NIVEL_NUTRITIE = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_NIVEL_INTELIGENTA = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_NIVEL_DISTRACTIE = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_BALANTA_BANI = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int INPUT_BALANTA_CALATORII = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        adaugareUtilizator(INPUT_TIP, INPUT_NUME, INPUT_STATIE,
            INPUT_NIVEL_VIATA, INPUT_NIVEL_ENERGIE, INPUT_NIVEL_NUTRITIE, INPUT_NIVEL_INTELIGENTA, INPUT_NIVEL_DISTRACTIE,
            INPUT_BALANTA_BANI, INPUT_BALANTA_CALATORII);
    }

    in.close();
}

void HartaOras::afisareUtilizator(const int &ID) {
    gasireUtilizator(ID)->afisareUtilizator();
}

void HartaOras::afisareListeUtilizatori() {
    for (const auto &utilizator: utilizatori) {
        utilizator->afisareUtilizator();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Statie* HartaOras::gasireStatie(const int &idStatie) {
    for (auto &statie: statii) {
        if (statie->verificareId(idStatie)) {
            return statie;
        }
    }
    return nullptr;
}

Utilizator* HartaOras::gasireUtilizator(const int &idUtilizator) {
    for (const auto &utilizator: utilizatori) {
        if (utilizator->verificareId(idUtilizator)) {
            return utilizator;
        }
    }
    return nullptr;
}

Locatie* HartaOras::gasireLocatie(const int &idLocatie) {
    for (auto &locatie: locatii) {
        if (locatie->verificareId(idLocatie)) {
            return locatie;
        }
    }
    return nullptr;
}

void HartaOras::interactiuneUtilizatorLocatie(Utilizator *utilizator, Locatie *locatie) {
    locatie->aplicaCoeficienti(utilizator);
}

