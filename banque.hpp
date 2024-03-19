//
//  banque.hpp
//  Bank
//
//  Created by Damien HEULIN on 18/03/2024.
//

#ifndef banque_hpp
#define banque_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Banque {
private:
    std::string nom;
    double solde;
    double retraitMax;
    std::string codeAuthentification;
    std::string codeAuthentificationCrypte;

public:
    Banque(std::string nom, double solde, double retraitMax);
    std::string getNom();
    double getSolde();
    double getRetraitMax();
    void setSolde(double solde);
    void setRetrait(double retraitMax);
    void setCodeAuthentification(std::string code);
    std::string getCodeAuthentificationCrypte();
    void afficherCodeAuthentificationCrypte(); // Déclaration de la méthode
};

#endif /* banque_hpp */
