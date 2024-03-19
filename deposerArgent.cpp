//
//  deposerArgent.cpp
//  Bank
//
//  Created by Damien HEULIN on 18/03/2024.
//

#include "deposerArgent.hpp"
#include <iostream>
using namespace std;

void deposerArgent(Banque& banque, double montant) {
    if (montant > 0) {
        banque.setSolde(banque.getSolde() + montant);
        cout << "Vous avez déposé " << montant << " euros sur votre compte." << endl;
        cout << "Votre solde actuel est de : " << banque.getSolde() << " euros." << endl;
    } else {
        cout << "Montant invalide. Veuillez entrer un montant positif." << endl;
    }
}
