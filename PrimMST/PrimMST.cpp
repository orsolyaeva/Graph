//
// Created by Orsi on 11/4/2021.
//

#include "PrimMST.h"
bool operator==(const Node& lhs, const Node& rhs)
{
    return lhs.id == rhs.id;
}

Graph::Graph(int nLimit, int eLimit) : nLimit(nLimit), eLimit(eLimit) {
    adj = new list<edgePair>[this->nLimit];
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
        this->degrees.resize(this->nCount);
        std::fill(this->degrees.begin(), this->degrees.end(), 0);
    }
}

void Graph::addEdgeWeight(int a, int b, int weight) {
    a--; b--;
    this->attachedEdge.resize(this->eCount);
    if(this->eCount < this->eLimit && a >= 0 && b >= 0 && a < nCount && b < nCount) {
        Node * c = &this->nodes[a];
        Node * d = &this->nodes[b];
        edge temp{c, d};
        weightedEdge tmp {temp, weight};
        this->wEdges.push(tmp);
        this->nodes[a].neighbors.emplace_back(d);

        adj[a].emplace_back(b, weight);
        adj[b].emplace_back(a, weight);
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

/* Expanded Prim algorithm */
void Graph::Prim(int src) {
    vector<int> tree;
    tree.reserve(this->nCount);
    std::fill(tree.begin(), tree.end(), 0); // store the nodes already in tree
    std::fill(this->attachedEdge.begin(), this->attachedEdge.end(), 0); // store the attached edges

    tree[src] = 1; // src is already in tree
    this->fathers[src] = 0;
    vector<vector<int>> SZM; // neighbor matrix, adjacency matrix
    this->cuts.resize(this->eCount); // edge is part of the actual cut or not

    vector<weightedEdge> cEdges; // edges + weights
    while(!this->wEdges.empty()) {
        cEdges.push_back(this->wEdges.top()); // edges in graph
        this->wEdges.pop();
    }

    // store the i,j edge's rank from edge list
    SZM.resize(this->eCount); // initialize the adjacency matrix
    for(int i = 0; i < this->eCount; i++){
        SZM[i] = vector<int>(this->eCount);
    }

    for(int i = 0; i < this->eCount; i++) {
        edge e = cEdges[i].first; // get the first edge
        SZM[e.first->id - 1][e.second->id - 1] = i;
        SZM[e.second->id - 1][e.first->id - 1] = i;
        if(e.first->id - 1 == src || e.second->id - 1 == src) { // if the edge is connected to the root its part of the cut
            this->cuts[i] = 1;
        } else {
            this->cuts[i] = 0;
        }
    }

    int total_weight = 0; // count the total weight
    for(int step = 0; step < this->nCount - 1;  step++) {
        int i = getMinCut2(cEdges, attachedEdge, tree); // get minimum edge index from the actual cut
//        cout << cEdges[i].first.first->id << " " << cEdges[i].first.second->id << " " << cEdges[i].second << endl;

        this->degrees[cEdges[i].first.first->id - 1] += 1;
        this->degrees[cEdges[i].first.second->id - 1] += 1;

        this->attachedEdge[i] = 1;
        total_weight += cEdges[i].second;


//        for(int k = 0; k < this->eCount; k++){
//            cout << this->cuts[k] << " " << cEdges[k].first.first->id << " " << cEdges[k].first.second->id << endl ;
//        }

        // attach the minimum edge to the tree
        int attached;
        if(tree[cEdges[i].first.first->id - 1] == 1) {
            attached = cEdges[i].first.second->id - 1;
            this->fathers[attached] = cEdges[i].first.first->id - 1;
        } else {
            attached = cEdges[i].first.first->id - 1;
            this->fathers[attached] = cEdges[i].first.second->id - 1;
        }

//        cout << "ATT: " << attached + 1 << endl << endl;
        tree[attached] = 1;

        // add the new cuts to the cuts
        for(const auto& neighbor : this->nodes[attached].neighbors) {
            int sz_point = neighbor->id - 1;
            int sz_edge = SZM[attached][sz_point];
            if(tree[sz_point] == 1) {
                this->cuts[sz_edge] = 0;
            } else {
                this->cuts[sz_edge] = 1;
            }
        }
    }

    cout << total_weight << endl;

    for(const auto& it : this->degrees) {
        cout << it << " ";
    }
}

int Graph::getMinCut2(const vector<weightedEdge>& v, const vector<int>& attached, vector<int>& tree) {
    int weight = 0;
    bool ok = false;
    for(int i = 0; i < this->eCount; i++) {
        if(this->cuts[i] == 1 && this->attachedEdge[i] == 0) {
            weight = v[i].second;
            int already = tree[v[i].first.first->id - 1] == 1 ? v[i].first.first->id : v[i].first.second->id;
//            cout << "keres: " << already << " " << "w: " << weight;
            int maxi = INT_MIN, maxiindex = 0;
            int j;

            for(j = 0; j < this->eCount; j++) {
                if(this->cuts[j] == 1 && this->attachedEdge[j] == 0 && v[j].second == weight
                && (v[j].first.first->id == already || v[j].first.second->id == already)) {
                    ok = true;

                    if (v[j].first.first->id == already && maxi < v[j].first.second->id) {
//                        cout << "tal: " << v[j].first.second->id << " " << endl;
                        maxi = v[j].first.second->id;
                        maxiindex = j;
                    }

                    if (v[j].first.second->id == already && maxi < v[j].first.first->id) {
//                        cout << "tal: " << v[j].first.first->id << " " << endl;
//                        cout << maxi << endl;
                        maxi = v[j].first.first->id;
                        maxiindex = j;
                    }
                }
            }

            if (ok) {
//                cout << "ret: " << v[maxiindex].first.first->id << " " << v[maxiindex].first.second->id << endl;
                return maxiindex;
            }

            return i;
        }
    }
    return 0;
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

