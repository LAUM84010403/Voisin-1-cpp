#include <iostream>
#include <vector>
#include<algorithm>
#include "ResourceLoader.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "Statistique.h"

using namespace std;

/**
 * @brief Prends un vector et fais la moyenne de tous les chiffres
 *
 * @param vector tableau qui est remplis de nombres
 *
 * @return un double contenant la moyenne
 */
double CalculerMoyenneVector(vector<double> tableau)
{
	double moyenne;
	double total{0};

	for (int i = 0; i < tableau.size(); i++)
	{
		total += tableau[i];
	}

	moyenne = total / tableau.size();
	cout << "Moyenne: " << moyenne << endl;
	return moyenne;
}

/**
 * @brief Prends un vector et calcule la medianne
 *
 * @param vector tableau qui est remplis de nombres
 *
 * @return un double contenant la medianne
 */
double CalculerMedianeVector(vector<double> tableau){

	double mediane;
	double valeur1;
	double valeur2;

	sort(tableau.begin(), tableau.end()); //source: https://www.digitalocean.com/community/tutorials/sorting-a-vector-in-c-plus-plus


	if (tableau.size() % 2 == 1) {
		mediane = (tableau.size() + 1) / 2;
		cout << "Mediane: " << tableau[mediane - 1] << endl;
	}
	else {
		valeur1 = tableau.size() / 2;
		valeur2 = valeur1 + 1;
		mediane = (tableau[valeur1 - 1] + tableau[valeur2 - 1]) / 2;
		cout << "Mediane: " << mediane << endl;
	}
	return 0;
}

/**
 * @brief Prends un vector et fais l'ecart-type de tous les chiffres
 *
 * @param vector tableau qui est remplis de nombres
 *
 * @return un double contenant l'écart
 */
double CalculerEcartTypeVector(vector<double> tableau)
{
	double moyenne = CalculerMoyenneVector(tableau);
	double ecart;
	
	for (int i = 0; i < tableau.size(); i++)
	{
		tableau[i] = (tableau[i] - moyenne) * (tableau[i] - moyenne);
	}
	ecart = sqrt(CalculerMoyenneVector(tableau));

	cout << "Ecart-type: " << ecart << endl;
	return ecart;
}

/**
 * @brief Prends deux vectors de même longueurs et calcule la longueur Euclédienne
 *
 * @param1 Vector pour les première coordonnées 
 * @parma2 Vector pour les deuxième coordonnées
 *
 * @return un double contenant la distance Euclidienne
 */
double CalculerEuclidienne(vector<double> valeur1, vector<double> valeur2) 
{
	if (!(valeur1.size() == valeur2.size())) {
		cout << "Erreur, les deux tableaux doivent etre dans les memes dimensions!";
		return 1;
	}
	double diff{ 0 };

	for (int i = 0; i < valeur1.size(); i++)
	{
		diff += (valeur1[i] - valeur2[i]) * (valeur1[i] - valeur2[i]);
	}

	diff = sqrt(diff);

	cout << "Difference Euclidienne: " << diff << endl;
	return 0;
}

/**
 * @brief Prends deux vectors de même longueurs et calcule la longueur de Manhattan
 *
 * @param1 Vector pour les première coordonnées
 * @parma2 Vector pour les deuxième coordonnées
 *
 * @return un double contenant la distance de Manhattan
 */
double CalculerManhattan(vector<double> valeur1, vector<double> valeur2)
{
	if (!(valeur1.size() == valeur2.size())) {
		cout << "Erreur, les deux points doivent etre dans les meme dimension!";
		return 1;
	}
	double dist{};

	for (int i = 0; i < valeur1.size(); i++)
	{
		dist += (valeur1[i] - valeur2[i]) * (valeur1[i] - valeur2[i]);
	}

	cout << "Distance Manhattan: " << dist << endl;

	return 0;
}