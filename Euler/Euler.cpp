//
// Created by Orsi on 12/8/2021.
//

#include "Euler.h"

Graph::Graph(int nLimit, int eLimit) : nLimit(nLimit), eLimit(eLimit) {
    this->matrix.resize(this->nLimit + 1);
    for(int i = 0; i < this->nLimit; i++) {
        this->matrix[i].resize(this->nLimit);
        std::fill(this->matrix[i].begin(), this->matrix[i].end(), 0);
    }
}

/* Function to add new node to the graph */
void Graph::addNode(int id) {
    if(this->nCount < this->nLimit)
    {
        this->nodes.emplace_back(Node(id));
        this->colors.emplace_back(0);
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
        this->nodes[a].neighbors.emplace_back(d);
        this->nodes[b].neighbors.emplace_back(c);
        this->matrix[a][b] += 1;
        this->matrix[b][a] += 1;
        eCount++;
    }
}

void Graph::sortNodes() {
    for(int i = 0; i < this->nCount; i++) {
        std::sort(this->nodes[i].neighbors.begin(), this->nodes[i].neighbors.end());
    }
}

/* Function to check if a directed graph is connected or not */
bool Graph::isConnected()
{
    fill(this->colors.begin(), this->colors.end(), 0);

    int pos = -1;
    // find the first vertex which is not isolated
    for(const auto& node : this->nodes )
        if (!node.neighbors.empty())
        {    pos = node.id-1;
            break;
        }

    // if all the nodes are isolated
    if (pos == -1)
        return true;

    eulerHelper(pos); // start DFS traversal

    for(const auto& node : this->nodes )
        // check if all non-zero degree nodes are visited
        if (this->colors[node.id - 1] == 0 && !node.neighbors.empty())
            return false;

    return true;
}

/* Function to help check if a graph is connected or not: based on DFS */
void Graph::eulerHelper(int pos)
{
    // mark the current node as visited
    this->colors[pos] = 1;

    list<int>::iterator i;
    for(auto& node : this->nodes[pos].neighbors)
    {
        // recur for all the vertices adjacent to this vertex
        if (this->colors[node->id-1] == 0) { eulerHelper(node->id - 1); }
    }
}

/* Check if an undirected graph is Eulerian or not */
int Graph::isEuler()
{
    // check if the graph is connected otherwise return 0 -> the graph does not contain eulerian circuit or path
    if (!isConnected())
        return 0;

    // count the number of vertexes with odd nr. of neighbors
    int odd = 0;
    for(const auto& node : this->nodes )
        if (node.neighbors.size() & 1)
            odd++;

    // if the graph contains more than 2 vertexes with odd degree
    if (odd > 2)
        return 0;

    return (odd)? 1 : 2;
}

void Graph::findEuler()
{
    int start = 0;
    // find first vertex with odd degree
    for(const auto& node : this->nodes )
        if (node.neighbors.size() & 1){
            start = node.id - 1; break;
        }
    pathHelper(start);
}

void Graph::pathHelper(int start)
{
    for(int v = 0; v < nCount; v++){
        // if the edge exists
        if(matrix[start][v] > 0){
            if(eCount <= 1 || isValidNextEdge(start, v)){
                cout << start + 1 << "-" << v + 1 << endl;
                // remove the edge
                matrix[start][v] -= 1;
                matrix[v][start] -= 1;
                eCount--;
                pathHelper(v);
            }
        }
    }
}

int Graph::countM(int i)  {
    this->colors[i] = 1;
    int count = 1;
    for(int j = 0; j < this->nCount; j++) {
        if(this->matrix[i][j] > 0 && this->colors[j] == 0) {
            count += countM(j);
        }
    }
    return count;
}

// check if the u-v edge is possibly the next edge in the euler circuit / path
bool Graph::isValidNextEdge(int u, int v) {
    // 2 methods:
    // 1) if v is the only neighbor of vertex u
    int count = 0;
    for(int i = 0; i < this->nCount; i++) {
        if(this->matrix[u][i] > 0) {
            count += 1;
        }
    }

    if(count == 1) {
        return true;
    }

    // 2) if u-v is a bridge
    this->colors.resize(this->nCount);
    std::fill(this->colors.begin(), this->colors.end(), 0);
    int count1 = countM(u);

    this->matrix[u][v] -= 1;
    this->matrix[v][u] -= 1;

    this->colors.resize(this->nCount);
    std::fill(this->colors.begin(), this->colors.end(), 0);
    int count2 = countM(u);

    this->matrix[u][v] += 1;
    this->matrix[v][u] += 1;

    return count1 <= count2;
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

    graph.sortNodes();

    return graph;
}