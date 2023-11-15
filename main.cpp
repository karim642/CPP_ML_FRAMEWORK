#include <iostream>
#include <vector>
#include <random>
#include "time.h"
float training_data[5][2] = {
        {0, 42},
        {1, 24},
        {2, 52},
        {3, 23},
        {4, 42}
};

// w1*x1 + + b = y

float get_cost(float w1, float w2, float b) {
    float cost = 0;
    for (int i = 0; i < 5; i++) {
        float expected = training_data[i][1];
        float computed = w1 * training_data[i][0] + w2 * training_data[i][0] + b;
        float distance = (computed - expected)*(computed - expected);      
        cost = cost + distance;   
    }
    return cost;
}


void learn(float& w1, float& w2, float& b, float h, float learning_rate) {
    float test = get_cost(w1, w2, b);
    float dw1 = (get_cost(w1 + h, w2, b) - test)/h;
    float dw2 = (get_cost(w1, w2 + h, b) - test)/h;
    float db = (get_cost(w1, w2, b + h) - test)/h;
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
    srand(time(0));
    float w1 = rand_float();
    float w2 = rand_float();
    float b = rand_float();
    float h = 0.000001;
    float learning_rate = 0.00001;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "start cost=" << get_cost(w1, w2, b) << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    for (int i = 0; i < 1000 * 1000; i++) {
        learn(w1, w2, b, h, learning_rate);
    }
    std::cout << "end cost=" << get_cost(w1, w2, b) << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "model prediction: " << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "x  |  y" << std::endl;
    std::cout << "-------" << std::endl;
    for (unsigned int i = 0; i < 5; i++) {
        std::cout << training_data[i][0] << "  |  " << w1 * training_data[i][0] + w2 * training_data[i][0] + b << std::endl;
    }
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "w1=" << w1 << std::endl;
    std::cout << "w2=" << w2 << std::endl;
    std::cout << "b=" << b << std::endl;
    return 0;
}
