//
// Created by Orsi on 11/11/2021.
//

#ifndef BFS_BREADTHFIRSTSEARCH_H
#define BFS_BREADTHFIRSTSEARCH_H

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
    vector<int> resultBFS;
    vector<vector<double>> weights;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    void printAdjList() const;

    void BFS(int src);
    void getShortestPaths(int i) const;

    void BFSUtil();
};

Graph readGraphFile(const string& filename);

#endif //BFS_BREADTHFIRSTSEARCH_H
