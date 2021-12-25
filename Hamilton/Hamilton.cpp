//
// Created by Orsi on 12/8/2021.
//

#include "Hamilton.h"

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
//        this->paths.emplace_back(0);
        this->children.resize(nCount);
        this->dist.resize(this->nCount);
        this->fathers.resize(this->nCount);
        this->matrix.resize(this->nCount + 1);
        this->matrix[id - 1].resize(this->nCount + 1);
        fill(this->matrix[id - 1].begin(), this->matrix[id - 1].end(), 0);
    }
}

void Graph::addEdge(int a, int b) {
    a--; b--;
    if(this->eCount < this->eLimit && a >= 0 && b >= 0 && a < nCount && b < nCount) {
        Node * c = &this->nodes[a];
        Node * d = &this->nodes[b];
        this->nodes[a].neighbors.emplace_back(d);
        this->nodes[b].neighbors.emplace_back(c);
        this->matrix[a][b] = 1;
        this->matrix[b][a] = 1;
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

void Graph::HamiltonCycle() {
    this->paths.emplace_back(0);

    this->color.resize(this->nCount);
    std::fill(this->color.begin(), this->color.end(), 0);

    this->color[0] = 1;

    HamiltonUtil(1);

    if(!hasCycle) {
        cout << "No Hamilton Cycle!" << endl;
        return;
    }
}

void Graph::printSolutions() {
    for(int i = 0; i < this->nCount; i++) {
        cout <<  this->paths[i] + 1 << " - ";
    }
    cout << this->paths[0] + 1 << endl;
}

bool Graph::HamiltonUtil(int pos) {
    if (pos == this->nCount) {
        if(this->matrix[this->paths[this->paths.size() - 1]][this->paths[0]] == 1) {
            this->paths.emplace_back(0);
            for(int i = 0; i < this->paths.size(); i++) {
                cout << this->paths[i] + 1 << " ";
            }
            cout << endl;
            this->paths.pop_back();
            hasCycle = true;
        }
        return false;
    }

    for(int v = 0; v  < this->nCount; v++) {
        if(promising(v, pos) && this->color[v] == 0) {
            this->paths.emplace_back(v);
            this->color[v] = 1;
            HamiltonUtil(pos + 1);
            this->color[v] = 0;
            paths.pop_back();
        }
    }

    return false;
}

bool Graph::promising(int v, int pos) {
   if(this->matrix[this->paths[pos - 1]][v] == 0) {
       return false;
   }
   for(int i = 0; i < pos; i++) {
       if(this->paths[i] == v) {
           return false;
       }
   }

   return true;
}
