#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>

struct Matrix
{
public:
    //Operator overloading
    Matrix &operator=(std::initializer_list<std::initializer_list<int>> &list);
    Matrix &operator+=(const Matrix &rightSide);
    Matrix &operator-=(const Matrix &rightSide);
    Matrix &operator*=(const Matrix &rightSide);
    std::vector<int> &operator[](std::vector<std::vector<int>>::size_type n);
    const std::vector<int> &operator[](std::vector<std::vector<int>>::size_type n) const;
    //Other operator-like functions
    std::vector<int> get_row(std::vector<int>::size_type rowNumber) const;
    std::vector<int> get_column(std::vector<int>::size_type columnNumber) const;
    static int dot_product(const std::vector<int> &leftSide, const std::vector<int> &rightSide);
private:
    //Data member
    std::vector<std::vector<int>> matrix;//Store the matrix
    std::vector<int>::size_type rowCnt;//Matrix row count, when the matrix is m by n, this will be m
    std::vector<int>::size_type colCnt;//Matrix column count, when the matrix is m by n, this will be n
    //Private member functions
    bool is_same_size(const Matrix &rightSide) const;//Return true if two matrices are of the same size, otherwise return false
};

//Inline member functions' defination
/*Private functions*/
inline bool Matrix::is_same_size(const Matrix &rightSide) const
{
    return (rowCnt == rightSide.rowCnt && colCnt == rightSide.colCnt);
}

/*Public functions*/
inline std::vector<int> Matrix::get_row(std::vector<int>::size_type rowNumber) const
{
    if (rowNumber > rowCnt)
        throw std::invalid_argument("Row number exceeded the matrix's row number");
    return matrix[rowNumber - 1];
}

inline std::vector<int> Matrix::get_column(std::vector<int>::size_type columnNumber) const
{
    if (columnNumber > colCnt)
        throw std::invalid_argument("Column number exceeded the matrix's column number");
    std::vector<int> ret_val;
    for (std::vector<int>::size_type i = 1; i != rowCnt + 1; ++i)
        ret_val.emplace_back(matrix[i - 1][columnNumber - 1]);
    return ret_val;
}

inline int Matrix::dot_product(const std::vector<int> &leftSide, const std::vector<int> &rightSide)//Dimensions of the two vectors must be equal! It should be checked before the function is called
{
    int ret_val;
    for (std::vector<int>::size_type i; i != leftSide.size(); ++i)
    {
        ret_val += leftSide[i] * rightSide[i];
    }
    return ret_val;
}

//Operator overloading
Matrix &operator<<(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator>>(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator+(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator-(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator*(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator==(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator!=(const Matrix &leftSide, const Matrix &rightSide);
#endif
