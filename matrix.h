#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <string>
class Matrix {
    public:
        Matrix();
        void setWhereInputsEnd(int idx); // 0 -> first col is inputs, 1->second col is inputs, etc...
        void addColumn(std::vector<float> col_data);
        void addRow(std::vector<float> row_data);
        void printMatrix();
        std::vector<float> getCol(int col_idx);
         std::vector<float> getRow(int row_idx);
        float getCost(std::vector<float> weights_and_b);
        Matrix multiply(Matrix other);
        void initializeWithZeros(int num_rows, int num_cols);
        float& at(int row, int col);
        int getNumCols() {
            return num_cols;
        }
        int getNumRows() {
            return num_rows;
        }
    private:
        std::vector<float> data;
        int num_rows;
        int num_cols;
        int input_delimiter;
};


#endif