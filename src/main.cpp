#include <iostream>
#include <vector>

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif
    extern Matrix __declspec(dllimport) *math_createMatrix(int, int);
    extern void __declspec(dllimport) math_deleteMatrix(Matrix *);
    extern double __declspec(dllimport) math_get(const Matrix *, int, int);
    extern void __declspec(dllimport) math_set(Matrix *, int, int, double);
    extern void __declspec(dllimport) math_print(Matrix *);
extern Matrix __declspec(dllimport) *math_add(const Matrix *A, const Matrix *B);
extern Matrix __declspec(dllimport) *math_subtract(const Matrix *A, const Matrix *B);
extern Matrix __declspec(dllimport) *math_dot(const Matrix *A, const Matrix *B);
extern Matrix  __declspec(dllimport) *math_add_(const Matrix *A, const Matrix *B);
extern Matrix  __declspec(dllimport) *math_subtract_(const Matrix *A, const Matrix *B);
extern Matrix  __declspec(dllimport)   *math_dot_(const Matrix *A, int k);

#ifdef __cplusplus
}
#endif

int main()
{
  
   Matrix *m1 = math_createMatrix(3, 3);
  math_set(m1, 0, 0, 1.);
    math_set(m1, 1, 1, 1.);
   // math_print(m1);
  Matrix *m2 = math_createMatrix(3, 3);
  math_set(m2, 0, 0, 2.);
    math_set(m2, 1, 1, 2.);
   math_print(m2);
  Matrix *m3 = math_createMatrix(3, 3);
m3=math_add(m1,m2);
m3=math_subtract(m1,m2);
m3=math_dot(m1,m2);
math_print(m3);
m3=math_dot_(m2,2);
math_print(m3);

 std::cout <<"vvv";
     std::cout << std::endl;
    return 0;
}
