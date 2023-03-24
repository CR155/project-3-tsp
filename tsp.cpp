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
    ifstream MyReadFile("distances.txt");
    while(getline(MyReadFile, myText)) {
        tempWeightedEdges.push_back(std::atof(myText.c_str()));
    }
}
// Creates adjacency matrix
void createAdjacencyMatrix(int &z, vector<double> &tempWeightedEdges, double weightedEdges[][20], int &cities) {
    cout << "---- ADJACENCY MATRIX ----" << endl;
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            // if 0 = 0 or 1 = 1 this will set the value of the edge to 0
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
// Brute forces the minimum path of adjacency matrix
double getMinPath(int &s, double min_path, vector<int> &numbers, double weightedEdges[][20], vector<vector<int>> &population,
                  vector<double> &generationWeights) {
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now() + 300s;
    vector<int> path;
        do {
            // store current Path weight(cost)
            double currentPathWeight = 0.0;
            // compute current path weight
            int k = s;
            for (int number: numbers) {
                currentPathWeight += weightedEdges[k][number];
                k = number;
                path.push_back(k);
            }
            path.insert(path.begin(), 0);
            path.insert(path.end(), 0);
            population.push_back(path);
            path.clear();
            currentPathWeight += weightedEdges[k][s];
            generationWeights.push_back(currentPathWeight);
            if (currentPathWeight < min_path) {
                // update minimum
                min_path = min(min_path, currentPathWeight);
            }
        } while (next_permutation(numbers.begin(), numbers.end()) && std::chrono::system_clock::now() < end);
        cout << "\nMinimum Path: " << min_path << endl;
        cout << "\nBrute Force Finished..." << endl;
        return min_path;
    }
    // Accepts a vector of type int and splits vector beginning at X, ending at Y.
vector<int> split(vector<int> &arr, int X, int Y) {
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;
    vector<int> result(Y - X + 1);;
    copy(start, end, result.begin());
    return result;
}
// Prints result of parameterized vector
void printResult(vector<int> &ans) {
    for(auto& it : ans) {
        cout << it << ' ';
    }
}
// Generates random number from 0 to N
int randomNumber(int N) {
    static std::random_device seed;
    static std::mt19937 eng(seed());
    std::uniform_int_distribution<> dist(0, N - 1);
    return dist(eng);
}
    void printPopulation(vector<vector<int>> &population, vector<double> generationWeights, int &generationsToRun, int &cities) {
        int A = 0;
        int B = cities / 2;
        int C = cities / 2;
        int D = cities - 1;
        vector<int> splitVec1;
        vector<int> splitVec2;
    for (int i = 0; i < generationsToRun; i++) {
        cout << "\nGeneration #" << i + 1 << " = ";
        for (int j = 0; j < cities; j++) {
            // Crossover
            splitVec1 = split(population[i], A, B);
            splitVec2 = split(population[j], C, D);
            splitVec1.insert(splitVec1.end(), splitVec2.begin(), splitVec2.end() - 1);
            // Mutation
            iter_swap(splitVec1.begin() + randomNumber(cities),
                      splitVec1.begin() + randomNumber(cities));
            int n = splitVec1.size();
            // Inserts 0 at beginning and end of vector to ensure full path is toured
            splitVec1[n - 1] = 0;
            splitVec1[n - n] = 0;
        }
        printResult(splitVec1);
        cout << "\nGeneration Weight: " << generationWeights[i] << endl;
    }
}
void acceptInput(int &cities,int &generationsToRun, int &solutionsInGeneration, int &percentOfToursMutated ) {
    cout << "Enter number of cities to run: ";
    cin >> cities;
    cout << "How many generations to run: ";
    cin >> generationsToRun;
    cout << "How many solutions in a generation: ";
    cin >> solutionsInGeneration;
    cout << "What percentage of a generation should be comprised of mutated tours: ";
    cin >> percentOfToursMutated;
    cout << endl;
}
int main() {
    int generationsToRun = 0;
    int solutionsInGeneration = 0;
    int percentOfToursMutated = 0;
    int cities = 0;
    double min_path = 100000.0;
    int s = 0;
    int z = 0;
    vector<double> tempWeightedEdges;
    vector<vector<int>> population;
    vector<double> generationWeights;
    vector<int> numbers;
    double weightedEdges[20][20];
    acceptInput(cities,generationsToRun, solutionsInGeneration, percentOfToursMutated );
    addCities(numbers, cities);
    readDistances(tempWeightedEdges);
    createAdjacencyMatrix(z, tempWeightedEdges, weightedEdges, cities);
    getMinPath(s, min_path, numbers, weightedEdges, population, generationWeights);
    printPopulation(population, generationWeights, generationsToRun, cities);
    return 0;
}
