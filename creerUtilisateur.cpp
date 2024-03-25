//
//  creerUtilisateur.cpp
//  Bank
//
//  Created by Damien HEULIN on 18/03/2024.
//

#include "creerUtilisateur.hpp"
#include <iostream>
using namespace std;

// Fonction pour créer un utilisateur et choisir une banque
void creerUtilisateur(vector<Banque>& banques, Banque& utilisateur) {
    // Votre commentaire fait remarquer que la fonction créé un utilisateur
    // et demande de choisir une banque, mais elle s'appelle uniquement creerUtilisateur
    // Vous pouvez initialiser la banque à part ou renommer cette fonction.
    // Pourquoi ne pas appeler cette fonction initialiserCompte?
    // Le commentaire deviendrait ainsi inutile et le code appelant n'aurait aucun doute sur ce que fait la fonction.
    int choixBanque;
    double solde, pourcentageRetraitMax, retraitMax;
    string nomCarte, code;

    cout << "Bienvenue dans notre système de gestion bancaire !" << endl;
    cout << "Veuillez choisir votre banque parmi les options suivantes :" << endl;

    // Afficher les options de banque
    for (int i = 0; i < banques.size(); ++i) {
        cout << i+1 << ". " << banques[i].getNom() << endl;
    }

    // Demander à l'utilisateur de choisir une banque
    cout << "Entrez le numéro correspondant à votre choix : ";
    cin >> choixBanque;

    // Vérifier si le choix est valide
    if (choixBanque < 1 || choixBanque > banques.size()) {
        cout << "Choix invalide." << endl;
        return;
        // Si le programme arrive ici, la banque n'est pas initialisée
        // mais le programme ne s'arrete pas (essayez en entrant 10 puis "toto" par exemple)
    }

    // Récupérer la banque choisie par l'utilisateur
    utilisateur = banques[choixBanque - 1];

    cout << "Entrez votre solde en banque : ";
    cin >> solde;

    // Si le solde est négatif, expliquer le choix d'un retrait de 100 euros
    if (solde < 0) {
        cout << "Votre solde est négatif. Un retrait de 100 euros sera autorisé jusqu'à ce que le solde repasse en positif." << endl;
        retraitMax = 100; // Retrait maximum autorisé en cas de solde négatif
    } else {
        // Définir les pourcentages de retrait maximum autorisé en fonction du solde
        if (solde < 1000) {
            pourcentageRetraitMax = 0.5; // 50% du solde
        } else if (solde < 5000) {
            pourcentageRetraitMax = 0.3; // 30% du solde
        } else {
            pourcentageRetraitMax = 0.2; // 20% du solde
                }

        // Calculer le retrait maximum autorisé
        retraitMax = solde * pourcentageRetraitMax;
            }

        // Sélection du nom de la carte en fonction du retrait maximum
        if (retraitMax <= 1500) {
            nomCarte = "Carte " + banques[choixBanque - 1].getNom();
        } else if (retraitMax <= 5000) {
            nomCarte = "Carte Gold";
        } else if (retraitMax > 10000) {
            nomCarte = "Carte Platinum";
        } else {
            nomCarte = "Carte Standard";
        }

        // Générer le code d'authentification
        cout << "Choisissez votre code d'authentification : ";
        cin >> code;
        utilisateur.setCodeAuthentification(code);

        cout << "Votre retrait maximum autorisé est de : " << retraitMax << " euros." << endl;
        cout << "Vous recevrez une " << nomCarte << "." << endl;

        utilisateur.setSolde(solde);
        utilisateur.setRetrait(retraitMax);
    }
