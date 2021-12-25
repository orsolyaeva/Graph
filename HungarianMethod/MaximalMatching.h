//
// Created by Orsi on 12/25/2021.
//

#ifndef HUNGARIANMETHOD_MAXIMALMATCHING_H
#define HUNGARIANMETHOD_MAXIMALMATCHING_H

#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <fstream>
#include <list>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int id;
    vector<Node*> neighbors;
    explicit Node(int id): id(id){};
};

struct edgeM {
    int p{0}, u, v;
    explicit edgeM(int u = 0, int v = 0): u(u), v(v) {};
};

typedef pair<Node*, Node*> edge;

class Graph {
private:
    int nLimit{0};
    int eLimit{0};
    int nCount{0};
    int eCount{0};
    vector<Node> nodes;
    vector<edge> edges;
    vector<vector<int>> parents;
    vector<vector<int>> children;
    vector<int> touched;
    vector<int> left;
    vector<int> dist;
    vector<vector<int>> allDistances;
    vector<vector<int>> weights;
    vector<int> levels;
    vector<int> topological;
    vector<Node> transpuse;
    vector<int> dists;
    vector<int> cuts;

    vector<int> colors;
    vector<int> paint;
    vector<int> fathers;
    vector<vector<int>> matrix;
    vector<edgeM> edgesM;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    int twoColoring(int s);
    int findAugmentingPath(int s, int max_paint, int min_paint);
    void reverseAlternation(int i, int j);
    void maximal_matching();
};

Graph readGraphFile(const string& filename);

#endif //HUNGARIANMETHOD_MAXIMALMATCHING_H
