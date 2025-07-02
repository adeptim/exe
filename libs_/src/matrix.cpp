#include "matrix.h"
#include <iostream>
#include <cmath>

using namespace math;
/// @brief переопределение оператора присваивания
/// @param row
/// @param col
/// @return mvec_
real &Matrix::operator()(int row, int col)
{
    if (row >= this->rows_)
    {
        std::cerr << "Matrix: row number out of bounds" << std::endl;
    }
    if (col >= this->cols_)
    {
        std::cerr << "Matrix: col number out of bounds" << std::endl;
    }

    int pos{0};

    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}
/// @brief  переопределение оператора присваивания постоянный
/// @param row
/// @param col
/// @return
real Matrix::operator()(int row, int col) const
{
    if (row >= this->rows_)
    {
        std::cerr << "Matrix: row number out of bounds" << std::endl;
        // return 0;
    }
    if (col >= this->cols_)
    {
        std::cerr << "Matrix: col number out of bounds" << std::endl;
        // return 0;
    }

    int pos{0};

    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

void Matrix::print() const
{
    std::cout << this->type << std::endl;
}

/// @brief сложение матриц
/// @param матрица A
/// @param матрица B
/// @return матрица М
Matrix math::operator+(const Matrix &A, const Matrix &B)
{

    /// проверка равенства строк и столбцов
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can't be added!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.cols_, A.rows_);
    M.type = "Sum of matrices m and m1 is:";
    for (int i = 0; i < M.mvec_.size(); ++i)
    {
        M.mvec_.at(i) = A.mvec_.at(i) + B.mvec_.at(i);
    }
    return M;
}
/// @brief Матрица вычитания
/// @param матрица A
/// @param матрица B
/// @return матрица М
Matrix math::operator-(const Matrix &A, const Matrix &B)
{
    /// проверка равенства строк и столбцов
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrices can't be subtracted!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.cols_, A.rows_);
    M.type = "Subtract of matrices m and m1 is:";
    for (int i = 0; i < M.mvec_.size(); ++i)
    {
        M.mvec_.at(i) = A.mvec_.at(i) - B.mvec_.at(i);
    }
    return M;
}
/// @brief Матрица умножения
/// @param Матрица A
/// @param Матрица B
/// @return Матрица М
Matrix math::operator*(const Matrix &A, const Matrix &B)
{
    if (A.cols_ != B.rows_)
    {
        std::cerr << "Matrix: Matrices can't be multiplied!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.rows_, B.cols_);
    M.type = "Multiplication of matrices m and m1 is:";
    for (int pos = 0; pos < M.mvec_.size(); ++pos)
    {
        int row = (int)std::floor(pos / M.cols_);
        int col = pos - row * M.cols_;

        for (int k = 0; k < A.cols_; ++k)
        {
            M.mvec_.at(pos) += A(row, k) * B(k, col);
        }
    }

    return M;
}
/// @brief сложение матрицы с присваиванием
/// @param матрица M
/// @return исходная матрица сложенная с М
Matrix &Matrix::operator+=(const Matrix &M)
{
    type = "Sum of matrices m";
    for (size_t i = 0; i < mvec_.size(); ++i)
    {
        mvec_.at(i) += M.mvec_.at(i);
    }
    return *this;
};
/// @brief вычитание матрицы с присваиванием
/// @param матрица M
/// @return исходная матрица после вычитания
Matrix &Matrix::operator-=(const Matrix &M)
{
    type = "Subtract of matrices m";
    for (size_t i = 0; i < mvec_.size(); ++i)
    {
        mvec_.at(i) -= M.mvec_.at(i);
    }
    return *this;
};
/// @brief умножение матрицы на число с присваиванием
/// @param число k
/// @return матрица

Matrix &Matrix::operator*=(int k)
{
    this->type = "Multiplication of matrices m:";
    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) *= k;
    }
    return *this;
}
/// @brief расширение пространства имен
/// перезагрузка ввода/вывода
namespace math
{
    /// @brief перезагрузка вывода
    /// @param out
    /// @param matrix
    /// @return out
    std::ostream &operator<<(std::ostream &out, const Matrix &matrix)
    {

        out << matrix.type << std::endl;
        for (int i = 0; i < matrix.rows_; ++i)
        {
            for (int j = 0; j < matrix.cols_; ++j)
            {
                out << matrix.mvec_.at(matrix.cols_ * i + j) << " ";
            }
            out << std::endl;
        }

        return out;
    }
    /// @brief перезагрузка вввода
    /// @param in , n, m
    /// @param matrix
    /// @return матрица с введенным количеством столбцов и строк
    std::istream &operator>>(std::istream &in, Matrix &matrix)
    {
        int n(0); /// количество строк
        int m(0); /// количество столбцов
                  /// ввод
        std::cout << "Input cools" << std::endl;
        in >> n;
        std::cout << "Input rows" << std::endl;
        in >> m;

        matrix = Matrix(n, m);

        return in;
    }


}