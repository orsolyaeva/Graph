//
// Created by Orsi on 1/7/2022.
//

#ifndef VITERBI_EX_H
#define VITERBI_EX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <list>
#include <cmath>
#define INF 0x3f3f3f3f

using namespace std;

struct Node {
    int id;
    vector<Node*> neighbors;
    explicit Node(int id): id(id){};
};

typedef pair<Node*, Node*> edge;
typedef pair<int, int> edgePair;
typedef pair<edge, int> weightedEdge;

class comparison
{
    bool reverse;
public:
    comparison(const bool& revparam=false)
    {reverse=revparam;}
    bool operator() (const weightedEdge& lhs, const weightedEdge &rhs) const
    {
        if (reverse) return (lhs.second<rhs.second);
        else return (lhs.second>rhs.second);
    }
};

class Graph {
private:
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
    vector<int> cuts;
    vector<int> fathers;
    vector<int> attachedEdge;
    priority_queue<weightedEdge, vector<weightedEdge>, comparison> wEdges;
    list< pair<int, int> > *adj; // store the vertex and weight pair for every edge
    vector<int> array;
    vector<pair<int, int>> directFriendship;

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdgeWeight(int, int, int weight = 0);
    void printAdjList() const;
    void Prim(int src, const string& output);
    void PrimS(int src);
    int getMinCut(const vector<weightedEdge>&, const vector<int>&);
};

Graph readGraphFile(const string& filename);

#endif //VITERBI_EX_H
