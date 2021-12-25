//
// Created by Orsi on 10/20/2021.
//

#ifndef LAB2_SCHELLING_MODEL_H
#define LAB2_SCHELLING_MODEL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <random>

using namespace std;

class Schelling {
private:
    int size{0};
    int t{3};
    vector<vector<int>> data;
    bool isSatisfied(int x, int y);
public:
    Schelling(int, double, double, int);
    double checkSatisfaction();
};


#endif //LAB2_SCHELLING_MODEL_H
