//
// Created by Orsi on 12/25/2021.
//

#include "MaximalMatching.h"

Graph::Graph(int nLimit, int eLimit) : nLimit(nLimit), eLimit(eLimit) {
    this->matrix.resize(this->nLimit + 1);
    for(int i = 0; i < this->nLimit; i++) {
        this->matrix[i].resize(this->nLimit);
        std::fill(this->matrix[i].begin(), this->matrix[i].end(), 0);
    }
}

void Graph::addNode(int id) {
    if(this->nCount < this->nLimit)
    {
        this->nodes.emplace_back(Node(id));
        this->colors.emplace_back(0);
        this->nCount++;
        this->parents.resize(nCount);
        this->children.resize(nCount);
        this->touched.resize(nCount);
        this->left.resize(nCount);
        this->dist.resize(this->nCount);
        this->levels.resize(this->nCount);
        this->fathers.resize(this->nCount+1);
        this->fathers[this->nCount] = 0;
        this->weights.resize(nCount);
        this->weights[id-1].resize(nCount);
        this->paint.resize(this->nCount);
    }
}

void Graph::addEdge(int a, int b) {
    a--; b--;
    if(this->eCount < this->eLimit && a >= 0 && b >= 0 && a < nCount && b < nCount)
    {
        Node* c = &this->nodes[a];
        Node* d = &this->nodes[b];
        edge temp{c, d};
        this->edges.emplace_back(temp);
        this->nodes[a].neighbors.emplace_back(d);
        this->nodes[b].neighbors.emplace_back(c);
        this->matrix[a][b] = this->edgesM.size();
        this->matrix[b][a] = this->edgesM.size();
        this->edgesM.emplace_back(*(new edgeM(a, b)));
        eCount++;
    }
}

int Graph::twoColoring(int s) {
    std::fill(this->colors.begin(), this->colors.end(), 0);
    std::fill(this->paint.begin(), this->paint.end(), 0);
    this->colors[s] = 1;
    this->paint[s] = 1;
    int f1 = 1;
    int f2 = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        for(auto& neighbor : this->nodes[u].neighbors) {
            int v = neighbor->id - 1;
            if (this->colors[v] == 0) {
                this->colors[v] = 1;
                if(this->paint[u] == 1) {
                    this->paint[v] = 2;
                    f2 += 1;
                } else {
                    this->paint[v] = 1;
                    f1 += 1;
                }
                q.push(v);
            }
        }
        q.pop();
        this->colors[u] = 2;
    }

    if (f1 < f2) {
        return 1;
    } else {
        return 2;
    }
}

int Graph::findAugmentingPath(int s, int max_paint, int min_paint) {
    std::fill(this->colors.begin(), this->colors.end(), 0);
    std::fill(this->fathers.begin(), this->fathers.end(), 0);

    this->colors[s] = 1;
    this->fathers[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        for(auto& neighbor : this->nodes[u].neighbors) {
            int v = neighbor->id - 1;
            if (this->colors[v] == 0) {
                if(this->paint[v] == max_paint || this->paint[v] == -max_paint || this->paint[v] == -min_paint) {
                    this->colors[v] = 1;
                    this->fathers[v] = u;
                    q.push(v);

                    if(this->paint[v] == max_paint) {
                        return v;
                    }
                }
            }
        }
        q.pop();
        this->colors[u] = 2;
    }
    return -1;
}

void Graph::reverseAlternation(int i, int j) {
    int actual_edge  = this->matrix[j][this->fathers[j]];
    if(this->edgesM[actual_edge].p == 1) {
        this->edgesM[actual_edge].p = 0;
    } else {
        this->edgesM[actual_edge].p = 1;
    }

    if(this->fathers[j] != i) {
        reverseAlternation(i, this->fathers[j]);
    }
}

void Graph::maximal_matching() {
    int min_paint = twoColoring(0);
    int max_paint;
    if(min_paint == 1) {
        max_paint = 2;
    } else {
        max_paint = 1;
    }

    for(int i = 0; i < this->eCount; i++) {
        if((this->paint[this->edgesM[i].u] > 0) && (this->paint[this->edgesM[i].v] > 0)) {
            this->paint[this->edgesM[i].u] = -this->paint[this->edgesM[i].u];
            this->paint[this->edgesM[i].v] = -this->paint[this->edgesM[i].v];
            this->edgesM[i].p = 1;
        }
    }

//    for(int i = 0; i < this->nCount; i++) {
//        cout << this->paint[i] << " ";
//    }
//    cout <<  endl << "min: " << min_paint << endl;

    for(int i = 0; i < this->nCount; i++) {
        if(this->paint[i] == min_paint) {
            int j = findAugmentingPath(i, max_paint, min_paint);
            if (j == -1) {
                break;
            }  else {
                reverseAlternation(i, j);
                this->paint[i] = -this->paint[i];
                this->paint[j] = -this->paint[j];
            }
        }
    }

    for(int i = 0 ; i < this->eCount; i++) {
        if(this->edgesM[i].p == 1) {
            cout << this->edgesM[i].u + 1 << " " << this->edgesM[i].v + 1 << endl;
        }
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
