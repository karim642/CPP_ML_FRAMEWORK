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

// y = w2 * x^2 + w1 * x + b

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
    //float w2 = rand_float();
    float b = rand_float();
    float h = 0.0001;
    float learning_rate = 0.0001;
    
    
    //for (int i = 0; i < 1000 * 1000; i++) {
    //    learn(w1, w2, b, h, learning_rate);
   // }
   // std::cout << "model prediction:" << std::endl;
    //for (size_t i = 0; i < 5; i++) {
     //   std::cout << "x=" << training_data[i][0] << " | y=" << w2 * training_data[i][0] * training_data[i][0] + w1 * training_data[i][0]  + b<< std::endl;
   // }
   Matrix A;
   A.addRow({0, 69});
   A.addRow({1, 69});
   A.addRow({2, 69});
   A.addRow({3, 69});
   A.addRow({4, 69});
   A.setWhereInputsEnd(0);
   std::vector<float> vec;
   vec.push_back(69);
   vec.push_back(0);
   float test1 = A.getCost(vec);
    std::cout << "cost=" << test1 << std::endl;
   return 0;
}
