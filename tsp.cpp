#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <thread>
#include <random>
using namespace std;

void readDistances(vector<double> &tempWeightedEdges) {
    string myText;
    ifstream MyReadFile(R"(C:\Users\Chris\Downloads\distances.txt)");
    while(getline(MyReadFile, myText)) {
        tempWeightedEdges.push_back(stod(myText));
    }
}
void createAdjacencyMatrix(int &z, vector<double> &tempWeightedEdges, double weightedEdges[][20], int &cities) {
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            if (i == j) {
                weightedEdges[i][j] = 0;
            } else {
                weightedEdges[i][j] = tempWeightedEdges.at(z - 1);
            }
            z++;
            cout << i << "->" << j << " = " << weightedEdges[i][j] << endl;
        }
    }
}
void addCities(vector<int> &numbers, int &cities) {
    for (int i = 0; i < cities; i++) {
        if (i != 0) {
            numbers.push_back(i);
        }
    }
}
int random(int min, int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    std::cout << distr(gen) << ' ';
    return distr(gen);
}
double getMinPath(int &s, double min_path, vector<int> &numbers, double weightedEdges[][20]) {
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now() + 300s;
        do {
            // store current Path weight(cost)
            double currentPathWeight = 0.0;
            // compute current path weight
            int k = s;
            for (int number: numbers) {
                currentPathWeight += weightedEdges[k][number];
                k = number;
            }
            currentPathWeight += weightedEdges[k][s];
            if (currentPathWeight < min_path) {
                // update minimum
                min_path = min(min_path, currentPathWeight);
            }
        } while (next_permutation(numbers.begin(), numbers.end()) && std::chrono::system_clock::now() < end);
        cout << "\nMinimum Path: " << min_path << endl;
            cout << min_path << endl;
        return min_path;
    }
void acceptInput(int &cities) {
    cout << "Enter number of cities to run: ";
    cin >> cities;
    cout << endl;
}
int main() {
    int cities = 0;
    double min_path = 100000.0;
    int s = 0;
    int z = 0;
    vector<double> tempWeightedEdges;
    vector<int> numbers;
    double weightedEdges[20][20];
    acceptInput(cities);
    addCities(numbers, cities);
    readDistances(tempWeightedEdges);
    createAdjacencyMatrix(z, tempWeightedEdges, weightedEdges, cities);
    getMinPath(s, min_path, numbers, weightedEdges);
    return 0;
}