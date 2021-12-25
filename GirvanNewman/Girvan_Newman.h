//
// Created by Orsi on 10/20/2021.
//

#ifndef LAB2_GIRVAN_NEWMAN_H
#define LAB2_GIRVAN_NEWMAN_H

#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
#include <fstream>
#include <cmath>

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
    vector<vector<int>> fathers;
    vector<vector<int>> sons;
    vector<Node> nodes;
    vector<edge> edges;
    vector<int> parents{};
    vector<int> paths{};
    vector<vector<int>> children;
    vector<int> dist;
    vector<int> resultBFS;
    vector<vector<double>> weights;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    void removeEdge(int, int);
    void Girvan();

    void printAdjList() const;

    void BFS(int src, vector<bool>& visited);

    void BFSUtil();
};

Graph readGraphFile(const string& filename);

#endif //LAB2_GIRVAN_NEWMAN_H
