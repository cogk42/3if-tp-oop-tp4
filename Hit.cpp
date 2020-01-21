/*************************************************************************
                           Hit  -  description
                             -------------------
    début                : 2020-01-06
    copyright            : (C) 2019 FADILI Zineb & FORLER Corentin
    e-mail               : zineb.fadili@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Hit> (fichier Hit.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "App.h"
#include "Hit.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Hit::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ifstream &operator>>(ifstream &fichierLog, Hit &unHit)
{
    string garbage; // on y stocke à chaque fois ce qu'on ne veut pas.
    string hourAsString;
    unHit.cible = "";
    unHit.referer = "";
    unHit.hour = 0;

    getline(fichierLog, garbage, ':');
    if (garbage == "")
    {
        // fin de fichier
        return fichierLog;
    }

    getline(fichierLog, hourAsString, ':');

    unHit.hour = (unsigned int)App::atoi(hourAsString.c_str()); // on est sur que si on arrive à ce stade que le resultat de atoi n'est pas -1
    // car on a verifie juste avant que la ligne n'est pas vide (dans la condition de vérification de garbage)

    getline(fichierLog, garbage, ' ');
    getline(fichierLog, garbage, ' ');
    getline(fichierLog, garbage, ' ');
    getline(fichierLog, unHit.cible, ' ');

    getline(fichierLog, garbage, ' ');
    getline(fichierLog, garbage, '"');
    getline(fichierLog, unHit.referer, '"');

    // on ignore le reste de la ligne jusqu'à la fin de ligne
    getline(fichierLog, garbage);

    //cout << "I read this hour : " << unHit.hour << " and this cible " << unHit.cible << "and this referer : " << unHit.referer << endl; READING OK EXCEPT OTHER LINE?

    return fichierLog;
}

//-------------------------------------------- Constructeurs - destructeur
Hit::Hit()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Hit>" << endl;
#endif
} //----- Fin de Hit

Hit::~Hit()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Hit>" << endl;
#endif
} //----- Fin de ~Hit

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
