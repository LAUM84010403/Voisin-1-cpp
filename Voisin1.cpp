#include <iostream>
#include <vector>

#include "Statistique.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    vector<double> vec{ 10.0, 20.0, 30.0, 40.0, 50.0, 60.0 };
    CalculerMoyenneVector(vec);
    CalculerMedianeVector(vec);
    CalculerEcartTypeVector(vec);

    vector<double> point1{ 1,1 };
    vector<double> point2{ 1,3 };
    CalculerEuclidienne(point1, point2);
    CalculerManhattan(point1, point2);



    cout << endl << endl;
}