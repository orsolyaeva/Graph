//
// Created by Orsi on 12/8/2021.
//

#ifndef HAMILTON_HAMILTON_H
#define HAMILTON_HAMILTON_H

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <list>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

struct Node {
    int id;
    vector<Node*> neighbors;
    explicit Node(int id): id(id){};
};

class Graph {
private:
    int nLimit{0};
    int eLimit{0};
    int nCount{0};
    int eCount{0};
    bool hasCycle {false};
    vector<Node> nodes;
    vector<int> parents{};
    vector<int> paths{};
    vector<vector<int>> children;
    vector<vector<int>> matrix;
    vector<int> dist;
    vector<int> fathers;
    vector<int> color;
    vector<int> attachedEdge;
    vector<int> topological;
    vector<vector<int>> weights;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    void printAdjList() const;

    void HamiltonCycle();
    void printSolutions();
    bool HamiltonUtil(int pos);
    bool promising(int v, int pos);
};

Graph readGraphFile(const string& filename);

#endif //HAMILTON_HAMILTON_H
