#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;
void readDistances(vector<double> &tempWeightedEdges) {
    string myText;
    ifstream MyReadFile(R"(C:\Users\Chris\Downloads\distances.txt)");
    while(getline(MyReadFile, myText)) {
        tempWeightedEdges.push_back(stod(myText));
    }
}
void createAdjacencyMatrix(int &z, vector<double> &tempWeightedEdges, double weightedEdges[][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == j) {
                continue;
            }
            weightedEdges[i][j] = tempWeightedEdges.at(z);
            z++;
            cout << "[" << i << "]" << "[" << j << "]" << " = " << weightedEdges[i][j] << endl;
        }
    }
}
void addCities(vector<int> &numbers, int &cities) {
    for(int i = 0; i < cities; i++) {
        numbers.push_back(i);
    }
}
bool stop() {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return true;
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
            // update minimum
            min_path = min(min_path, currentPathWeight);
            cout << min_path << endl;
        } while (next_permutation(numbers.begin(), numbers.end()) && std::chrono::system_clock::now() < end);
        return min_path;
    }
void acceptInput(int &cities) {
    cout << "Enter number of cities to run: ";
    cin >> cities;
}

void createPopulation() {
    for (int i = 0; i < 10; i++) {

    }
}
int main() {
    int cities = 0;
    //int tours = 0;
    //int generations = 0;
    //int percentMutated = 0;
    double min_path = 100000.0;
    int s = 0;
    int z = 0;
    vector<double> tempWeightedEdges;
    vector<int> numbers;
    double weightedEdges[20][20];
    acceptInput(cities);
    addCities(numbers, cities);
    readDistances(tempWeightedEdges);
    createAdjacencyMatrix(z, tempWeightedEdges, weightedEdges);
    //std::chrono::time_point<std::chrono::system_clock> end;
    //end = std::chrono::system_clock::now() + 5s;
    //while (std::chrono::system_clock::now() < end) {
    getMinPath(s, min_path, numbers, weightedEdges);
    //}
    return 0;
}