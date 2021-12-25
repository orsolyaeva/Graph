#include "DepthFirstSearch.h"

int main() {
    Graph graph = readGraphFile("input.txt");
    graph.DFS();
}
