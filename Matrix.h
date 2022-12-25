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
    int &operator[](std::size_t n);
    const int &operator[](std::size_t n) const;
    //Other operator-like functions
private:
    //Data member
    std::vector<std::vector<int>> matrix;//Store the matrix
    std::vector<int>::size_type rowCnt;//Matrix row count
    std::vector<int>::size_type colCnt;//Matrix column count
    //Private member functions
    bool is_same_size(const Matrix &rightSide) const;//Return true if two matrix is of the same size, otherwise return false
};

//Operator overloading
Matrix &operator<<(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator>>(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator+(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator-(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator*(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator==(const Matrix &leftSide, const Matrix &rightSide);
Matrix &operator!=(const Matrix &leftSide, const Matrix &rightSide);
#endif
