#include "matrix.h"
#include "matrix.cpp"
#include <iostream>
#include <vector>
#include <random>
#include "time.h"


float training_data[5][2] = {
        {0, 69},
        {1, 69},
        {2, 69},
        {3, 69},
        {4, 69}
};

// w1*x1 + + b = y

float get_cost(float w1, float w2, float b) {
    float cost = 0;
    
    for (int i = 0; i < 5; i++) {
        float x = training_data[i][0];
        float expected = training_data[i][1];
        float computed = w2 * x * x + w1 * x + b;
        float distance = (computed - expected)*(computed - expected);      
        cost = cost + distance;   
    }
    return cost;
}


void learn(float& w1, float& w2, float& b, float h, float learning_rate) {
    float d = get_cost(w1, w2, b);
    float dw1 = (get_cost(w1 + h, w2,  b) - d)/h;
    float dw2 = (get_cost(w1, w2 + h,  b) - d)/h;
    float db = (get_cost(w1,  w2, b + h) - d)/h;
    w1 = w1 - learning_rate * dw1;
    w2 = w2 - learning_rate * dw2;
    b = b - learning_rate * db;
}
float rand_float() {
    int a =  (float) rand();
    float b = (float) RAND_MAX;
    return a/b;
}
int main(void) {
    std::vector<float> test = {0.0, 69.0, 1.0, 69.0, 2.0, 69.0, 3.0, 69.0, 4.0, 69.0};
    srand(time(0));
    float w1 = rand_float();
    float w2 = rand_float();
    float b = rand_float();
    float h = 0.0001;
    float learning_rate = 0.0001;
    Matrix first;
    std::vector<float> a1 = {0.0, 69.0};
    std::vector<float> a2 = {1.0, 69.0};
    std::vector<float> a3 = {2.0, 69.0};
    std::vector<float> a4 = {3.0, 69.0};
    std::vector<float> a5 = {4.0, 69.0};
    std::vector<float> a6 = {1, 2, 3};
   //std::vector<float> aha = {4, 4, 4, 4, 4};
    first.addRow(a1);
    first.addRow(a2);
    first.addRow(a3);
    first.addRow(a4);
    first.addRow(a5);
   // first.addRow(a6);
   // first.addColumn(aha);
    first.printMatrix();
   return 0;
}
