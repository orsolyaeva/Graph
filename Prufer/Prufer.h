//
// Created by Orsi on 10/20/2021.
//

#ifndef LAB1_PRUFER_H
#define LAB1_PRUFER_H

#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <array>

using namespace std;

class Graph {
private:
    vector<int> nodes{};
    vector<array<int,2>> edges{};
    vector<int> statArray{0};
    vector<int> pruferCode{};
public:
    Graph();
    Graph(vector<int> pruferCode);
    void addNode(int);
    void addEdge(int, int);
    void generateStatArray();
    void generatePruferCode();
    void decodePruferCode();
    void printPruferCode();
};

Graph readGraphFile(const string& filename);

void readArrayEdges(const char * file, int *** arrayEdges, int ** degree, int * pn, int * pm);
void printArrayEdges(int **a, int n, int m);
void generatePruferCode(int ** arrayEdges, int * degree, int ** prufer, int n, int m);
void decodePruferCode(int * prufer, int n, int m);

#endif //LAB1_PRUFER_H
