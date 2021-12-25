//
// Created by Orsi on 10/21/2021.
//

#ifndef LAB4_AP_BRIDGES_H
#define LAB4_AP_BRIDGES_H

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

struct Node {
    int id, weight{0};
    vector<Node*> neighbors;
    explicit Node(int id): id(id){};
};

class Graph {
private:
    typedef pair<Node*, Node*> edge;
    int nLimit{0};
    int eLimit{0};
    int nCount{0};
    int eCount{0};
    vector<Node> nodes;
    vector<edge> edges;
    vector<int> colors;
    vector<int> levels;
    vector<int> fathers;
    vector<array<int, 2>> possible_cuts;
    vector<array<int, 2>> possible_bridges;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    void printAdjList() const;

    int Articulation_Point(int pos, int level);
    void getArticulationPoints();

    int Bridge_Edges(int pos, int level);
    void getBridges();
};

Graph readGraphFile(const string& filename);

#endif //LAB4_AP_BRIDGES_H
