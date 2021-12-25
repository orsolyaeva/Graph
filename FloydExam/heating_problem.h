//
// Created by Orsi on 11/25/2021.
//

#ifndef LAB7_HEATING_PROBLEM_H
#define LAB7_HEATING_PROBLEM_H

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <list>
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
    vector<Node> nodes;
    vector<int> parents{};
    vector<int> paths{};
    vector<vector<int>> children;
    vector<int> dist;
    vector<int> fathers;
    vector<int> attachedEdge;
    vector<vector<int>> weights;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdgeWeight(int, int, int weight = 0);
    void printAdjList() const;
    int Floyd();
};

Graph readGraphFile(const string& filename);
void PrintSolution(vector<vector<int>> a, int n);

#endif //LAB7_HEATING_PROBLEM_H
