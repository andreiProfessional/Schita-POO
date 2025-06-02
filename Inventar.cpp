#include "Inventar.h"
#include "Activitate.h"
#include "Exceptii.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

Inventar::Inventar() {std::cout << std::endl << "Am creat Inventarul!" << std::endl << std::endl;}

Inventar::~Inventar() {
    for (const auto &statie: this->statii) {
        delete statie;
    }
    for (const auto& locatie: this->locatii) {
        delete locatie;
    }
    for (const auto& jucator: this->jucatori) {
        delete jucator;
    }
    for (const auto& activitate: this->istoricActivitati) {
        delete activitate;
    }
    std::cout << std::endl << "Am distrus Inventarul!" << std::endl << std::endl;
}

void Inventar::adaugareStatie(Statie *statie) {
    this->statii.push_back(statie);
}


void Inventar::adaugareMuchieStatii(Statie *statie1, Statie *statie2) {
    this->listeAdiacentaStatii[statie1].push_back(statie2);
    this->listeAdiacentaStatii[statie2].push_back(statie1);
}

void Inventar::adaugareLocatie(Locatie *locatie) {
    this->locatii.push_back(locatie);
}

void Inventar::adaugareJucator(Jucator *jucator) {
    this->jucatori.push_back(jucator);
}

void Inventar::adaugareActivitate(const int& idJucator, const int& tipActivitate, const int& alegere) {
    Jucator* jucator = this->getJucatorDupaID(idJucator);
    Activitate* activitate = nullptr;
    switch (tipActivitate) {
        case 1:
            activitate = new SpawnLocatie(jucator, this->locatii);
            break;
        case 2:
            activitate = new SpawnStatie(jucator, this->listeAdiacentaStatii);
            break;
        case 3:
            activitate = new ActivitateLocatie(jucator, {{"Optiune 1", 1}, {"Optiune 2", 3}, {"Optiune 3", 4}});
            break;
        case 4:
            activitate = new ActivitateStatie(jucator, this->listeAdiacentaStatii);
            break;
        case 5:
            activitate = new ActivitateTaxi(jucator, this->locatii);
            break;
        case 6:
            activitate = new LocatieCatreStatie(jucator);
            break;
        case 7:
            activitate = new StatieCatreLocatie(jucator, this->locatii);
            break;
    }
    try {
        activitate->afisare();
        activitate->activitate(alegere);
    } catch (const InsuficientaViata &exceptie) {
        std::cout << exceptie.what() << std::endl;
    } catch (const InsuficientaHrana &exceptie) {
        std::cout << exceptie.what() << std::endl;
    } catch (const InsuficientaBani &exceptie) {
        std::cout << exceptie.what() << std::endl;
    } catch (const OptiuneIndisponibila &exceptie) {
        std::cout << exceptie.what() << std::endl;
    }
    this->istoricActivitati.push_back(activitate);
}


void Inventar::populareInventar() {
    std::ifstream in("tastatura.txt");
    int numarStatii;
    in >> numarStatii;
    in.get();
    for (int index = 0; index < numarStatii; index ++) {
        Statie *statie = new Statie("", {});
        in >> *statie;
        this->adaugareStatie(statie);
    }
    int numarMuchiiStatii;
    in >> numarMuchiiStatii;
    in.get();
    for (int index = 0; index < numarMuchiiStatii; index ++) {
        std::string input;
        std::getline(in, input);
        int pozitieStatie1 = std::stoi(input.substr(0, input.find(',')));
        input = input.erase(0, input.find(',') + 1);
        int pozitieStatie2 = std::stoi(input.substr(0, input.find(',')));
        this->adaugareMuchieStatii(this->statii[pozitieStatie1 - 1], this->statii[pozitieStatie2 - 1]);
    }
    int numarLocatii;
    in >> numarLocatii;
    in.get();
    for (int index = 0; index < numarLocatii; index ++) {
        std::string input;
        std::getline(in, input);
        auto pozitieVirgula = input.find(',');
        const std::string inputNume = input.substr(0, pozitieVirgula);
        input = input.erase(0, pozitieVirgula + 1);
        pozitieVirgula = input.find(',');
        const int inputCoeficientViata = std::stoi(input.substr(0, pozitieVirgula));
        input = input.erase(0, pozitieVirgula + 1);
        pozitieVirgula = input.find(',');
        const int inputCoeficientHrana = std::stoi(input.substr(0, pozitieVirgula));
        input = input.erase(0, pozitieVirgula + 1);
        pozitieVirgula = input.find(',');
        const int inputCoeficientBani = std::stoi(input.substr(0, pozitieVirgula));
        input = input.erase(0, pozitieVirgula + 1);
        int idStatie = std::stoi(input);
        Statie* inputStatie = this->getStatieDupaID(idStatie);
        Locatie* locatie = new Locatie(inputNume, inputCoeficientViata, inputCoeficientHrana, inputCoeficientBani, inputStatie);
        this->adaugareLocatie(locatie);
    }
    int numarJucatori;
    in >> numarJucatori;
    in.get();
    for (int index = 0; index < numarJucatori; index ++) {
        std::string input;
        std::getline(in, input);
        const auto pozitieVirgula = input.find(',');
        const std::string nume = input.substr(0, pozitieVirgula);
        input = input.erase(0, pozitieVirgula + 1);
        const int optiunePlayer = std::stoi(input);
        switch (optiunePlayer) {
            case 1:
                this->adaugareJucator(JucatorFactory::tataBogat(nume));
                break;
            case 2:
                this->adaugareJucator(JucatorFactory::tataSarac(nume));
                break;
            case 3:
                this->adaugareJucator(JucatorFactory::magnatBatran(nume));
                break;
            case 4:
                this->adaugareJucator(JucatorFactory::omDeRand(nume));
                break;
            case 5:
                this->adaugareJucator(JucatorFactory::pierdeVara(nume));
                break;
        }
    }
    in.close();
}

void Inventar::afisareStatii() const {
    for (const Statie* statie: this->statii) {
        std::cout << *statie << std::endl;
    }
}

void Inventar::afisareListeAdiacentaStatii() const {
    for (const auto &listaAdiacenta: this->listeAdiacentaStatii) {
        std::cout << *listaAdiacenta.first << std::endl;
        for (const auto &statie: listaAdiacenta.second) {
            std::cout << "--> " << *statie << std::endl;
        }
    }
}


void Inventar::afisareLocatii() const {
    for (const Locatie* const locatie: this->locatii) {
        std::cout << *locatie << std::endl;
    }
}

void Inventar::afisareJucatori() const {
    for (const Jucator* const jucator: this->jucatori) {
        std::cout << *jucator << std::endl;
    }
}

void Inventar::afisareIstoricActivitati() const {
    for (const Activitate* activitate: this->istoricActivitati) {
        activitate->afisareRaport();
        std::cout << std::endl;
    }
}


void Inventar::sortareJucatori() {
    std::ranges::sort(this->jucatori, [](const Jucator* jucator1, const Jucator* jucator2) {
            return (*jucator1 > *jucator2);
        });
}

Statie* Inventar::getStatieDupaID(const int &idStatie) {
    for (const auto& statie: this->statii) {
        if (statie->verificaID(idStatie)) {
            return statie;
        }
    }
    return nullptr;
}

Jucator *Inventar::getJucatorDupaID(const int &idJucator) {
    for (const auto& jucator: this->jucatori) {
        if (jucator->verificaID(idJucator)) {
            return jucator;
        }
    }
    return nullptr;
}
