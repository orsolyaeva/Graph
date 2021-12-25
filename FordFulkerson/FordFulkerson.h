//
// Created by Orsi on 11/30/2021.
//

#ifndef FORD_FULKERSON_FORDFULKERSON_H
#define FORD_FULKERSON_FORDFULKERSON_H

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

struct Point {
    int f;
    int c;
    explicit Point(): f(0), c(-1){};
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
    vector<vector<Point>> matrix;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdgeWeight(int, int, int weight = 0);
    void printAdjList() const;

    void fordFulkerson();
    int fordHelper(int pos, int t);
    void findAugmentingPath(int pos, int& min, int t);
    void fixPath(int u, int &min);
};

Graph readGraphFile(const string& filename);

#endif //FORD_FULKERSON_FORDFULKERSON_H
