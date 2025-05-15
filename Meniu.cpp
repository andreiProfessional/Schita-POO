#include "Meniu.h"
#include <iostream>
#include <fstream>

Meniu::Meniu(): hartaOras(HartaOras::acceseazaSingleton()) {}

Meniu::~Meniu() {}

void Meniu::golireEcran() {
    system("clear");
}

void Meniu::creareHartaOras() {
    hartaOras.creareHartaLocatii();
    hartaOras.creareHartaRute();
}

void Meniu::creareListaJucatori() {
    std::ifstream in("jucatori.csv");
    std::string input;

    std::getline(in, input);
    while (std::getline(in, input)) {
        const std::string inputNume = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const std::string inputLocatieResedinta = input.substr(0, input.find(","));
        input = input.erase(0, input.find(",") + 1);

        const int inputBalantaBani = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int inputNivelViata = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int inputNivelEnergie = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        const int inputNivelNutritie = std::stoi(input.substr(0, input.find(",")));
        input = input.erase(0, input.find(",") + 1);

        Locatie *locatieNoua = this->gasireLocatieDupaNume(inputLocatieResedinta);
        Jucator *jucatorNou = new Jucator(inputNume,
            locatieNoua, nullptr,
            inputBalantaBani, inputNivelViata, inputNivelEnergie, inputNivelNutritie);
        jucatori.push_back(jucatorNou);
    }

    in.close();
}
/*
void Meniu::afisareJucator(const int &idJucator) {
    gasireJucator(id)->afisareJucator();
}
*/
void Meniu::afisareListaJucatori() {
    for (const auto &jucator: jucatori) {
        jucator->afisareJucator();
        std::cout << std::endl;
    }
}

Jucator* Meniu::gasireJucator(const int &idJucator) {
    for (const auto &jucator: jucatori) {
        if (jucator->verificareId(idJucator)) {
            return jucator;
        }
    }
    return nullptr;
}

Locatie* Meniu::gasireLocatieDupaNume(const std::string &numeLocatie) {
    return hartaOras.gasireLocatieDupaNume(numeLocatie);
}

Statie* Meniu::gasireStatieDupaLocatie(Locatie *locatie) {
    return locatie->gasireStatie();
}

void Meniu::meniuInceput() {
    golireEcran();
    this->creareHartaOras();
    this->creareListaJucatori();
    std::cout << "Bine ai venit in \"MICUL ORASEL\"!" << std::endl << std::endl;
    std::cout << "1. Selecteaza jucator vechi" << std::endl;
    std::cout << "2. Creeaza jucator nou" << std::endl;
    std::cout << "0. Pleaca acasa" << std::endl;
    std::cout << std::endl << "Alegerea ta: ";
    int optiune;
    std::cin >> optiune;
    switch (optiune) {
        case 1:
            meniuJucatorVechi();
            break;
        case 2:
            meniuJucatorNou();
            break;
        case 0:
            meniuSfarsit();
            break;
        default:
            meniuInceput();
            break;
        }
}

void Meniu::meniuSfarsit() {
    golireEcran();
    std::cout << "Incheierea programului..." << std::endl;
}

void Meniu::meniuJucatorVechi() {
    golireEcran();
    std::cout << "Jucatori disponibili: " << std::endl << std::endl;
    this->afisareListaJucatori();
    std::cout << "Alegerea ta: ";
    int optiune;
    std::cin >> optiune;
    this->jucatorCurent = this->gasireJucator(optiune);
    meniuStartJoc();
}

void Meniu::meniuJucatorNou() {
    golireEcran();
    std::cin.ignore();
    std::cout << "Hai sa creem un jucator nou!" << std::endl << std::endl;
    std::cout << "Nume: ";
    std::string inputNume;
    std::getline(std::cin, inputNume);
    std::cout << std::endl;

    std::cout << "Locatie Resedinta ";
    std::string inputStatie;
    std::getline(std::cin, inputStatie);

    //Jucator* jucatorNou = new Jucator(inputNume, inputStatie);
    //jucatori.push_back(jucatorNou);
    //jucatorCurent = jucatorNou;
}

void Meniu::meniuStartJoc() {
    golireEcran();
    jucatorCurent->afisareJucator();
    std::cout << std::endl << std::endl;
    std::cout << "1. Incepe jocul" << std::endl;
    std::cout << "0. Inapoi la Meniul de Inceput" << std::endl;
    std::cout << std::endl << "Alegerea ta: ";
    int optiune;
    std::cin >> optiune;
    switch (optiune) {
        case 1:
            std::cout << "JOCUL A INCEPUT!" << std::endl;
            break;
        case 0:
            meniuInceput();
            break;
        default:
            meniuStartJoc();
            break;
    }
}