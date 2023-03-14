//
// Created by Chris Robinson on 3/2/23.
//

#ifndef PROJECT_3_TSP_TSP_H
#define PROJECT_3_TSP_TSP_H
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
//#include <bits/stdc++.h>
#define V 5

#define GENES ABCDE
#define START 0;
#define POP_SIZE 10

using namespace std;

class tsp {
public:
    int cities = 0;
    int tours = 0;
    int generations = 0;
    int percentMutated = 0;

    int getA() {
        return this->a;
    }

    int setA(int a) {
        this->a = a;
    }

    vector<double> vertex;
    double graph[20][20] = { };

    bool readDistances() {
        ifstream distances("distances.txt");
        while (getline(distances, fileText)) {
            // Output the text from the file
            cout << fileText;
            //double nextVertex = fileText;
            //double nextVertex = std::stod(fileText);
            //graph.push_back(nextVertex);
        }
        return true;
    }

    int travllingSalesmanProblem(int graph[][V], int s)
    {
        // store all vertex apart from source vertex
        vector<int> vertex;
        for (int i = 0; i < V; i++)
            if (i != s)
                vertex.push_back(i);

        // store minimum weight Hamiltonian Cycle.
        int min_path = INT_MAX;
        do {

            // store current Path weight(cost)
            int current_pathweight = 0;

            // compute current path weight
            int k = s;
            for (int i = 0; i < vertex.size(); i++) {
                current_pathweight += graph[k][vertex[i]];
                k = vertex[i];
            }
            current_pathweight += graph[k][s];

            // update minimum
            min_path = min(min_path, current_pathweight);

        } while (
                next_permutation(vertex.begin(), vertex.end()));

        return min_path;
    }

    bool createAdjacencyMatrix() {
        int adjMat[vertices + 1][vertices + 1];
        for (int i = 0; i < edges; i++) {
            int u = i;
            int v = i;
            adjMat[u][v] = 1;
            adjMat[v][u] = 1;
            // for a directed graph with an edge pointing from u
            // to v,we just assign adjMat[u][v] as 1
        }
        return true;
    }

    bool acceptInput() {
        //the number of cities to run
        cout << "Enter number of cities to run: ";
        cin >> cities;
        //how many individual tours are in a given generation
        cout << "Enter how many individual tours are in a given generation: ";
        cin >> tours;
        //how many generations to run
        cout << "Enter how many generation to run: ";
        cin >> generations;
        //what percentage of a generation should be comprised of mutated tours
        cout << "Enter percentage of a generation should be comprised of mutated tours: ";
        cin >> percentMutated;
        return true;
    }

    void printS() {

    }
private:
    int vertices = 20;
    int edges = 20;
    std::string fileText;
    int a = 0;
};

#endif //PROJECT_3_TSP_TSP_H
