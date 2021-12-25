#include "heating_problem.h"

int main() {
    Graph graph = readGraphFile("graph.txt");
    int heatingCenter = graph.Floyd();
    cout << "Heating Center: " << heatingCenter + 1 << endl;
}