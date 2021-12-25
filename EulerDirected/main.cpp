#include "EulerDir.h"

int main() {
    Graph graph = readGraphFile("graph.txt");

    int res = graph.isEuler();
    if (res == 0) { cout << "The graph does not contain Eulerian path or circuit." << endl; }
    else if (res == 1) {
        cout << "The graph contains an Eulerian path." << endl;
        graph.findEuler();
    } else {
        cout << "The graph contains an Eulerian circuit." << endl;
        graph.findEuler();
    }
}
