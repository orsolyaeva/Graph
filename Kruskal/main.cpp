#include "Kruskal.h"

int main() {
    Graph graph = readGraphFromFile("graph.txt");
//    graph.printAdjList();
    graph.Kruskal();
}