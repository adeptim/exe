#pragma once

#include <vector>
#include <iostream>
/// @brief определение пространства имен
namespace math
{
     #ifdef MATH_DOUBLE_PRECISION_DEFINE
        typedef double real;
    #else
        typedef float real;
    #endif
    /// @brief класс Matrix
    class Matrix
    {
    private:
        /// @brief количество строк
        int cols_;
        /// @brief количество столбцов
        int rows_;
        /// @brief вектор хранения матриц
        std::vector<real> mvec_;

    public:
        /// @brief переменная для ввывода строки при печати
        std::string type="Matrix is:";

        /// @brief конструктор по умолчанию
        Matrix() {};
        /// @brief конструктор с заданными парамметрами
        /// @param rows
        /// @param cols
        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)){};

        /// @brief функции класса
        void print() const;
        int rows() const;
        int cols() const;

        /// @brief переопределение операторов
        /// @param матрица A
        /// @param матрица B
        /// @return матрица
        friend Matrix operator+(const Matrix &A, const Matrix &B);
        friend Matrix operator-(const Matrix &A, const Matrix &B);
        friend Matrix operator*(const Matrix &A, const Matrix &B);

        real &operator()(int row, int col);
        real operator()(int row, int col) const;

        Matrix &operator+=(const Matrix &M);
        Matrix &operator-=(const Matrix &M);
        Matrix &operator*=(int k);

        friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);
       friend std::istream &operator>>(std::istream &in, Matrix &matrix);
    };
}