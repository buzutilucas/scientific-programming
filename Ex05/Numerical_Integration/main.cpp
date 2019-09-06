#include <iostream>
#include <cmath>
#include "newtoncotes.h"

using namespace std;

float f1(float x) {return pow(M_E,x);} //e^x
float f2(float x) {return sqrt(1-pow(x,2));} //sqrt(1-x^2)
float f3(float x) {return pow(M_E,pow(-x,2));} //e^(-x^2)

int main(int argc, char *argv[]) {

  float a = 0.;
  float b = 1.;
  float eps=1.e-10;

  cout << "---------- Function: e^x ----------" << endl;

  NewtonCotes trap_func1(&f1,a,b);
  cout << "Trapezoidal:\nIntegral " << trap_func1.adaptQuad("trap", eps) << endl;
  cout << "error " << trap_func1.getErr() << " | n "<< trap_func1.getN() << endl << endl;

  NewtonCotes rect_func1(&f1,a,b);
  cout << "Rectangle:\nIntegral " << rect_func1.adaptQuad("rectangle", eps) << endl;
  cout << "error " << rect_func1.getErr() << " | n "<< rect_func1.getN() << endl << endl;

  NewtonCotes simp_func1(&f1,a,b);
  cout << "Simpson:\nIntegral " << simp_func1.adaptQuad("simp", eps) << endl;
  cout << "error " << simp_func1.getErr() << " | n "<< simp_func1.getN() << endl << endl;


  cout << "---------- Function: sqrt(1-x^2) ----------" << endl;

  NewtonCotes trap_func2(&f2,a,b);
  cout << "Trapezoidal:\nIntegral " << trap_func2.adaptQuad("trap", eps) << endl;
  cout << "error " << trap_func2.getErr() << " | n "<< trap_func2.getN() << endl << endl;

  NewtonCotes rect_func2(&f2,a,b);
  cout << "Rectangle:\nIntegral " << rect_func2.adaptQuad("rectangle", eps) << endl;
  cout << "error " << rect_func2.getErr() << " | n "<< rect_func2.getN() << endl << endl;

  NewtonCotes simp_func2(&f2,a,b);
  cout << "Simpson:\nIntegral " << simp_func2.adaptQuad("simp", eps) << endl;
  cout << "error " << simp_func2.getErr() << " | n "<< simp_func2.getN() << endl << endl;


  cout << "---------- Function: e^(-x^2) ----------" << endl;

  NewtonCotes trap_func3(&f3,a,b);
  cout << "Trapezoidal:\nIntegral " << trap_func3.adaptQuad("trap", eps) << endl;
  cout << "error " << trap_func3.getErr() << " | n "<< trap_func3.getN() << endl << endl;

  NewtonCotes rect_func3(&f3,a,b);
  cout << "Rectangle:\nIntegral " << rect_func3.adaptQuad("rectangle", eps) << endl;
  cout << "error " << rect_func3.getErr() << " | n "<< rect_func3.getN() << endl << endl;

  NewtonCotes simp_func3(&f3,a,b);
  cout << "Simpson:\nIntegral " << simp_func3.adaptQuad("simp", eps) << endl;
  cout << "error " << simp_func3.getErr() << " | n "<< simp_func3.getN() << endl << endl;

  return 0;
}
