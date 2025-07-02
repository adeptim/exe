#pragma once
#include "export.h"

#ifdef MATH_DOUBLE_PRECISION_DEFINE
typedef double real;
#else
typedef float real;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct Matrix Matrix;
    /// @brief обертка конструктора с параметрами
    /// @param rows
    /// @param cols
    /// @return
    Matrix MATRIXLIB_EXPORT *math_createMatrix(int rows, int cols);

    /// @brief обертка деструктора
    /// @param M
    void MATRIXLIB_EXPORT math_deleteMatrix(Matrix *M);

    /// @brief обертка оператора доступа к элементам матрицы (получение)
    /// @param M объект матрицы
    /// @param row номер строки
    /// @param col номер столбца
    /// @return элемент матрицы
    real MATRIXLIB_EXPORT math_get(const Matrix *M, int row, int col);

    /// @brief обертка оператора доступа к элементам матрицы (запись)
    /// @param M объект матрицы
    /// @param row номер строки
    /// @param col номер столбца
    /// @return элемент матрицы
    void MATRIXLIB_EXPORT math_set(Matrix *M, int row, int col, real val);

    /// @brief обертка оператора вывода элементов матрицы в консоль
    /// @param M
    void MATRIXLIB_EXPORT math_print(const Matrix *M);

    /// @brief обертка оператора сложения матриц
    /// @param A
    /// @param B
    /// @return
    Matrix MATRIXLIB_EXPORT *math_add(const Matrix *A, const Matrix *B);

    /// @brief обертка оператора вычитания матриц
    /// @param A
    /// @param B
    /// @return
    Matrix MATRIXLIB_EXPORT *math_subtract(const Matrix *A, const Matrix *B);

    /// @brief обертка оператора умножения матриц
    /// @param A
    /// @param B
    /// @return
    Matrix MATRIXLIB_EXPORT *math_dot(const Matrix *A, const Matrix *B);

     /// @brief обертка оператора сложения матриц c присвоением
    /// @param A
    /// @return
Matrix MATRIXLIB_EXPORT *math_add_(const Matrix *A, const Matrix *B);

  /// @brief обертка оператора вычитания матриц c присвоением
    /// @param A
    /// @return
    Matrix MATRIXLIB_EXPORT *math_subtract_(const Matrix *A, const Matrix *B);

/// @brief обертка оператора умножения матрицы на число
    /// @param k
    /// @return
    Matrix MATRIXLIB_EXPORT *math_dot_(const Matrix *A, int k);



#ifdef __cplusplus
}
#endif