//
// Created by Chris Robinson on 3/2/23.
//

#ifndef PROJECT_3_TSP_TSP_H
#define PROJECT_3_TSP_TSP_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class tsp {
public:
    int cities = 0;
    int tours = 0;
    int generations = 0; // Program terminates once this number is reached
    int percentMutated = 0;
    string fileText;
    vector<double> weightedEdges;

    void readDistances() {
        ifstream distances("distances.txt");
        while (getline(distances, fileText)) {
            cout << fileText << endl;
            weightedEdges.push_back(stod(fileText));
        }
    }

    bool acceptInput() {
        //the number of cities to run
        cout << "Enter number of cities to run: ";
        cin >> cities;
        cout << endl;
        //how many individual tours are in a given generation
        cout << "Enter how many individual tours are in a given generation: ";
        cin >> tours;
        cout << endl;
        //how many generations to run
        cout << "Enter how many generation to run: ";
        cin >> generations;
        cout << endl;
        //what percentage of a generation should be comprised of mutated tours
        cout << "Enter percentage of a generation should be comprised of mutated tours: ";
        cin >> percentMutated;
        return true;
    }
};

#endif //PROJECT_3_TSP_TSP_H
