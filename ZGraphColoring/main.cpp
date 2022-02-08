#include "Coloring.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
//    graph.PrimS(1); // Greedy algorithm
    graph.Prim(1);
}