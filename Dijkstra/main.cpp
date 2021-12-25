#include "Dijkstra.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.dijkstra(0);
}