//
// Created by Orsi on 10/21/2021.
//

#include "AP_Bridges.h"

bool operator==(const Node& lhs, const Node& rhs)
{
    return lhs.id == rhs.id;
}

Graph::Graph(int nLimit, int eLimit) : nLimit(nLimit), eLimit(eLimit) {
}

void Graph ::addNode(int id) {
    if(this->nCount < this->nLimit) {
        this->nodes.emplace_back(Node(id));
        this->colors.emplace_back(0);
        this->nCount++;
        this->levels.resize(this->nCount);
        this->fathers.resize(this->nCount);
        this->fathers[this->nCount-1] = -1;
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

// pos - actual point, level - actual level
int Graph::Articulation_Point(int pos, int level) {
    this->colors[pos] = 1;
    this->levels[pos] = level;
    int RFminVM = INT_MAX;
    int cut_sons = 0;
    int sons = 0;

    for(auto neighbor : this->nodes[pos].neighbors) {
        int UminVM = INT_MAX;
        if(this->colors[neighbor->id - 1] == 0) { // if the neighbor is the son of the pos
            sons++;
            this->fathers[neighbor->id - 1] = pos;
            UminVM = Articulation_Point(neighbor->id - 1, level + 1);
            if(UminVM < level) { // if there is a back edge from neighbor
                if(UminVM < RFminVM) {
                    RFminVM = UminVM;
                }
            }
            else {
                cut_sons ++;
            }
        } else {
            if(this->colors[neighbor->id - 1] == 1) {
                if(this->levels[neighbor->id - 1] < level - 1) {
                    if(this->levels[neighbor->id - 1] < RFminVM) {
                        RFminVM = this->levels[neighbor->id - 1];
                    }
                }
            }
        }
    }

    this->colors[pos] = 2;
    if(this->fathers[pos] >= 0) { // if pos is not the root
        if(cut_sons > 0) {
            this->possible_cuts.push_back({pos + 1, cut_sons});
        }
    } else { // if pos is the root
        if(sons > 1) {
            this->possible_cuts.push_back({pos + 1, sons});
        }
    }

    return RFminVM;
}

void Graph::getArticulationPoints() {
    this->Articulation_Point(0, 0);

    fill(this->fathers.begin(), this->fathers.end(), -1);
    fill(this->levels.begin(), this->levels.end(), 0);
    fill(this->colors.begin(), this->colors.end(), 0);

    cout << "Articulation points: " << endl;
    for(auto cut : this->possible_cuts) {
        cout << cut[0] << " " << cut[1] << endl;
    }
    cout << endl << endl;
}

int Graph::Bridge_Edges(int pos, int level) {
    this->colors[pos] = 1;
    this->levels[pos] = level;
    int RFminVM = INT_MAX;

    for(auto neighbor : this->nodes[pos].neighbors) {
        if(this->colors[neighbor->id - 1] == 0) {
            this->fathers[neighbor->id - 1] = pos;
            int UminVM = Bridge_Edges(neighbor->id - 1, level + 1);
            if(UminVM < level) {
                if(UminVM < RFminVM) {
                    RFminVM = UminVM;
                }
            }
        } else {
            if(this->colors[neighbor->id - 1] == 1) {
                if(this->levels[neighbor->id - 1] < level - 1) {
                    if(this->levels[neighbor->id - 1] < RFminVM) {
                        RFminVM = this->levels[neighbor->id - 1];
                    }
                }
            }
        }
    }

    this->colors[pos] = 2;
    if(this->fathers[pos] >= 0) { // if pos is not the root
       if(RFminVM == INT_MAX) {
           this->possible_bridges.push_back({this->fathers[pos] + 1, pos + 1});
       }
    }

    return RFminVM;
}

void Graph::getBridges() {
    this->Bridge_Edges(0, 0);

    cout << "Bridges: " << endl;
    for(auto bridge : this->possible_bridges) {
        cout << bridge[0] << " " << bridge[1] << endl;
    }
}


