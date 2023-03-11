//
// Created by Chris Robinson on 3/2/23.
//

#ifndef PROJECT_3_TSP_TSP_H
#define PROJECT_3_TSP_TSP_H
#include <iostream>
#include <fstream>
class tsp {
public:
    int getA() {
        return this->a;
    }

    int setA(int a) {
        this->a = a;
    }

    bool readDistances() {
        std::ifstream distances("distances.txt");
        while (getline(distances, fileText)) {
            // Output the text from the file
            std::cout << fileText;
        }
        //return true;

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

    void acceptInput();

    void printS() {

    }
private:
    int vertices = 20;
    int edges = 20;
    std::string fileText;
    int a = 0;
};

#endif //PROJECT_3_TSP_TSP_H
