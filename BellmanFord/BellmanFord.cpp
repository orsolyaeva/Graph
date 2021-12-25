//
// Created by Orsi on 11/30/2021.
//

#include "BellmanFord.h"

bool operator==(const Node& lhs, const Node& rhs)
{
    return lhs.id == rhs.id;
}

Graph::Graph(int nLimit, int eLimit) : nLimit(nLimit), eLimit(eLimit) {
    this->weights.resize(this->nLimit);
    for(int i = 0; i < this->nLimit; i++){
        this->weights[i].resize(this->nLimit);
        for(int j = 0; j < this->nLimit; j++) {
            this->weights[i][j] = INT_MAX;
        }
    }
}

void Graph ::addNode(int id) {
    if(this->nCount < this->nLimit) {
        this->nodes.emplace_back(Node(id));
        this->nCount += 1;
        this->parents.emplace_back(-1);
        this->paths.emplace_back(0);
        this->children.resize(nCount);
        this->dist.resize(this->nCount);
        this->fathers.reserve(this->nCount);
    }
}

void Graph::addEdgeWeight(int a, int b, int weight) {
    a--; b--;
    if(this->eCount < this->eLimit && a >= 0 && b >= 0 && a < nCount && b < nCount) {
        Node * c = &this->nodes[a];
        Node * d = &this->nodes[b];
        edge temp{c, d};
        this->edges.emplace_back(temp);
        this->nodes[a].neighbors.emplace_back(d);
        this->nodes[b].neighbors.emplace_back(c);
        this->weights[a][b] = weight;
        this->weights[b][a] = weight;
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

void Graph::BellmanFordStart(int pos) {
    cout << "Shortest paths using Bellman Ford algorithm:\n";
    BellmanFord(pos);
    for(const auto& node : this->nodes) {
        cout << node.id << "\t" << this->dist[node.id - 1] << endl;
    }
}

bool Graph::BellmanFord(int pos) {
    std::fill(this->fathers.begin(), this->fathers.end(), -1);
    this->dist.resize(this->nCount);
    for(const auto& node : this->nodes) {
        this->dist[node.id - 1] = INT_MAX;
    }

    this->dist[pos] = 0;
    this->fathers[pos] = 0;
    int i = 0;
    bool ok; // volt kozelites vagy sem

    do {
        ok = false;
        for(const auto& edg : this->edges) {
            int u = edg.first->id - 1;
            int v = edg.second->id - 1;
            if(this->dist[u] + this->weights[u][v] < this->dist[v] && this->dist[u] != INT_MAX) {
                this->fathers[v] = u;
                this->dist[v] = this->dist[u] + this->weights[u][v];
                ok = true;
            }
        }
        ++i;

    } while (ok && i < this->nCount);

    if(ok && i == this->nCount) {
        return false;
    }
    return true;
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

    int temp;
    while(fin >> n >> m >> temp) {
        graph.addEdgeWeight(n, m, temp);
    }

    return graph;
}
