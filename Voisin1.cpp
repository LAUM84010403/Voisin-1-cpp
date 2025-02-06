#include <iostream>
#include <vector>

#include "Statistique.h"
#include "ResourceLoader.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    vector<double> vec{1,2,3};
    CalculerMoyenneVector(vec);
    CalculerMedianeVector(vec);
    CalculerEcartTypeVector(vec);

    vector<double> point1{ 10,-10 };
    vector<double> point2{ 10,-5 };
    CalculerEuclidienne(point1, point2);
    CalculerManhattan(point1, point2);



    ResourceLoader loader;

    // Chargez le fichier CSV
    loader.TraiterFichierCSV("binary-winequality-white.csv");

    double pourcentage{ 0.8 };

    vector<vector<double>> donneesTrain;
    vector<vector<double>> donneesTest;

    donneesTrain = loader.getTrainData(pourcentage);
    donneesTest = loader.getTestData(pourcentage);

    CalculerEuclidienne(donneesTrain[0], donneesTrain[1]);

    cout << endl << endl;
}
