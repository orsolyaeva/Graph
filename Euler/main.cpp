#include "Euler.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
//    graph.printAdjList();

    int result = graph.isEuler();

    if(result == 0) {
        cout << "The graph does not contain an Euler tour / path.";
    } else if (result == 1) {
        cout << "The graph contains an Euler path." << endl;
        graph.findEuler();
    } else {
        cout << "The graph contains an Euler tour." << endl;
        graph.findEuler();
    }
}