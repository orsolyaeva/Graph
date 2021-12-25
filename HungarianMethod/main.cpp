#include "MaximalMatching.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.maximal_matching();
}