//
// Created by Orsi on 10/20/2021.
//

#include "Prufer.h"

Graph::Graph() {
    this->pruferCode = {};
}

Graph::Graph(vector<int> pruferCode) : pruferCode(pruferCode){}

void Graph::addNode(int id){
    if(find(this->nodes.begin(), this->nodes.end(), id) == this->nodes.end())
    {
        this->nodes.push_back(id);
    }
}

void Graph::addEdge(int x, int y) {
    array<int, 2> tmp{x, y};
    if(find(this->edges.begin(), this->edges.end(), tmp) == this->edges.end())
    {
        this->edges.push_back(tmp);
    }
}

void Graph::generateStatArray() {
    this->statArray.resize(this->nodes.size() + 1);
    for(auto x : this->edges) {
        this->statArray.at(x[0])++;
        this->statArray.at(x[1])++;
    }
}

void Graph::generatePruferCode() {
    for(int i = 0; i < this->nodes.size() - 2; i++) {
        int min = INT_MAX, pos = 1;
        for(int j = 0; j < this->statArray.size(); j++) {
            if(this->statArray[j] < min && this->statArray[j] > 0) {
                min = this->statArray[j];
                pos = j;
            }
        }
        this->statArray[pos] = 0;
        for(auto edge : this->edges) {
            if(edge[0] == pos && pos > 0) {
                this->pruferCode.push_back(edge[1]);
            } else if (edge[1] == pos && pos > 0) {
                this->pruferCode.push_back(edge[0]);
            }
        }
    }
    this->generateStatArray();
}

void Graph::printPruferCode()
{
    for(int i : this->pruferCode)
    {
        cout << i <<" ";
    }
    cout<<endl;
}

void Graph::decodePruferCode(){
    for(int i = 0; i < this->pruferCode.size()+2; ++i)
    {
        this->addNode(i);
    }
    int temp;
    for(int i = 1; i < this->pruferCode.size(); ++i)
    {
        for(int j = 1; j < this->pruferCode.size()+2; ++j) {
            if (find(this->pruferCode.begin(), this->pruferCode.end(), j) == this->pruferCode.end()) {
                this->addEdge(j, this->pruferCode.front());
                temp = this->pruferCode.front();
                this->pruferCode.erase(this->pruferCode.begin());
                cout<<"last dropped: "<<temp<<" | added: "<<j<<endl;
                this->pruferCode.push_back(j);
//            cout<<this->pruferCode.back()<<endl;
            }
        }
    }
    for(int j = 1; j <= this->pruferCode.size()+2; ++j) {
        if(j == temp)
        {
            continue;
        }
        if (find(this->pruferCode.begin(), this->pruferCode.end(), j) == this->pruferCode.end()) {
            cout<<"added: "<<temp<<" "<<j<<endl;
            this->addEdge(temp, j);
        }
    }
    this->generateStatArray();
}

//void generatePruferCode(int ** arrayEdges, int * degree, int ** prufer, int n, int m) {
//    int min, temp;
//
//    *prufer = (int*)malloc((n - 2) * sizeof(int));
//    if(!*prufer) {
//        exit(5);
//    }
//
//    for(int i = 0; i < n - 2; i++) {
//        min = INT_MAX;
//
//        // megkeressuk a legkisebb cimkeju levelet a grafban
//        for(int j = 0; j < m; j++) {
//            if(arrayEdges[j][0] < min && degree[arrayEdges[j][0]] == 1) {
//                min = arrayEdges[j][0];
//                temp = j;
//            }
//            if(degree[arrayEdges[j][1]] == 1 && arrayEdges[j][1] < min) {
//                min = arrayEdges[j][1];
//                temp = j;
//            }
//        }
//
//        degree[arrayEdges[temp][0]] -= 1;
//        degree[arrayEdges[temp][1]] -= 1;
//
//        // a prufer kodba az eltavolitott elem apja kerul
//        if(degree[arrayEdges[temp][0]] == 0) {
//            (*prufer)[i] = arrayEdges[temp][1];
//        } else {
//            (*prufer)[i] = arrayEdges[temp][0];
//        }
//
//    }
//}

// fuggveny a prufer kod dekodolasara
//void decodePruferCode(int * prufer, int n, int m) {
//    int * vertices = (int*)calloc(n + 1, sizeof(int));
//    if(!vertices) {
//        exit(6);
//    }
//
//    // megnezzuk hogy minden csomopont hanyszor szerepel a prufer kodban
//    for(int i = 0; i < n - 2; i++) {
//        vertices[prufer[i] - 1] += 1;
//    }
//
//    printf("Graph: \n");
//    for(int i = 0; i < n - 2; i++) {
//        for(int j = 0; j < n; j++) {
//            // ha meg nem szerepel egyszer sem
//            if(vertices[j] == 0) {
//                vertices[j] = -1; // -1 re allitjuk, tehat mar benne van a dekodolt reszben
//                printf("%d %d\n", j + 1, prufer[i]);
//                vertices[prufer[i] - 1]--; // csokkentjuk az elofordulasat
//
//                break;
//            }
//        }
//    }
//
//    // kiiratjuk azt az utolso ponott amely nem szerepelt meg
//    for(int i = 0; i < n; i++) {
//        if(vertices[i] == 0) {
//            printf("%d ", i + 1);
//        }
//    }
//}

Graph readGraphFile(const string& filename) {
    ifstream fin(filename);
    if(!fin) {
        exit(1);
    }

    int n, m;
    fin >> n >> m;
    Graph graph;

    for(int i = 1; i <= n; i++){
        graph.addNode(i);
    }

    while(fin >> n >> m) {
        graph.addEdge(n, m);
    }

    return graph;
}

