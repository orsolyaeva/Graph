//
// Created by Orsi on 11/11/2021.
//

#include "BreadthFirstSearch.h"

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
        this->paths.emplace_back(0);
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

void Graph::BFS(int src)
{
    vector<bool> visited;
    visited.resize(this->nCount);

    for(int i = 0;  i < this->nCount; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        parents[i] = -1;
    }

    list<int> queue;
    dist[src] = 0;
    queue.emplace_back(src);
    visited[src] = true;
    parents[src] = 0;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        resultBFS.push_back(u);

        cout << u + 1<< " ";

        // Iterate through the neighbors of the node
        for(auto& neighbor : this->nodes[u].neighbors)
        {
            if (!visited[neighbor->id - 1]) {
                visited[neighbor->id-1] = true;
                parents[neighbor->id-1] = u;
                dist[neighbor->id - 1] = dist[u] + 1;
                queue.push_back(neighbor->id-1);

//                if (neighbor->id-1 == dest)
//                    return true;
            }
        }
    }

    cout << endl;
    cout << "Shortest paths:" << endl;
    for(int i = 0; i < this->nCount; i++) {
//        cout << src + 1 << " ";
        getShortestPaths(i);
        cout << endl;
    }
}

void Graph::getShortestPaths(int i) const {
    if(this->parents[i] != 0) {
        getShortestPaths(this->parents[i]);
    }
    cout << i + 1 << " ";
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

