//
// Created by Orsi on 11/30/2021.
//

#include "Dijkstra.h"

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
//        this->nodes[b].neighbors.emplace_back(c);
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

void Graph::dijkstra(int pos) {
    fill(this->fathers.begin(), this->fathers.end(), -1);
    cout << "Shortest paths using Dijkstra algorithm:\n";

    vector<int> queue;
    this->dist.resize(this->nCount);
    for(const auto& node : this->nodes) {
        queue.emplace_back(node.id - 1);
        this->dist[node.id - 1] = INT_MAX;
    }

    this->dist[pos] = 0;
    this->fathers[pos] = 0;

    while(!queue.empty()) {
        int u = getMinDistance(queue);
        auto it = std::find(queue.begin(), queue.end(), u);
        queue.erase(it);

        if (u == -1) {
            return;
        }
        for (const auto &node: this->nodes[u].neighbors) {
            if (find(queue.begin(), queue.end(), node->id - 1) != queue.end() &&
                (this->dist[u] + this->weights[u][node->id - 1] < this->dist[node->id - 1]) &&
                this->dist[u] != INT_MAX && this->weights[u][node->id - 1] != INT_MAX) {
                this->fathers[node->id - 1] = u;
                this->dist[node->id - 1] = this->dist[u] + this->weights[u][node->id - 1];
            }
        }
    }

    for(const auto& node : this->nodes) {
        cout << node.id << "\t" << this->dist[node.id - 1] << endl;
    }
}

int Graph::getMinDistance(vector<int> queue) {
    int min = INT_MAX, min_index = -1;
    for(int i = 0; i < this->nCount; i++){
        if(find(queue.begin(), queue.end(), i) != queue.end() && this->dist[i] <= min) {
            min = this->dist[i];
            min_index = i;
        }
    }

    return min_index;
}
