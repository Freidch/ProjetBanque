//
//  main.cpp
//  Bank
//
//  Created by Damien HEULIN on 17/03/2024.
//

#include "banque.hpp"
#include "creerUtilisateur.hpp"
#include "retirerArgent.hpp"
#include "deposerArgent.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Initialiser les banques disponibles
    vector<Banque> banques;
    banques.push_back(Banque("BNP Paribas", 0, 0));
    banques.push_back(Banque("Crédit Agricole", 0, 0));
    banques.push_back(Banque("Société Générale", 0, 0));
    banques.push_back(Banque("Crédit Mutuel", 0, 0));
    banques.push_back(Banque("Banque Postale", 0, 0));
    banques.push_back(Banque("HSBC", 0, 0));
    banques.push_back(Banque("Caisse d'épargne", 0, 0));

    Banque utilisateur("", 0, 0);
    
    creerUtilisateur(banques, utilisateur);

    // Afficher le code d'authentification crypté une fois que l'utilisateur a terminé la création du compte
    cout << "Votre code d'authentification crypté est : " << utilisateur.getCodeAuthentificationCrypte() << endl;

    char choix;
    do {
        cout << "Souhaitez-vous effectuer une opération sur votre compte ?" << endl;
        cout << "1. Retrait d'argent" << endl;
        cout << "2. Dépôt d'argent" << endl;
        cout << "3. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case '1':
                retirerArgent(utilisateur);
                break;
            case '2': {
                double montant;
                cout << "Entrez le montant que vous souhaitez déposer : ";
                cin >> montant;
                deposerArgent(utilisateur, montant);
                break;
            }
            case '3':
                cout << "Merci d'avoir utilisé notre service bancaire. Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez sélectionner une option valide." << endl;
        }
    } while (choix != '3');

    return 0;
}
