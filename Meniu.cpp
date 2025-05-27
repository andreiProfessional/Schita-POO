#include "Meniu.h"
#include "Inventar.h"
#include <iostream>

Meniu::Meniu(): inventar(Inventar::acceseazaSingleton()) {
    std::cout << "God Message: Orasul a fost creat!" << std::endl << std::endl;
    this->inventar.populareInventar();
}

Meniu::~Meniu() {std::cout << "God Message: Orasul a fost distrus!" << std::endl << std::endl;}


void Meniu::golireEcran() {
    system("clear");
}

void Meniu::afisareInventar() const {
    this->inventar.afisareStatii();
}

/*
void Meniu::meniuInceput() {
    golireEcran();
    std::cout << "Bine ai venit in \"MICUL ORASEL\"!" << std::endl << std::endl;
    std::cout << "1. Selecteaza jucator vechi" << std::endl;
    std::cout << "2. Creeaza jucator nou" << std::endl;
    std::cout << "-1. Pleaca acasa" << std::endl;
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
        case -1:
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
    std::cout << "JUCATORI DISPONIBILI: " << std::endl << std::endl;
    this->afisareListaJucatori();
    std::cout << std::endl << "Alegerea ta (ID Jucator): ";
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

    std::cout << "Locatie Resedinta: ";
    std::string inputStatie;
    std::getline(std::cin, inputStatie);

    //Jucator* jucatorNou = new Jucator(inputNume, inputStatie);
    //jucatori.push_back(jucatorNou);
    //jucatorCurent = jucatorNou;
}

void Meniu::meniuStartJoc() {
    golireEcran();
    std::cout << "___JUCATORUL TAU___" << std::endl << std::endl;
    jucatorCurent->afisareJucator();
    std::cout << std::endl << std::endl;
    std::cout << "1. Incepe jocul" << std::endl;
    std::cout << "0. Inapoi la Meniul de Inceput" << std::endl;
    std::cout << "-1. Iesi din joc" << std::endl;
    std::cout << std::endl << "Alegerea ta: ";
    int optiune;
    std::cin >> optiune;
    switch (optiune) {
        case 1:
            meniuLocatie();
            break;
        case 0:
            jucatorCurent = nullptr;
            meniuInceput();
            break;
        case -1:
            meniuSfarsit();
            break;
        default:
            meniuStartJoc();
            break;
    }
}

void Meniu::meniuAfara() {
    golireEcran();
    std::cout << "___JUCATORUL TAU___" << std::endl << std::endl;
    jucatorCurent->afisareJucator();
    std::cout << std::endl << std::endl;
    std::cout << "Statiile din apropiere:" << std::endl << std::endl;
    const std::string numeStatieCurenta = jucatorCurent->gasireLocatie()->gasireNumeStatie();
    const std::vector<std::pair<Ruta*, int>> statii = hartaOras.gasireStatii(numeStatieCurenta);
    const int numarStatii = statii.size();
    for (int i = 0; i < numarStatii; i ++) {
        std::cout << i + 1 << ". ";
        statii[i].first->afisareDetaliiRuta();
        statii[i].first->afisareStatie(statii[i].second);
        std::cout << " (" << ROSU << "-" << statii[i].first->calcularePretProcent() << "% Lei" << RESETARE << ")";
        std::cout << std::endl;
    }
    std::cout << "-1. Iesi din joc" << std::endl;
    int optiune;
    std::cout << std::endl << "Alegerea ta: ";
    std::cin >> optiune;
    if (optiune == -1) {
        meniuSfarsit();
    }
    else {
        jucatorCurent->setareStatie(std::make_pair(statii[optiune - 1].first, statii[optiune - 1].second));
        jucatorCurent->plataMijlocTransport();
        meniuStatie();
    }
}

void Meniu::meniuLocatie() {
    golireEcran();
    std::cout << "___JUCATORUL TAU___" << std::endl << std::endl;
    jucatorCurent->afisareJucator();
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "___LOCATIA TA___" << std::endl << std::endl;
    jucatorCurent->afisareLocatie();
    std::cout << std::endl;
    jucatorCurent->afisareOptiuniLocatie();
    std::cout << "-1. Iesi din joc" << std::endl << std::endl;
    std::cout << "Alegerea ta: ";
    int optiune;
    std::cin >> optiune;
    switch (optiune) {
        case 0:
            meniuAfara();
            break;
        case -1:
            meniuSfarsit();
            break;
        default:
            jucatorCurent->aplicareCoeficienti(optiune);
            meniuLocatie();
            break;
    }
}

void Meniu::meniuStatie() {
    golireEcran();
    std::cout << "___JUCATORUL TAU___" << std::endl << std::endl;
    jucatorCurent->afisareJucator();
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "___STATIA ACTUALA___" << std::endl << std::endl;
    jucatorCurent->afisareStatie();
    std::cout << std::endl;
    const std::string numeStatieCurenta = jucatorCurent->gasireNumeStatie();
    const std::string numeCapatDus = jucatorCurent->gasireNumeCapat(true);
    const std::string numeCapatIntors = jucatorCurent->gasireNumeCapat(false);
    if (numeStatieCurenta == numeCapatDus) {
        const std::string numeStatiePredecesor = jucatorCurent->gasireNumeStatieUrmatoare(false);
        std::cout << "1. Statia " << numeStatiePredecesor << " (Directia: " << numeCapatIntors << ")" << std::endl;
        std::cout << "0. Du-te afara" << std::endl;
        std::cout << "-1. Iesi din joc" << std::endl;
        std::cout << std::endl << "Alegerea ta: ";
        int optiune;
        std::cin >> optiune;
        switch (optiune) {
            case 1:
                jucatorCurent->calatorieStatiiVecine(false);
                meniuStatie();
                break;
            case 0:
                meniuAfara();
                break;
            case -1:
                meniuSfarsit();
                break;
            default:
                meniuStatie();
                break;
        }
    }
    else if (numeStatieCurenta == numeCapatIntors) {
        const std::string numeStatieSuccesor = jucatorCurent->gasireNumeStatieUrmatoare(true);
        std::cout << "1. Statia " << numeStatieSuccesor << " (Directia: " << numeCapatDus << ")" << std::endl;
        std::cout << "0. Du-te afara" << std::endl;
        std::cout << "-1. Iesi din joc" << std::endl;
        std::cout << std::endl << "Alegerea ta: ";
        int optiune;
        std::cin >> optiune;
        switch (optiune) {
            case 1:
                jucatorCurent->calatorieStatiiVecine(true);
                meniuStatie();
                break;
            case 0:
                meniuAfara();
                break;
            case -1:
                meniuSfarsit();
                break;
            default:
                meniuStatie();
                break;
        }
    }
    else {
        const std::string numeStatieSuccesor = jucatorCurent->gasireNumeStatieUrmatoare(true);
        const std::string numeStatiePredecesor = jucatorCurent->gasireNumeStatieUrmatoare(false);
        std::cout << "1. Statia " << numeStatieSuccesor << " (Directia: " << numeCapatDus << ")" << std::endl;
        std::cout << "2. Statia " << numeStatiePredecesor << " (Directia: " << numeCapatIntors << ")" << std::endl;
        std::cout << "0. Du-te afara" << std::endl;
        std::cout << "-1. Iesi din joc" << std::endl;
        std::cout << std::endl << "Alegerea ta: ";
        int optiune;
        std::cin >> optiune;
        switch (optiune) {
            case 1:
                jucatorCurent->calatorieStatiiVecine(true);
                meniuStatie();
                break;
            case 2:
                jucatorCurent->calatorieStatiiVecine(false);
                meniuStatie();
            case 0:
                meniuAfara();
                break;
            case -1:
                meniuSfarsit();
                break;
            default:
                meniuStatie();
                break;
        }
    }
}
*/


