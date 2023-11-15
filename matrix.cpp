#include "matrix.h"

Matrix::Matrix()
{
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
    if (num_cols != 0 && num_rows != col_data.size()) {
        std::cout << "COL SIZE MISMATCH, CBA" << std::endl;
        return;
    }
    std::cout << "num_cols=" << num_rows << std::endl;
    std::cout << "col_data=" << col_data.size() << std::endl;
    for (size_t i = 0; i < col_data.size(); i++) {
        data.insert(data.begin() + 2 * (i + 1) + i, col_data[i]);
    }

    num_cols = num_cols + 1;
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
    std::cout << "---------------------" << std::endl;
    for (auto& x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
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

