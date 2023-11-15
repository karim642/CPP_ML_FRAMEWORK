#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
class Matrix {
    public:
        Matrix();
        void setWhereInputsEnd(int idx); // 0 -> first col is inputs, 1->second col is inputs, etc...
        void addColumn(std::vector<float> col_data);
        void addRow(std::vector<float> row_data);
        void printMatrix();
        int getCost(std::vector<float> weights_and_b);
    private:
        std::vector<float> data;
        int num_rows;
        int num_cols;
        int input_delimiter;
};


#endif