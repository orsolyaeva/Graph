//
// Created by Orsi on 12/8/2021.
//

#ifndef EULER_EULER_H
#define EULER_EULER_H

#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <fstream>
#include <list>
#include <iostream>

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
    vector<int> colors;
    vector<vector<int>> matrix;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    void sortNodes();

    bool isConnected();
    void eulerHelper(int);
    int isEuler();
    void findEuler();
    void pathHelper(int);
    int countM(int i) ;
    bool isValidNextEdge(int u, int v);
};

Graph readGraphFile(const string& filename);

#endif //EULER_EULER_H
