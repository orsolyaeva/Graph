//
// Created by Orsi on 11/11/2021.
//

#ifndef DFS_DEPTHFIRSTSEARCH_H
#define DFS_DEPTHFIRSTSEARCH_H

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
    vector<Node> nodes;
    vector<edge> edges;
    vector<int> parents{};
    vector<int> paths{};
    vector<vector<int>> children;
    vector<int> dist;
    vector<int> color;
    vector<vector<double>> weights;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    void printAdjList() const;

    void DFS();
    void depth_search(int u);;

};

Graph readGraphFile(const string& filename);

#endif //DFS_DEPTHFIRSTSEARCH_H
