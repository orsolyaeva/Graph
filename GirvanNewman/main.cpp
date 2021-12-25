#include "Girvan_Newman.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    graph.Girvan();
}
