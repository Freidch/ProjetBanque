//
//  banque.cpp
//  Bank
//
//  Created by Damien HEULIN on 18/03/2024.
//

#include "banque.hpp"
#include <bitset>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>

Banque::Banque(string nom, double solde, double retraitMax)
    : nom(nom), solde(solde), retraitMax(retraitMax) {}

string Banque::getNom() {
    return nom;
}

double Banque::getSolde() {
    return solde;
}

double Banque::getRetraitMax() {
    return retraitMax;
}

void Banque::setSolde(double solde) {
    this->solde = solde;
}

void Banque::setRetrait(double retraitMax) {
    this->retraitMax = retraitMax;
}

void Banque::setCodeAuthentification(string code) {
    // Vérifier que le code contient exactement 4 chiffres
    while (code.size() != 4 || !std::all_of(code.begin(), code.end(), ::isdigit)) {
        std::cerr << "Erreur : Le code d'authentification doit contenir exactement 4 chiffres." << std::endl;
        std::cout << "Entrez à nouveau votre code d'authentification : ";
        std::cin >> code;
    }

    this->codeAuthentification = code;

    // Crypter le code d'authentification
    size_t const sha_size = 32;
    int checksum = 0;
    for (char c : code) {checksum += c;}
    bitset<sha_size> binary(checksum);
    stringstream ss;
    ss << binary;
    codeAuthentificationCrypte = ss.str();
}

string Banque::getCodeAuthentificationCrypte() {
    return codeAuthentificationCrypte;
}
