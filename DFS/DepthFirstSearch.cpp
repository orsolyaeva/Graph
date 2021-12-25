//
// Created by Orsi on 11/11/2021.
//

#include "DepthFirstSearch.h"

bool operator==(const Node& lhs, const Node& rhs)
{
    return lhs.id == rhs.id;
}

Graph::Graph(int nLimit, int eLimit) : nLimit(nLimit), eLimit(eLimit) {
}

void Graph ::addNode(int id) {
    if(this->nCount < this->nLimit) {
        this->nodes.emplace_back(Node(id));
        this->nCount += 1;
        this->parents.emplace_back(-1);
        this->children.resize(nCount);
        this->dist.resize(this->nCount);
        this->weights.resize(this->nCount);
    }
}

void Graph ::addEdge(int a, int b) {
    a--; b--;
    if(this->eCount < this->eLimit && a >= 0 && b >= 0 && a < nCount && b < nCount) {
        Node * c = &this->nodes[a];
        Node * d = &this->nodes[b];
        edge temp{c, d};
        this->edges.emplace_back(temp);
        this->nodes[a].neighbors.emplace_back(d);
        this->nodes[b].neighbors.emplace_back(c);
        eCount++;
    }
}

void Graph::printAdjList() const {
    for(const auto& node: this->nodes) {
        cout << node.id << ": ";
        for(auto neighbor: node.neighbors) {
            cout << neighbor->id << " ";
        }
        cout << endl;
    }
}
Graph readGraphFile(const string& filename) {
    ifstream fin(filename);
    if(!fin) {
        exit(1);
    }

    int n, m;
    fin >> n >> m;
    Graph graph(n, m);

    for(int i = 1; i <= n; i++){
        graph.addNode(i);
    }

    while(fin >> n >> m) {
        graph.addEdge(n, m);
    }

    return graph;
}


void Graph::DFS() {
    this->color.resize(this->nCount);
    this->parents.resize(this->nCount);
    this->dist.resize(this->nCount);

    for(int i = 0; i < this->nCount; i++) {
        this->color[i] = 0;
        this->parents[i] = -1;
        this->dist[i] = INT_MAX;
    }

    for(int i = 0; i < this->nCount; i++) {
        if(this->color[i] == 0) {
            depth_search(i);
        }
    }
}

void Graph::depth_search(int u) {
//    cout << u + 1 << " ";
    this->color[u] = 1;
    for(auto& neighbor : this->nodes[u].neighbors) {
        if(this->color[neighbor->id - 1] == 0) {
            this->parents[neighbor->id - 1] = u + 1;
            depth_search(neighbor->id - 1);
        }
    }
    this->color[u] = 2;
}


