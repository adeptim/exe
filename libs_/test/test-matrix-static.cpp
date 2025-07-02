#include "src/matrix.h"
#include <iostream>


int main()
{
   math::Matrix m(3, 3);
    m(0,0) = 1;
    m(1,1) = 1;

    math::Matrix m1(3, 3);
    m1(0,0)=5;
    m1(1,1)=5;

    std::cout << m << std::endl;

    std::cout << m1 << std::endl;

    math::Matrix m2 = m + m1;
    std::cout<< m2 << std::endl;

    math::Matrix m3 = m - m1;
    std::cout   << m3 << std::endl;

    math::Matrix m4 = m * m1;
    std::cout  << m4 << std::endl;

  m4 += m1;
    std::cout << m4 << std::endl;

    m4 -= m1;
    std::cout << m4 << std::endl;
 m4 *= 2;
    std::cout << m4 << std::endl;


}