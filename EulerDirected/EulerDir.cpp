//
// Created by Orsi on 12/25/2021.
//

#include "EulerDir.h"

Graph::Graph(int nLimit, int eLimit) : nLimit(nLimit), eLimit(eLimit) {
    this->adj.resize(this->nLimit);
}

/* Function to add new node to graph */
void Graph::addNode(int id) {
    if(this->nCount < this->nLimit)
    {
        this->nodes.emplace_back(Node(id));
        this->nCount++;
    }
}

/* Function to add new edge to graph */
void Graph::addEdge(int a, int b) {
    a--; b--;
    if(this->eCount < this->eLimit && a >= 0 && b >= 0 && a < nCount && b < nCount)
    {
        Node* c = &this->nodes[a];
        Node* d = &this->nodes[b];
        this->nodes[a].out_neighbors.emplace_back(d);
        this->nodes[b].in_neighbors.emplace_back(c);
        this->adj[a].emplace_back(b);
        eCount++;
    }
}

/* Depth first search */
/*  parameters
 * v - visited array
 * x - start points
 * out - boolean to decide if we should check the vertex's in or out neighbors */
void Graph::dfs(vector<bool>& v, int x, bool out) {
    v[x] = true;

    if(out) {
        for(auto& i : this->nodes[x].out_neighbors) {
            if(!v[i->id - 1]) {
                dfs(v, i->id - 1, out);
            }
        }
    } else {
        for(auto& i : this->nodes[x].in_neighbors) {
            if(!v[i->id - 1]) {
                dfs(v, i->id - 1, out);
            }
        }
    }
}

/* Function to check if a directed graph is connected or not */
bool Graph::isConnected()
{
    vector<bool> vis1;
    vis1.resize(this->nCount);
    std::fill(vis1.begin(), vis1.end(), false);
    dfs(vis1, 0, true); // call for correct direction (go through the out neighbors)

    vector<bool> vis2;
    vis2.resize(this->nCount);
    std::fill(vis2.begin(), vis2.end(), false);
    dfs(vis2, 0, false); // call for reverse direction (in neighbors)

    // if any vertex is not visited in any direction the graph is not connected
    for(int i = 0; i < this->nCount; i++) {
        if(!vis1[i] && !vis2[i]) {
            return false;
        }
    }

    return true;
}

/* Check if a directed graph is Eulerian or not */
int Graph::isEuler()
{
    // check if the graph is connected otherwise return 0 -> the graph does not contain eulerian circuit or path
    if (!isConnected()){
        return 0;
    }

    bool eulerPath = true, eulerCircuit = true;

    /*
     * first vertex: nr. of out_neighbors - nr. of in_neighbors = 1
     * last vertex: nr. of in_neighbors - nr. of out_neighbors = 1
     * */
    if(this->nodes[0].out_neighbors.size() - this->nodes[0].in_neighbors.size() != 1 ||
       this->nodes[this->nCount - 1].in_neighbors.size() - this->nodes[this->nCount - 1].out_neighbors.size() != 1) {
        eulerPath = false;
    }

    // if the graph contains an Eulerian circuit all of its vertexes in and out neighbors should be equal
    for(int i = 0; i < this->nCount; i++) {
        if (this->nodes[i].out_neighbors.size() != this->nodes[i].in_neighbors.size()) {
            eulerCircuit = false;

            if(i != 0 && i != this->nCount - 1) {
                eulerPath = false;
            }
        }
    }

    if(eulerCircuit) {
        return 2;
    }

    if(eulerPath) {
        return 1;
    }

    return 0;
}

/* Find and print euler path or circuit */
void Graph::findEuler()
{
    // edge_count represents the number of edges of a vertex
    unordered_map<int, int> edge_count;
    for(int i = 0; i < this->nCount; i++) {
        edge_count[i] = this->adj[i].size();
    }

    // if the graph is empty
    if(this->nCount == 0) {
        return;
    }

    stack<int> currentPath;
    vector<int> circuit; // to store the final path / circuit
    currentPath.push(0);
    int currentVertex = 0; // we can start from any point

    while(!currentPath.empty()) {
        if(edge_count[currentVertex]) { // if there are more edges
            currentPath.push(currentVertex);
            int nextVertex = this->adj[currentVertex].back(); // find the next vertex
            edge_count[currentVertex] -= 1; // remove the edge
            this->adj[currentVertex].pop_back();
            currentVertex = nextVertex; // move to the next vertex
        } else {
            circuit.emplace_back(currentVertex);
            currentVertex = currentPath.top();
            currentPath.pop();
        }
    }

    // print the circuit vector in reverse order
    for(int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i] + 1;
        if(i) {
            cout << " -> ";
        }
    }
}

/* Function to sort the neighbors of each vertex */
void Graph::sortNodes() {
    for(int i = 0; i < this->nCount; i++) {
        std::sort(this->nodes[i].out_neighbors.begin(), this->nodes[i].out_neighbors.end());
        std::sort(this->nodes[i].in_neighbors.begin(), this->nodes[i].in_neighbors.end());
    }
}

/* Function to read graph (array of edges) from file */
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

    graph.sortNodes();

    return graph;
}