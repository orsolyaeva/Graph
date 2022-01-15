//
// Created by Orsi on 1/6/2022.
//

#ifndef KRUSKAL_KRUSKAL_H
#define KRUSKAL_KRUSKAL_H

#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int id;
    vector<Node*> neighbors;
    explicit Node(int id): id(id){};
};
typedef pair<Node*, Node*> edge;
typedef pair<edge, int> weightedEdge;

class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam=false)
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
    priority_queue<weightedEdge, vector<weightedEdge>, mycomparison> wEdges;
    vector<int> colors;
    vector<vector<int>> parents;
    vector<vector<int>> children;
    vector<vector<edge>> categories;
    vector<int> touched;
    vector<int> left;
    vector<int> dist;
    vector<vector<int>> allDistances;
    vector<vector<double>> weights;
    vector<int> levels;
    vector<int> fathers;
    vector<int> topologycal;
    vector<Node> transpuse;
    vector<int> cuts;
    bool kormentes{true};
    int time{0};

    int parentCount(int child);

public:
    Graph(int nLimit = 0, int eLimit = 0);
    void addNode(int);
    void addEdge(int, int);
    void addEdgeWeight(int, int, int);

    void runPrim();
    void Kruskal();
    vector<int> unite (vector<int> tree, int a, int b);
    int minVagas(vector<weightedEdge>);
    void getBridges();
    void generateTranspuse();
    void getBridgePoints();
    void getTopologycal() const;
    void getKormentes() const;
    void printColors() const;
    void printParents() const;
    void printChildren() const;
    void printAdjList() const;
    void edgeCategories() const;
    void printTimes() const;
    void printEdges() const;
    void shortestPaths() const;
    void printWeights() const;
};

Graph readGraphFromFile(const string& filename);

#endif //KRUSKAL_KRUSKAL_H
