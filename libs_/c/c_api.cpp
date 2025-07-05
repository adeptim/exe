#include "c_api.h"
#include "src/matrix.h"
#include <iostream>

struct Matrix : public math::Matrix
{
public:
    Matrix(const struct math::Matrix &M) : math::Matrix(M) {};
};

Matrix *math_createMatrix(int rows, int cols)
{
    return new Matrix(math::Matrix(rows, cols));
}

void math_deleteMatrix(Matrix *M)
{
    delete M;
}

real math_get(const Matrix *M, int row, int col)
{
    return M->operator()(row, col);
}

void math_set(Matrix *M, int row, int col, real val)
{
    M->operator()(row, col) = val;
}

void math_print(const Matrix *M)
{
    std::cout << *M;
}

Matrix *math_add(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A + *B);
}

Matrix *math_subtract(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A - *B);
}

Matrix *math_dot(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A * *B);
}
Matrix *math_add_(const Matrix *A, const Matrix *B)
{
    // Создаём копию левого операнда
    Matrix *result = new Matrix(*A);
    // Применяем оператор += к копии
    *result += *B;
    return result;
}
Matrix *math_subtract_(const Matrix *A, const Matrix *B)
{
    // Создаём копию левого операнда
    Matrix *result = new Matrix(*A);
    // Применяем оператор += к копии
    *result -= *B;
    return result;
}
Matrix *math_dot_(const Matrix *A, int k)
{
    // Создаём копию левого операнда
    Matrix *result = new Matrix(*A);
    // Применяем оператор += к копии
    *result *= k;
    return result;
}