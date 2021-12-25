//
// Created by Orsi on 10/20/2021.
//

#include "Girvan_Newman.h"

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

void Graph ::removeEdge(int x, int y) {
    int index = -1;
    // Check if the desired edge exists
    for (int i = 0; i < eCount; ++i) {
        if ((edges[i].first->id - 1 == x && edges[i].second->id - 1 == y) || (edges[i].first->id - 1 == y && edges[i].second->id - 1 == x)) {
            index = i;
            break;
        }
    }
    // If the edge was found
    if (index > -1) {
        int found = -1;
        // Remove the nodes from each other's neighbor list
        for (int i = 0; i < edges[index].first->neighbors.size(); ++i) {
            if (edges[index].first->neighbors[i]->id == edges[index].second->id) {
                found = i;
                break;
            }
        }
        if (found > - 1) {
            edges[index].first->neighbors.erase(edges[index].first->neighbors.begin() + found);
        }

        found = -1;
        // Remove the nodes from each other's neighbor list
        for (int i = 0; i < edges[index].second->neighbors.size(); ++i) {
            if (edges[index].second->neighbors[i]->id == edges[index].first->id) {
                found = i;
                break;
            }
        }
        if (found > - 1) {
            edges[index].second->neighbors.erase(edges[index].second->neighbors.begin() + found);
        }

        edges.erase(edges.begin() + index);
        eCount--;
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

// to work with disconnected graphs
void Graph::BFSUtil() {
    vector<bool> visited(this->nCount, false);
    for (int i = 0; i < this->nCount; i++)
        if (!visited[i])
            BFS(i, visited);
}

void Graph::BFS(int src, vector<bool> &visited)
{
    list<int> queue;
    for (int i = 0; i < this->nCount; i++) {
        visited[i] = false;
        this->weights[i].resize(nCount);
    }
    visited[src] = true;
    dist[src] = 0;
    paths[src] = 1;
    queue.emplace_back(src);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        resultBFS.push_back(u);
        // Iterate through the neighbors of the node
        for(auto& neighbor : this->nodes[u].neighbors)
        {
            // If the neighbor wasn't visited yet add the current node as it's parent
            if (!visited[neighbor->id - 1]) {
                visited[neighbor->id-1] = true;
                parents[neighbor->id-1] = u;
                queue.push_back(neighbor->id-1);
            }

            // If the neighbor is the descendant of the current node
            if (dist[neighbor->id - 1] > dist[u] + 1) {
                dist[neighbor->id-1] = dist[u] + 1;
                paths[neighbor->id-1] = paths[u];
            }

            // If the neighbor it's the direct descendant of the current node
            else if (dist[neighbor->id-1] == dist[u] + 1) {
                paths[neighbor->id-1] += paths[u];
            } else {
                sons[neighbor->id - 1].emplace_back(u);
                fathers[u].emplace_back(neighbor->id - 1);
            }
        }
    }
}


void Graph::Girvan() {
    // While there are still edges left
    while(eCount > 0) {
        // The 2D Array storing the final weights
        vector<vector<double>> finalWeights;
        finalWeights.resize(nCount); // koztessegi fokok

        // Filling the 2D Array with zeros
        for (int i = 0; i < this->nCount; ++i) {
            finalWeights[i].resize(nCount);
            std::fill(finalWeights[i].begin(), finalWeights[i].end(), 0);
        }

        for (int nNumber = 0; nNumber < nCount; ++nNumber) {
            // Initialize the default arrays and matrices before the run
            std::fill(this->dist.begin(), this->dist.end(), INT_MAX);
            std::fill(this->parents.begin(), this->parents.end(), -1);
            std::fill(this->paths.begin(), this->paths.end(), 0);
            for (int i = 0; i < this->nCount; ++i) {
                std::fill(this->weights[i].begin(), this->weights[i].end(), 0);
            }
            fathers.clear();
            sons.clear();
            resultBFS.clear();
            fathers.resize(this->nCount);
            sons.resize(this->nCount);
            vector<bool> visited(this->nCount, false);

            // Run the BFS
            BFS(nNumber, visited);

            // Calculate the base betweenness of the edges
            for (int i = resultBFS.size() - 1; i >= 0; --i) {
                for (auto& father : fathers[resultBFS[i]]) {
                    this->weights[resultBFS[i]][father] = paths[father] / (double)paths[resultBFS[i]];
                }
            }

            // Calculate the final betweenness using the sum of the edges' connected to each node
            for (int i = this->resultBFS.size() - 1; i >= 0; --i) {
                if (!sons[resultBFS[i]].empty()) {
                    double weight = 1;
                    for (auto& son : sons[resultBFS[i]]) {
                        weight += weights[son][resultBFS[i]];
                    }
                    for (auto& father : fathers[resultBFS[i]]) {
                        this->weights[resultBFS[i]][father] = weight / (double)fathers[resultBFS[i]].size();
                    }
                }
            }

            // Adding the weights generated after the current BFS to the finalWeights
            for (int i = 0; i < this->nCount; ++i) {
                for (int j = 0; j < this->nCount; ++j) {
                    finalWeights[i][j] += this->weights[i][j];
                }
            }
        }
        // Finding the maximum value to remove
        double max = 0;
        for (int i = 0; i < this->nCount; ++i) {
            for (int j = 0; j < this->nCount; ++j) {
                if (finalWeights[i][j] > max) {
                    max = finalWeights[i][j];
                }
            }
        }
        // Printing the maximum betweenness
        cout<<"MAX BETWEENNESS: "<<max<<endl;
        cout<<"-------------"<<endl;
        // Removing the edges with the maximum betweenness
        for (int i = 0; i < this->nCount; ++i) {
            for (int j = 0; j < this->nCount; ++j) {
                if (fabs(finalWeights[i][j] - max) < 1E-3) {
                    cout << "Removing edge: " << i + 1 << " - " << j + 1 << endl;
                    finalWeights[j][i] = 0;
                    removeEdge(i, j);
                    removeEdge(j, i);
                }
            }
        }
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
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
