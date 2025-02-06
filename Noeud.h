#pragma once

#include <vector>

using namespace std;

struct Noeud
{
    vector<double> valeurs;

    Noeud* suivant;
};