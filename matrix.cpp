#include "matrix.h"
#include <cmath>
Matrix::Matrix(){
    input_delimiter = 0;
    num_rows = 0;
    num_cols = 0;
}

void Matrix::setWhereInputsEnd(int idx)
{
    input_delimiter = idx;
}

void Matrix::addColumn(std::vector<float> col_data)
{

    if (num_rows != 0 && num_rows != col_data.size()) {
        std::cout << "COL SIZE MISMATCH, CBA" << std::endl;
        return;
    }
    if (num_cols == 0) {
        for(size_t i = 0; i < col_data.size(); i++) {
            data.push_back(col_data[i]);
        }
        num_cols = 1;
        num_rows = col_data.size();
    } else {
       for (size_t i = 0; i < col_data.size(); i++) {
        data.insert(data.begin() + 2 * (i + 1) + i, col_data[i]);
        }  
        num_cols = num_cols + 1;
    }
}

void Matrix::addRow(std::vector<float> row_data)
{
    if (num_cols != 0 && num_cols != row_data.size())
    {
        std::cout << "THIS ROW VECTOR DOESN'T FIT GG" << std::endl;
        return;
    }
    int counter = 0;
    for (size_t i = 0; i < row_data.size(); i++) {
        float element = row_data[i];
        data.push_back(element);
    }
    num_rows = num_rows + 1;
    if (num_cols == 0) {
            num_cols = num_cols + row_data.size();
    }
}

void Matrix::printMatrix()
{
    //std::cout << "---------------------" << std::endl;
   //// for (auto& x : data) {
   //     std::cout << x << " ";
    
    //std::cout << std::endl;
    std::cout << "[";
    for (size_t j = 0; j < num_rows; j++) {
        for (size_t i = 0; i < num_cols; i++) {
            if (i != num_cols - 1) {
                std::cout << data[i + j*num_cols] << " ";
            } else {
                std::cout << data[i + j*num_cols];
            }
        }
        if (j != num_rows - 1) {
            std::cout << std::endl; 
        }
    }

    std::cout << "]" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << num_rows << "x" << num_cols << std::endl;
    std::cout << std::endl;
}

std::vector<float> Matrix::getCol(int col_idx)
{
    std::vector<float> out;
    for (size_t i = 0; i < num_rows; i++) {
        out.push_back(data[col_idx + i * num_cols]);
    }
    return out;
}
std::vector<float> Matrix::getRow(int row_idx)
{
    std::vector<float> out;
    for (size_t i = 0; i < num_cols; i++) {
        out.push_back(data[row_idx + i * num_rows]);
    }
    return out;
}


Matrix Matrix::multiply(Matrix other)
{
    //this is on left
    //other is on right
    if (this->num_cols != other.num_rows) {
        std::cout << "INVALID MATRIX MULTIPLICATION, RETURNING EMPTY MATRIX" << std::endl;
        return Matrix();
    }
    Matrix out;
    int m = this->num_rows;
    int n = this->num_cols;
    int p = other.num_cols;
    out.initializeWithZeros(this->num_rows, other.num_cols);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < p; j++) {
            float sum = 0;
            for (size_t k = 0; k < n; k++) {
                sum = sum + this->at(i, k) * other.at(k, j);
            }
            out.at(i, j) = sum;
        }
    }
    return out;
}

void Matrix::initializeWithZeros(int nr, int nc)
{
    data.clear();
    num_rows = nr;
    num_cols = nc;
    for (size_t j = 0; j < num_rows; j++) {
        for (size_t i = 0; i < num_cols; i++) {
            data.push_back(0.0);
        }
    }
}

float &Matrix::at(int row, int col)
{
    // TODO: insert return statement here
    return data[row*num_cols + col];
}

float Matrix::getCost(std::vector<float> weights_and_b)
{
    //form is b + w1*x + w2*x^2 + ... + wn*x^n
    
    Matrix weights;
    weights.addRow(weights_and_b);
    Matrix de_augment;
    for (size_t i = 0; i <= input_delimiter; i++) {
        de_augment.addColumn(this->getCol(i));
    }
    Matrix expected;
    expected.addColumn(this->getCol(input_delimiter + 1));

    std::cout << "Inputs:" << std::endl;
    de_augment.printMatrix();
    std::cout << "weights:" << std::endl;
    weights.printMatrix();
    std::cout << "expected:" << std::endl;
    expected.printMatrix();
    float cost = 0;
    for (size_t k = 0; k < de_augment.num_cols; k++) {
       for (size_t i = 0; i < de_augment.num_rows; i++) {
            float x = de_augment.at(i, k);
            float exp = expected.at(i, 0);
            float computed = 0;
            for (size_t j = 0; j < weights.num_cols; j++) {
                computed = computed + weights.at(0, j)*powf(x, j);
            }
            float distance = (exp - computed)*(exp - computed);
            cost = cost + distance;
        } 
    }
    return cost;
}

/* float get_cost(float w1, float w2, float b) {
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
*/

