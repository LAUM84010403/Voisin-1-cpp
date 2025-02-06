#pragma once

#include <string>
#include <vector>

#include "Noeud.h"

using namespace std;


class ResourceLoader
{
private:
    Noeud* m_premier;

public:
    ResourceLoader();
    ~ResourceLoader();

    void TraiterFichierCSV(const string& cheminFichier);

    vector<vector<double>> getTrainData(double pourcentage);
    vector<vector<double>> getTestData(double pourcentage);
};
