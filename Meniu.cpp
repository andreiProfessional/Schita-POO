#include "Meniu.h"
#include <iostream>
#include <fstream>

Meniu::Meniu(): hartaOras(HartaOras::acceseazaSingleton()) {}

Meniu::~Meniu() {}


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

        adaugareJucator(INPUT_TIP, INPUT_NUME, INPUT_STATIE,
            INPUT_NIVEL_VIATA, INPUT_NIVEL_ENERGIE, INPUT_NIVEL_NUTRITIE, INPUT_NIVEL_INTELIGENTA, INPUT_NIVEL_DISTRACTIE,
            INPUT_BALANTA_BANI, INPUT_BALANTA_CALATORII);
    }

    in.close();
}

void Meniu::afisareJucator(const int &ID) {
    gasireJucator(ID)->afisareJucator();
}

void Meniu::afisareListeJucatori() {
    for (const auto &jucator: jucatori) {
        jucator->afisareJucator();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Jucator* Meniu::gasireJucator(const int &idUtilizator) {
    for (const auto &jucator: jucatori) {
        if (jucator->verificareId(idUtilizator)) {
            return jucator;
        }
    }
    return nullptr;
}

void Meniu::interactiuneJucatorLocatie(Jucator *jucator, Locatie *locatie) {
    locatie->aplicaCoeficienti(jucator);
}