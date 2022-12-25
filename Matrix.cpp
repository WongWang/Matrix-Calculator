#include "Matrix.h"

inline bool Matrix::is_same_size(const Matrix &rightSide) const
{
    return (rowCnt == rightSide.rowCnt && colCnt == rightSide.colCnt);
}

Matrix &Matrix::operator=(std::initializer_list<std::initializer_list<int>> &list)
{
    if (list.begin() == list.end())
        throw std::invalid_argument("Matrix in the initializer list cannot be empty");
    rowCnt = list.end() - list.begin();
    colCnt = list.begin()->end() - list.begin()->begin();
    for (auto rowPtr = list.begin(); rowPtr != list.end(); ++rowPtr)
    {
        std::vector<int> row;
        for (const int *entryPtr = rowPtr->begin(); entryPtr != rowPtr->end(); ++entryPtr)
        {
            row.emplace_back(*entryPtr);
        }
        matrix.emplace_back(row);
    }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &rightSide)
{
    if (!is_same_size(rightSide))
        throw std::invalid_argument("Two operands of the addition operator's must be of the same size");
    for (decltype(rowCnt) rowSubscript = 0; rowSubscript != rowCnt; ++rowSubscript)
    {
        for (decltype(colCnt) colSubscript = 0; colSubscript != colCnt; ++colSubscript)
        {
            matrix[rowSubscript][colSubscript] += rightSide.matrix[rowSubscript][colSubscript];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &rightSide)
{
    if (!is_same_size(rightSide))
        throw std::invalid_argument("Two operands of the subtraction operator's must be of the same size");
    for (decltype(rowCnt) rowSubscript = 0; rowSubscript != rowCnt; ++rowSubscript)
    {
        for (decltype(colCnt) colSubscript = 0; colSubscript != colCnt; ++colSubscript)
        {
            matrix[rowSubscript][colSubscript] -= rightSide.matrix[rowSubscript][colSubscript];
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &rightSide)//To be finished
{
    if (colCnt != rightSide.rowCnt)
        throw std::invalid_argument("Column number of the former matrix is not equal to row number of the latter matrix");
    Matrix ans;
    for (decltype(rowCnt) rowSubscript = 0; rowSubscript != rowCnt; ++rowSubscript)
    {
        for (decltype(colCnt) colSubscript = 0; colSubscript != colCnt; ++colSubscript)
        {
            matrix[rowSubscript][colSubscript] -= rightSide.matrix[rowSubscript][colSubscript];
        }
    }
    return *this;
}