//
// Created by Orsi on 11/30/2021.
//

#include "Viterbi.h"


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

    reverse(this->topological.begin(), this->topological.end());
    cout << "Topological order: ";
    for(auto& node : this->topological) {
        cout << node + 1 << " ";
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
    this->topological.emplace_back(u);
}

void Graph::Viterbi(int s) {
    this->dist.resize(this->nCount);
    this->fathers.resize(this->nCount);
    for(int i = 0; i < this->nCount; i++) {
        this->dist[i] = INT_MAX;
    }

    this->dist[s] = 0;
    this->fathers[s] = 0;
    int i = 0;

    while (this->topological[i] != s) {
        i += 1;
    }

    for(int j = i; j < this->nCount; j++) {
        int u = this->topological[j];

        for(auto & neighbor : this->nodes[u].neighbors) {
            if(this->dist[u] + this->weights[u][neighbor->id - 1] < this->dist[neighbor->id - 1] && this->weights[u][neighbor->id - 1] != INT_MAX
            && this->dist[u] != INT_MAX) {
                this->fathers[neighbor->id - 1] = u;
                this->dist[neighbor->id - 1] = this->dist[u] + this->weights[u][neighbor->id - 1];
            }
        }
    }

    for(int j = 0; j < this->nCount; j++) {
        cout << j + 1 << " " << this->dist[j] << endl;
    }
}
