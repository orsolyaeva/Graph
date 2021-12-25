//
// Created by Orsi on 11/25/2021.
//

#include "heating_problem.h"

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

int Graph::Floyd() {
    vector<vector<int>> dist;
    dist.resize(this->nCount);
    for(int i = 0; i < this->nCount; i++) {
        dist[i].resize(this->nCount);
    }

    vector<vector<int>> ue;
    ue.resize(this->nCount);
    for(int i = 0; i < this->nCount; i++) {
        ue[i].resize(this->nCount);
    }

    for(int i = 0; i < this->nCount; i++) {
        for(int j = 0; j < this->nCount; j++) {
            ue[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < this->nCount; i++) {
        for(int j = 0; j < this->nCount; j++) {
            dist[i][j] = this->weights[i][j];

            if(i == j) {
                ue[i][j] = 0;
            } else if (weights[i][j] != INT_MAX) {
                ue[i][j] = i + 1;
            } else {
                ue[i][j] = -1;
            }
        }
    }

    for(int k = 0; k < this->nCount; k++) {
        for(int i = 0; i < this->nCount; i++) {
            for(int j = 0; j < this->nCount; j++) {
                if(dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX &&
                dist[i][k] != INT_MAX)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    ue[i][j] = ue[k][j];
                }
            }
        }
    }

//    PrintSolution(dist, this->nCount);

    int minimum = INT_MAX, start = 0;
    for(int i = 0; i < this->nCount; i++) {
        int value = 0;
        for(int j = 0; j < this->nCount; j++) {
            if(dist[i][j] != INT_MAX) {
                value += dist[i][j];
            }
        }

        if(value < minimum) {
            minimum = value;
            start = i;
        }
    }

//    PrintSolution(ue, this->nCount);

    fstream fout("halozat.txt");

    for(int i = 0; i < this->nCount; i++) {
        fout << i + 1 << " " << ue[start][i] + 1 << endl;
    }

    return start;
}

void PrintSolution(vector<vector<int>> a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == INF) {
                cout << "INF" << " ";
            } else  {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
}
