#include "FordFulkerson.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.fordFulkerson();
}