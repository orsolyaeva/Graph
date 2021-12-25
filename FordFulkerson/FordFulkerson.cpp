//
// Created by Orsi on 11/30/2021.
//

#include "FordFulkerson.h"

bool operator==(const Node& lhs, const Node& rhs)
{
    return lhs.id == rhs.id;
}

Graph::Graph(int nLimit, int eLimit) : nLimit(nLimit), eLimit(eLimit) {
    this->matrix.resize(this->nLimit + 1);
    for(int i = 0; i <= this->nLimit; i++) {
        this->matrix[i].resize(this->nLimit + 1);
    }
}

void Graph ::addNode(int id) {
    if(this->nCount <= this->nLimit) {
        this->nodes.emplace_back(Node(id));
        this->nCount += 1;
        this->parents.emplace_back(-1);
        this->paths.emplace_back(0);
        this->children.resize(nCount);
        this->dist.resize(this->nCount);
        this->fathers.resize(this->nCount + 1);
    }
}

void Graph::addEdgeWeight(int a, int b, int weight) {
    if(this->eCount < this->eLimit && a > 0 && b > 0 && a <= nCount && b <= nCount) {
        Node * c = &this->nodes[a - 1];
        Node * d = &this->nodes[b - 1];
        this->nodes[a - 1].neighbors.emplace_back(d);
        this->nodes[b - 1].neighbors.emplace_back(c);
        this->matrix[a][b].c = weight;
        this->matrix[b][a].c = weight;
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

void Graph::fordFulkerson() {
    cout << fordHelper(1, this->nCount);
}

int Graph::fordHelper(int pos, int t) {
    int fe = 0;
    int min;
    do {
        min = INT_MAX;
        findAugmentingPath(pos, min, t);
        fe += min;
//        cout << "Fe: " << fe << " | " << min << endl;
    } while (min != 0);
    return fe;
}

void Graph::findAugmentingPath(int pos, int &min, int t) {
    this->color.resize(this->nCount + 1);
    for(const auto& node : this->nodes) {
        this->color[node.id] = 0;
        this->fathers[node.id] = 0;
    }

    this->color[pos] = 1;
    this->fathers[pos] = 0;
    vector<int> q;
    q.push_back(pos);
    int u;

    while (!q.empty()) {
        u = q.front();
//        cout << "Debug #1: " << u << endl;
        for(auto & neighbor : this->nodes[u - 1].neighbors) {
            int v = neighbor->id;
            if (this->color[v] == 0) {
                // elore elek menten ekkor telitetlen
                if(this->matrix[u][v].c != -1 && this->matrix[u][v].f < this->matrix[u][v].c) {
                    this->color[v] = 1;
                    this->fathers[v] = u;
                    if(v == t) {
                        fixPath(t, min);
                        return;
                    }
                    q.push_back(v);
                    // vissza elek menten telitetlen
                } else if (this->matrix[v][u].c != -1 && this->matrix[v][u].f > 0) {
                    this->color[v] = 1;
                    this->fathers[v] = -u;
                    if(v == t) {
                        fixPath(t, min);
                        return;
                    }
                    q.push_back(v);
                }
            }
        }

        this->color[u] = 2;
        q.erase(q.begin());
    }
    min = 0;
}

// aparol apara haladva meghatarozza hogy melyik a legnagyobb ertek amelyyel a szoban forgo javitout menten
// novelheto a folyamertke
void Graph::fixPath(int u, int &min) {
    if (fathers[u] < 0) { // visszamutato
        int v = - this->fathers[u]; // apa pont
        if(min > this->matrix[u][v].f) {
            min = this->matrix[u][v].f;
        }
        fixPath(v, min);
        this->matrix[u][v].f = this->matrix[u][v].f - min; // csokkenti a folyamerteket
    } else if (this->fathers[u] > 0) { // eloremutato
        int v = this->fathers[u];
        if (min > this->matrix[v][u].c - this->matrix[v][u].f) {
            min = this->matrix[v][u].c - this->matrix[v][u].f;
        }
        fixPath(v, min);
        this->matrix[v][u].f = this->matrix[v][u].f + min; // noveli a folyamerteket
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
//        cout << n << " " << m <<  " " << temp << endl;
        graph.addEdgeWeight(n, m, temp);
    }
    return graph;
}

