#include "Viterbi.h"
int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.DFS();
}