#include "Hamilton.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.HamiltonCycle();
}