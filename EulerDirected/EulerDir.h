//
// Created by Orsi on 12/25/2021.
//

#ifndef EULERDIRECTED_EULERDIR_H
#define EULERDIRECTED_EULERDIR_H

#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <fstream>
#include <list>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int id;
    vector<Node*> in_neighbors;
    vector<Node*> out_neighbors;
    explicit Node(int id): id(id){};
};

typedef pair<Node*, Node*> edge;
typedef pair<edge, int> weightedEdge;

class Graph {
private:
    int nLimit{0};
    int eLimit{0};
    int nCount{0};
    int eCount{0};
    vector<Node> nodes;
    vector<vector<int>> adj;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    bool isConnected();
    int isEuler();
    void findEuler();
    void sortNodes();

    void dfs(vector<bool>& v, int x, bool out);
};

Graph readGraphFile(const string& filename);

#endif //EULERDIRECTED_EULERDIR_H
