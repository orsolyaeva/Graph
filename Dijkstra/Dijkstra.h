//
// Created by Orsi on 11/30/2021.
//

#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H

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
    vector<Node> nodes;
    vector<int> parents{};
    vector<int> paths{};
    vector<vector<int>> children;
    vector<int> dist;
    vector<int> fathers;
    vector<int> color;
    vector<int> attachedEdge;
    vector<int> topological;
    vector<vector<int>> weights;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdgeWeight(int, int, int weight = 0);
    void printAdjList() const;

    int getMinDistance(vector<int> queue);
    void dijkstra(int pos);
};

Graph readGraphFile(const string& filename);

#endif //DIJKSTRA_DIJKSTRA_H
