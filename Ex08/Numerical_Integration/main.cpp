#include <iostream>
#include <cmath>
#include <chrono>
#include "newtoncotes.h"

using namespace std;
using namespace std::chrono;

float f1(float x) {return pow(M_E,x);} //e^x
float f2(float x) {return sqrt(1-pow(x,2));} //sqrt(1-x^2)
float f3(float x) {return pow(M_E,pow(-x,2));} //e^(-x^2)

int main(int argc, char *argv[]) {

  float a = 0.;
  float b = 1.;
  float eps=1.e-10;

  cout << "---------- Function: e^x ----------" << endl;

  steady_clock::time_point t1 = steady_clock::now();
  NewtonCotes trap_func1(&f1,a,b);
  steady_clock::time_point t2 = steady_clock::now();
  cout << "Trapezoidal:\nIntegral " << trap_func1.adaptQuad("trap", eps) << endl;
  cout << "error " << trap_func1.getErr() << " | n "<< trap_func1.getN() << endl;
  duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
  cout << "Time: " << time_span1.count() << " seconds." << endl << endl;

  steady_clock::time_point t3 = steady_clock::now();
  NewtonCotes rect_func1(&f1,a,b);
  steady_clock::time_point t4 = steady_clock::now();
  cout << "Rectangle:\nIntegral " << rect_func1.adaptQuad("rect", eps) << endl;
  cout << "error " << rect_func1.getErr() << " | n "<< rect_func1.getN() << endl;
  duration<double> time_span2 = duration_cast<duration<double>>(t4 - t3);
  cout << "Time: " << time_span2.count() << " seconds." << endl << endl;

  steady_clock::time_point t5 = steady_clock::now();
  NewtonCotes simp_func1(&f1,a,b);
  steady_clock::time_point t6 = steady_clock::now();
  cout << "Simpson:\nIntegral " << simp_func1.adaptQuad("simp", eps) << endl;
  cout << "error " << simp_func1.getErr() << " | n "<< simp_func1.getN() << endl;
  duration<double> time_span3 = duration_cast<duration<double>>(t6 - t5);
  cout << "Time: " << time_span3.count() << " seconds." << endl << endl;


  cout << "---------- Function: sqrt(1-x^2) ----------" << endl;

  steady_clock::time_point t7 = steady_clock::now();
  NewtonCotes trap_func2(&f2,a,b);
  steady_clock::time_point t8 = steady_clock::now();
  cout << "Trapezoidal:\nIntegral " << trap_func2.adaptQuad("trap", eps) << endl;
  cout << "error " << trap_func2.getErr() << " | n "<< trap_func2.getN() << endl;
  duration<double> time_span4 = duration_cast<duration<double>>(t8 - t7);
  cout << "Time: " << time_span4.count() << " seconds." << endl << endl;

  steady_clock::time_point t9 = steady_clock::now();
  NewtonCotes rect_func2(&f2,a,b);
  steady_clock::time_point t10 = steady_clock::now();
  cout << "Rectangle:\nIntegral " << rect_func2.adaptQuad("rect", eps) << endl;
  cout << "error " << rect_func2.getErr() << " | n "<< rect_func2.getN() << endl;
  duration<double> time_span5 = duration_cast<duration<double>>(t10 - t9);
  cout << "Time: " << time_span5.count() << " seconds." << endl << endl;

  steady_clock::time_point t11 = steady_clock::now();
  NewtonCotes simp_func2(&f2,a,b);
  steady_clock::time_point t12 = steady_clock::now();
  cout << "Simpson:\nIntegral " << simp_func2.adaptQuad("simp", eps) << endl;
  cout << "error " << simp_func2.getErr() << " | n "<< simp_func2.getN() << endl;
  duration<double> time_span6 = duration_cast<duration<double>>(t12 - t11);
  cout << "Time: " << time_span6.count() << " seconds." << endl << endl;


  cout << "---------- Function: e^(-x^2) ----------" << endl;

  steady_clock::time_point t13 = steady_clock::now();
  NewtonCotes trap_func3(&f3,a,b);
  steady_clock::time_point t14 = steady_clock::now();
  cout << "Trapezoidal:\nIntegral " << trap_func3.adaptQuad("trap", eps) << endl;
  cout << "error " << trap_func3.getErr() << " | n "<< trap_func3.getN() << endl;
  duration<double> time_span7 = duration_cast<duration<double>>(t14 - t13);
  cout << "Time: " << time_span7.count() << " seconds." << endl << endl;

  steady_clock::time_point t15 = steady_clock::now();
  NewtonCotes rect_func3(&f3,a,b);
  steady_clock::time_point t16 = steady_clock::now();
  cout << "Rectangle:\nIntegral " << rect_func3.adaptQuad("rect", eps) << endl;
  cout << "error " << rect_func3.getErr() << " | n "<< rect_func3.getN() << endl;
  duration<double> time_span8 = duration_cast<duration<double>>(t15 - t16);
  cout << "Time: " << time_span8.count() << " seconds." << endl << endl;

  steady_clock::time_point t17 = steady_clock::now();
  NewtonCotes simp_func3(&f3,a,b);
  steady_clock::time_point t18 = steady_clock::now();
  cout << "Simpson:\nIntegral " << simp_func3.adaptQuad("simp", eps) << endl;
  cout << "error " << simp_func3.getErr() << " | n "<< simp_func3.getN() << endl;
  duration<double> time_span9 = duration_cast<duration<double>>(t18 - t17);
  cout << "Time: " << time_span9.count() << " seconds." << endl << endl;

  return 0;
}
