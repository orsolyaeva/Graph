#include "BellmanFord.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.BellmanFordStart(0);
}