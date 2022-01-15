//
// Created by Orsi on 1/6/2022.
//

#include "Kruskal.h"

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
    }
}

void Graph::addEdgeWeight(int a, int b, int weight) {
    a--; b--;
    if(this->eCount < this->eLimit && a >= 0 && b >= 0 && a < nCount && b < nCount) {
        Node * c = &this->nodes[a];
        Node * d = &this->nodes[b];
        edge temp{c, d};
        weightedEdge tmp {temp, weight};
        this->wEdges.push(tmp);
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

void Graph::Kruskal() {
    vector<int> tree;
    tree.resize(this->nodes.size());
    for(int i = 0; i < this->nodes.size(); i++) {
        tree[i] = i;
    }
    int sum_weight = 0;

    while(!this->wEdges.empty()) {
        int a, b;
        a = tree[this->wEdges.top().first.first->id - 1];
        b = tree[this->wEdges.top().first.second->id - 1];
        if (a != b) {
            sum_weight += this->wEdges.top().second;
            cout << this->wEdges.top().first.first->id << " " << this->wEdges.top().first.second->id << " " << this->wEdges.top().second << endl;
            tree = unite(tree, a, b);
        }
        this->wEdges.pop();
    }

    cout << "Result: " << sum_weight << endl;
}

vector<int> Graph::unite(vector<int> tree, int a, int b) {
    for(int & i : tree) {
        if(i == b) {
            i = a;
        }
    }

    return tree;
}

Graph readGraphFromFile(const string& filename) {
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
