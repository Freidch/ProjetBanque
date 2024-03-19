//
//  retirerArgent.cpp
//  Bank
//
//  Created by Damien HEULIN on 18/03/2024.
//

#include "retirerArgent.hpp"
#include <iostream>
using namespace std;

// Fonction pour retirer de l'argent du compte
void retirerArgent(Banque& banque) {
    double montant;
    cout << "Entrez le montant que vous souhaitez retirer : ";
    cin >> montant;

    // Vérifier si le montant est valide par rapport au solde et à la limite de retrait mensuel
    if (montant > banque.getSolde()) {
        cout << "Solde insuffisant." << endl;
        return;
    }

    if (montant > banque.getRetraitMax()) {
        cout << "Le montant demandé dépasse votre retrait maximum mensuel autorisé." << endl;
        return;
    }

    // Effectuer le retrait
    banque.setSolde(banque.getSolde() - montant);
    cout << "Vous avez retiré " << montant << " euros de votre compte courant." << endl;
    cout << "Votre solde actuel est de : " << banque.getSolde() << " euros." << endl;
}
