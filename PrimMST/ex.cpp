//
// Created by Orsi on 1/7/2022.
//

#include "ex.h"

//
// Created by Orsi on 1/6/2022.
//

#include "exam.h"

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
    cout << this->nCount << " " << this->eCount << endl;
    for(const auto& node: this->nodes) {
        for(auto& pair : adj[node.id - 1]) {
            cout << node.id << " " << pair.first + 1 << " " << pair.second << endl;
        }
    }
}

/* Greedy algorithm, in every step we add the minimal weighted edge */
void Graph::PrimS(int src) { // src = root, start point
    std::fill(this->dist.begin(), this->dist.end(), INF);
    std::fill(this->parents.begin(), this->parents.end(), -1);
    priority_queue<edgePair, vector<edgePair>, greater<>> pq; // sort point by weight

    vector<bool> inMST(this->nCount, false); // check if node is in MST or not

    this->dist[src] = 0; // set root's distance from root to 0
    pq.push(make_pair(0, src)); // the root's weight is equal to 0

    while(!pq.empty()) {
        int u = abs(pq.top().second); // get second value which is the smallest value
        pq.pop(); // delete node from queue

        if(inMST[u]){ // if the point is not already in the MST
            continue;
        }

        inMST[u] = true;

        for(auto & pair : adj[u]) { // go through its neighbors
            int v = pair.first; // get its pair (if edge is a -b then b)
            int weight = pair.second; // get the value

            if(!inMST[v] && this->dist[v] > weight) { // if v is not in the MST and its weight is smaller than the distance
                this->dist[v] = weight;
                pq.push(make_pair(this->dist[v], v)); // weight + v
                this->parents[v] = u;
                cout << v  + 1 << " ";
            }
        }
    }

    for(int i = 1; i < this->nCount; i++){
        cout << this->parents[i] + 1 << " " << i + 1 << endl;
    }
}


/* Expanded Prim algorithm */
void Graph::Prim(int src, const string& output) {
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
        int i = getMinCut(cEdges, attachedEdge); // get minimum edge index from the actual cut
//        cout << cEdges[i].first.first->id << " " << cEdges[i].first.second->id << " " << cEdges[i].second << endl;
        this->directFriendship.emplace_back(cEdges[i].first.first->id, cEdges[i].first.second->id);
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

    ofstream fout(output);

    if (!fout) {
        cout << "Something went wrong with the output file!";
        exit(2);
    }

    fout << "a) Minimum weight: " << total_weight << endl;

    fout << "b) Direct Friendships" << endl;
    for(const auto & fs : this->directFriendship) {
        fout << fs.first << " " << fs.second << endl;
    }
}

int Graph::getMinCut(const vector<weightedEdge>& v, const vector<int>& attached) {
    for(int i = 0; i < this->eCount; i++) {
        if(this->cuts[i] == 1 && this->attachedEdge[i] == 0) {
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
//    fin >> n >> m;
    fin >> n;
    m = n * (n - 1) / 2;

    Graph graph(n, m);

    for(int i = 1; i <= n; i++){
        graph.addNode(i);
    }

    vector<int> array;

    int temp;
    while(fin >> temp) {
//        graph.addEdgeWeight(n, m, temp);
        array.emplace_back(temp);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int weight = abs((i - j)) * abs((array[i] - array[j]));
            graph.addEdgeWeight(i + 1, j + 1, weight);
        }
    }

    return graph;
}
