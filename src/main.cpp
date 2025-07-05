#include <iostream>
#include <vector>

// объявление структуры
struct Matrix;

// Предпроцессор: импорт из файла .dll
#define ExpDLL __declspec(dllimport)
#ifdef __cplusplus
extern "C"
{
#endif
  extern Matrix ExpDLL *math_createMatrix(int, int);
  extern void ExpDLL math_deleteMatrix(Matrix *);
  extern float ExpDLL math_get(const Matrix *, int, int);
  extern void ExpDLL math_set(Matrix *, int, int, float);
  extern void ExpDLL math_print(Matrix *);
  extern Matrix ExpDLL *math_add(const Matrix *A, const Matrix *B);
  extern Matrix ExpDLL *math_subtract(const Matrix *A, const Matrix *B);
  extern Matrix ExpDLL *math_dot(const Matrix *A, const Matrix *B);
  extern Matrix ExpDLL *math_add_(const Matrix *A, const Matrix *B);
  extern Matrix ExpDLL *math_subtract_(const Matrix *A, const Matrix *B);
  extern Matrix ExpDLL *math_dot_(const Matrix *A, int k);

#ifdef __cplusplus
}
#endif

int main()
{
  // создание матрицы
  Matrix *m1 = math_createMatrix(3, 3);
  math_set(m1, 0, 0, 1);
  math_set(m1, 1, 1, 1);

  // вывод в терминал
  math_print(m1);

  // создание матрицы
  Matrix *m2 = math_createMatrix(3, 3);
  math_set(m2, 0, 0, 2.);
  math_set(m2, 1, 1, 2.);

  // создание матрицы
  Matrix *m3 = math_createMatrix(3, 3);
  // операции с матрицами +-*
  m3 = math_add(m1, m2);
  m3 = math_subtract(m1, m2);
  m3 = math_dot(m1, m2);

  math_print(m3);
  // операции с матрицами с присвоением
  m3 = math_dot_(m2, 2);
  math_print(m3);

  return 0;
}
