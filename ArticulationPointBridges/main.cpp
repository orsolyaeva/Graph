#include "AP_Bridges.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.getArticulationPoints();
    graph.getBridges();
    return 0;
}
