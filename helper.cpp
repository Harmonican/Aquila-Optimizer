#include <iostream>
#include <vector>
#include <time.h>

using std::vector;
// defining the function that will return the randomly initialised population

// declaring the functions
vector<vector<double>> randomInitializer(vector<vector<double>> &, int);
double objectiveFunction(vector<double> &);
vector<double> meanSolution(vector<vector<double>> &);

vector<vector<double>> randomInitializer(vector<vector<double>> &a, int population)
{
    vector<vector<double>> randomMatrix;
    vector<double> firstRandomNumbers; // for the sake of the first elements step description

    double initializedElement{};
    srand((unsigned)time(NULL)); // seeding the random numbers

    for (int p{0}; p < population; p++)
    {
        vector<double> initialSolution;
        double randomNumber;

        for (int i{0}; i < a.size(); i++)
        {
            randomNumber = (float)rand() / RAND_MAX;
            if (p == 0)
                firstRandomNumbers.push_back(randomNumber);

            initializedElement = a.at(i).at(0) + randomNumber * (a.at(i).at(1) - a.at(i).at(0));
            initialSolution.push_back(initializedElement);
        }
        double outputValue = objectiveFunction(initialSolution);
        // the output value is then attached to be part of the elements for that solution
        initialSolution.push_back(outputValue);
        // the solution just finalised is pushed into the matrix of the randomly intialised solution...
        randomMatrix.push_back(initialSolution);
    }

    return randomMatrix;
}

// This objective function is the function used for the particular output parameter that is being optimized and should be edited to suit
double objectiveFunction(vector<double> &factor)
{
    /*
    Laser Micromachining of thin Beams

    */
    double F = factor.at(0);
    double DC = factor.at(1);
    double PO = factor.at(2);
    double N = factor.at(3);
    double GS = factor.at(4);
    double output;

    output = -1.53 * F + 2.76 * DC + 0.169 * PO - 1.92 * N - 0.565 * GS + 0.00363 * F * F + 0.222 * DC * DC + 0.001081 * PO * PO + 0.179 * N * N + 0.01285 * GS * GS + 0.086 * F * DC + 0.00592 * F * PO + 0.0630 * F * N + 0.0080 * F * GS - 0.0683 * DC * PO;

    return output;
}

vector<double> meanSolution(vector<vector<double>> &a)
{
    vector<double> mean;
    double factor{0};
    int N = a.size();

    for (int i{0}; i < a.at(1).size(); i++)
    {
        for (int j{0}; j < a.size(); j++)
        {
            factor += a.at(j).at(i);
        }
        mean.push_back(factor / N);
        factor = 0;
    }
    return mean;
}