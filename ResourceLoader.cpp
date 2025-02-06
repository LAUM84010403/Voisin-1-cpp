#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


#include "ResourceLoader.h"

using namespace std;


/*
Méthode qui s'executeà la céation d'une instance de la classe
*/
ResourceLoader::ResourceLoader()
{
    m_premier = nullptr;
}

/*
Méthode qui s'executeà la suppresion d'une instance de la classe
*/
ResourceLoader::~ResourceLoader()
{
    if (m_premier == nullptr)
    {
        delete m_premier;
    }
    else
    {
        Noeud* iterateur = m_premier;

        while (iterateur != nullptr)
        {
            Noeud* aSupprimer = iterateur;
            iterateur = iterateur->suivant;
            delete aSupprimer;
        }
    }
}

/**
 * @brief Charge les données d'un fichier CSV et les stocke dans des vecteurs.
 *
 * @param cheminFichier Le chemin du fichier CSV à lire.
 *
 * @note Assurez-vous que le fichier CSV a le bon format, sinon des erreurs seront affichées.
 */
void ResourceLoader::TraiterFichierCSV(const string& cheminFichier) {
    ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << endl;
        return;
    }

    string ligne;
    int i{ 0 };

    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string valeur;
        vector<double> donnees;


        while (getline(ss, valeur, ',')) {
            donnees.push_back(stod(valeur));
        }

        if (donnees.size() < 12) {
            cerr << "Erreur : Ligne mal formatée ou données manquantes." << endl;
            continue;
        }

        Noeud* nouvelleValeur = new Noeud{
            donnees,
            nullptr
        };

        if (m_premier == nullptr) {
            m_premier = nouvelleValeur;
        }
        else {
            Noeud* iterateur = m_premier;
            while (iterateur->suivant != nullptr) {
                iterateur = iterateur->suivant;
            }
            iterateur->suivant = nouvelleValeur;
        }

        i++;
    }

    cout << "Nombre de lignes traites: " << i << endl;
    fichier.close();
}

/**
 * @brief Prends des données à partir du début du ressource loader pour s'entrainer
 *
 * @param pourcentage qui équivaux au nombre de donnée que l'utilisateur veut utiliser
 *
 * @verif si le pourcentage n'est pas bien formaté, retourne une erreur
 *
 * @return un vector remplis des données prete à être testée
 */
vector<vector<double>> ResourceLoader::getTrainData(double pourcentage) {

    if (pourcentage > 1)
    {
        cerr << "Erreur : Entrez un nombre en dessus de 1" << endl;
        return{};
    }

    int total{ 2 };
    Noeud* iterateur = m_premier;

    while (iterateur->suivant != nullptr)
    {
        iterateur = iterateur->suivant;
        total++;
    }

    int nombreTrain = total * pourcentage;

    vector<vector<double>> donnees;
    iterateur = m_premier;

    for (int i = 0; i < nombreTrain && iterateur != nullptr; i++)
    {
        donnees.push_back(iterateur->valeurs);
        iterateur = iterateur->suivant;
    }

    cout << "Train reussit!" << endl;
    return donnees;
}

/**
 * @brief Prends des données à partir du début du ressource loader pour avoir des données
 *
 * @param pourcentage qui équivaux au nombre de donnée que l'utilisateur veut utiliser
 *
 * @verif si le pourcentage n'est pas bien formaté, retourne une erreur
 *
 * @return un vector remplis des données prete à être testée
 */
vector<vector<double>> ResourceLoader::getTestData(double pourcentage)
{

    if (pourcentage > 1)
    {
        cerr << "Erreur : Entrez un nombre en dessus de 1" << endl;
        return{};
    }

    int total{ 2 };
    Noeud* iterateur = m_premier;

    pourcentage = 1 - pourcentage;

    while (iterateur->suivant != nullptr)
    {
        iterateur = iterateur->suivant;
        total++;
    }

    int nombreTrain = total * pourcentage;

    vector<vector<double>> donnees;
    iterateur = m_premier;

    for (int i = 0; i < nombreTrain && iterateur != nullptr; i++)
    {
        donnees.push_back(iterateur->valeurs);
        iterateur = iterateur->suivant;
    }

    cout << "Test reussit!" << endl;
    return donnees;
}
