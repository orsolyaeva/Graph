//
// Created by Orsi on 10/20/2021.
//

#include "Schelling_model.h"

Schelling::Schelling(int size, double emptyRatio, double similarityRatio, int t) {
    this->size = size;
    this->t = t;

    // Make a temporary array to store the right amount of each number
    vector<int> values;
    int fullSize = size * size;
    values.resize(fullSize);
    // Fill the array with 2s
    fill(values.begin(), values.end(), 2);
    // Fill the array with 1s but leave the needed amount of 2s at the end
    int length = fullSize - fullSize *(1 - emptyRatio) * similarityRatio;
    fill_n(values.begin(), length, 1);
    // Fill the array with 0s but leave the needed amount of 1s and 2s at the end
    fill_n(values.begin(), fullSize * emptyRatio, 0);
    // Randomly shuffle the array of numbers
    shuffle(values.begin(), values.end(), mt19937(random_device()()));

    this->data.resize(size);
    for (int i = 0; i < size; ++i) {
        this->data[i].resize(size);
        // Split the random number array into sub-arrays and copy them into the 2D array as rows
        copy(values.begin() + (i * size), values.begin() + (i * size) + size, this->data[i].begin());
    }
    // Print the 2D Array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << this->data[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if a given element of the 2D array is satisfied
bool Schelling::isSatisfied(int x, int y) {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        return false;
    }
    int correct = 0;
    if (y < size - 1) {
        if (data[x][y + 1] == data[x][y]) {
            correct++;
        }
        if (x < size - 1) {
            if (data[x + 1][y + 1] == data[x][y]) {
                correct++;
            }
        }
        if (x > 0) {
            if (data[x - 1][y + 1] == data[x][y]) {
                correct++;
            }
        }
    }
    if (y > 0) {
        if (data[x][y - 1] == data[x][y]) {
            correct++;
        }
        if (x < size - 1) {
            if (data[x + 1][y - 1] == data[x][y]) {
                correct++;
            }
        }
        if (x > 0) {
            if (data[x - 1][y - 1] == data[x][y]) {
                correct++;
            }
        }
    }
    if (x > 0) {
        if (data[x - 1][y] == data[x][y]) {
            correct++;
        }
    }
    if (x < size-1) {
        if (data[x + 1][y] == data[x][y]) {
            correct++;
        }
    }
    if (correct >= t) {
        return true;
    }
    return false;
}

double Schelling::checkSatisfaction() {
    // Create a vector to store the indices of all the unsatisfied elements
    vector<array<int, 2>> unsatisfied;
    // Create a vector to store the indices of all the free places
    vector<array<int, 2>> freePlaces;
    int satisfied = 0;
    double satisfiedPercentage = 0;
    int total = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // If the place isn't free
            if (data[i][j] != 0) {
                total++;
                // If element is unsatisfied add it to the unsatisfied array
                if (!isSatisfied(i, j)) {
                    unsatisfied.push_back({i, j});
                }
                    // Else increase the amount of the satisfied elements
                else {
                    satisfied++;
                }
            }
                // Else add the indices to the freePlaces array
            else {
                freePlaces.push_back({i, j});
            }
        }
    }
    // cout << total << " ~ " << satisfied << endl;

    // Calculate the percentage of satisfaction in the 2D Array
    satisfiedPercentage = (satisfied / (double)total) * 100;
    cout << "Satisfaction percentage: " << satisfiedPercentage << "%" << endl;
    cout << "---------------------" << endl;

    // Go through each unsatisfied element
    for (const auto& element : unsatisfied) {
        // Make a new variable that will store the indices of the current free place in the iteration below
        array<int, 2> freePair{};
        // Iterate through the free places
        for (int i = 0; i < freePlaces.size(); ++i) {
            freePair = freePlaces[i];
            // Move the unsatisfied element to the free place
            this->data[freePair[0]][freePair[1]] = this->data[element[0]][element[1]];
            this->data[element[0]][element[1]] = 0;
            // If the element won't be satisfied in the new place then revert the move
            if (!isSatisfied(freePair[0], freePair[1])) {
                this->data[element[0]][element[1]] = this->data[freePair[0]][freePair[1]];
                this->data[freePair[0]][freePair[1]] = 0;
            }
                // If the element is satisfied in the new position then remove the free place from the array
            else {
                freePlaces.erase(freePlaces.begin() + i);
                break;
            }
        }
    }
    // Print the newly generated 2D Array
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << this->data[i][j] << " ";
        }
        cout << endl;
    }
    return satisfiedPercentage;
}

