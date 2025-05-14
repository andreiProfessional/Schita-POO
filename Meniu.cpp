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
    //hartaOras.afisareHartaLocatii();
    hartaOras.creareHartaRute();
    //hartaOras.afisareHartaRute();
}

void Meniu::adaugareJucator(const std::string &tip, const std::string &nume, const std::string &statie,
    const int &nivelViata, const int &nivelEnergie, const int &nivelNutritie, const int &nivelInteligenta, const int &nivelDistractie,
    const int &balantaBani, const int &balantaCalatorii) {
    if (tip == "ADMIN") {
        jucatori.emplace_back(new JucatorAdmin(tip, nume, statie,
            nivelViata, nivelEnergie, nivelNutritie, nivelInteligenta, nivelDistractie));
    }
    else if (tip == "STANDARD") {
        jucatori.emplace_back(new JucatorStandard(tip, nume, statie,
            nivelViata, nivelEnergie, nivelNutritie, nivelInteligenta, nivelDistractie,
            balantaBani, balantaCalatorii));
    }
    else {
        std::cout << "Nu exista acest tip de jucator!!!" << std::endl;
    }
}

void Meniu::creareListeJucatori() {
    std::ifstream in("jucatori.csv");
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

        adaugareJucator(INPUT_TIP, INPUT_NUME, INPUT_STATIE,
            INPUT_NIVEL_VIATA, INPUT_NIVEL_ENERGIE, INPUT_NIVEL_NUTRITIE, INPUT_NIVEL_INTELIGENTA, INPUT_NIVEL_DISTRACTIE,
            INPUT_BALANTA_BANI, INPUT_BALANTA_CALATORII);
    }

    in.close();
}
/*
void Meniu::afisareJucator(const int &idJucator) {
    gasireJucator(id)->afisareJucator();
}
*/
void Meniu::afisareListeJucatori() {
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

/*
void Meniu::interactiuneJucatorLocatie(Jucator *jucator, Locatie *locatie) {
    locatie->aplicaCoeficienti(jucator);
}
*/

void Meniu::meniuInceput() {
    golireEcran();
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
    this->creareListeJucatori();
    this->afisareListeJucatori();
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
    std::string nume;
    std::getline(std::cin, nume);
    std::cout << "Statia: ";
    std::string statie;
    std::getline(std::cin, statie);

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