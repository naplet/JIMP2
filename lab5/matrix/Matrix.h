

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <regex>
#include <stdlib.h>
#include <sstream>
namespace algebra {
    class Matrix {
    public:
        Matrix();

        ~Matrix();

        Matrix(int R, int C);

        Matrix(const Matrix &Ptr);

        Matrix(std::string Text);

        Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list);

        int GetCols();

        int GetRows();

        std::complex<double>** GetMatrix();

        int SetElement(int R, int C, double Value);

        Matrix Add(Matrix Matrix_ToAdd);

        Matrix Sub(Matrix Matrix_ToSub);

        Matrix Mul(const Matrix &Matrix_ToMul);

        Matrix Mul(std::complex<double> Number);

        Matrix Div(Matrix matrix);

        Matrix Div(std::complex<double> Number);

        Matrix Pow(int Number);

        std::string Print();
        std::pair<size_t, size_t> Size();

    private:
        int Cols;
        int Rows;
        std::complex<double> **Matrix_Complex;

    };
}
#endif //JIMP_EXERCISES_MATRIX_H
