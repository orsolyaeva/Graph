#include "BreadthFirstSearch.h"

int main() {
    Graph graph = readGraphFile("input.txt");
    graph.BFS(0);
}
