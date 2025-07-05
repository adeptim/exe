#include <export.h> // bkb vf[ros 'rcgjhnf]
struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif
    extern Matrix MATRIXLIB_EXPORT *math_createMatrix(int, int);
    extern void MATRIXLIB_EXPORT math_deleteMatrix(Matrix *);
    extern float MATRIXLIB_EXPORT math_get(Matrix *, int, int);
    extern void MATRIXLIB_EXPORT  math_set(Matrix *, int, int, float);
    extern Matrix  MATRIXLIB_EXPORT *math_add(const Matrix *A, const Matrix *B);
extern Matrix  MATRIXLIB_EXPORT *math_subtract(const Matrix *A, const Matrix *B);
extern Matrix  MATRIXLIB_EXPORT *math_dot(const Matrix *A, const Matrix *B);
extern Matrix  MATRIXLIB_EXPORT *math_add_(const Matrix *A, const Matrix *B);
extern Matrix   MATRIXLIB_EXPORT *math_subtract_(const Matrix *A, const Matrix *B);
extern Matrix  MATRIXLIB_EXPORT *math_dot_(const Matrix *A, int k);
    extern void MATRIXLIB_EXPORT math_print(Matrix *);
#ifdef __cplusplus
}
#endif

int main()
{
   
    
   Matrix *m1 = math_createMatrix(3, 3);
  math_set(m1,0,0,1.);
    math_set(m1,1,1,1.);
  //  math_print(m1);
     Matrix *m2 = math_createMatrix(3, 3);
  math_set(m2,0,0,2.);
    math_set(m2,1,1,1.);
 Matrix *m3 = math_createMatrix(3, 3);
m3=math_add(m1,m2);
//math_print(m3);
m3=math_subtract(m1,m2);
math_print(m3);
//m3=math_dot(m1,m2);
m3=math_add_(m3,m1);

//m3=math_dot_(m1,3);
math_print(m3);
Matrix *m4 = math_createMatrix(3, 3);
math_print(m4);
    // в конце обязательно вызываем деструктор
    math_deleteMatrix(m1);

    return 0;
}