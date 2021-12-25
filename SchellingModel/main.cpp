#include "Schelling_model.h"

int main() {
    Schelling schelling(5, 0.4, 0.5, 3);
    int sameFor = 0;
    double lastSimilarity = 0;
    for (int i = 0; i < 10; ++i) {
        double temp = schelling.checkSatisfaction();
        if (temp == lastSimilarity) {
            sameFor++;
        } else {
            sameFor = 0;
            lastSimilarity = temp;
        }

        if (sameFor > 2 || lastSimilarity == 100.0) {
            break;
        }
    }
    cout << "Last similarity: " << lastSimilarity << "%";
    return 0;
}
