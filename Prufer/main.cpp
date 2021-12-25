#include "Prufer.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.generateStatArray();
    graph.generatePruferCode();
    graph.printPruferCode();
    graph.decodePruferCode();
}
