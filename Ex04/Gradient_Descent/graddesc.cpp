/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file graddesc.cpp                                                   |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 08/11/2019                                                  |
| @modified 08/13/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Source file containing the implementation of the
                          Gradient Descent Algorithm
----------------------------------------------------------------------*/

#ifndef GRADDESC_CPP
#define GRADDESC_CPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include "graddesc.h"

#define DELTA 0.00001

/*----------------------------------------------------------------------
                         Methods of GradDesc class
----------------------------------------------------------------------*/
/*Creat a gradient descent object.*/
GradDesc::GradDesc(float (*func)(float),  float val, float learningRate)
{
  /*
  Param:
    float (*func)(float) - function address (polynomial that will
                           be applied to the algorithm).
    float val - inicial value.
    float learningRate - learning rate.
  */
  this->func = func;
  this->val = val;
  this->learningRate = learningRate;

}

/*Get the derivative of a function given
an initial variable.*/
float GradDesc::diff()
{
  /*
      df     f(x+Dx) - f(x)
     ---- = ----------------
      dx           Dx

  Return: derivative of a polynomial
  */

  float d = (this->func(this->val + DELTA) - this->func(this->val))/DELTA;
  return d;
}

/*Runs the gradient descent algorithm.*/
void GradDesc::fit()
{
  float f = this->func(this->val);

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Derivative: " << this->func(this->val) << " | x: " << this->val << "| y: " << f << std::endl;
  while(f != 0.00)
  {
    float s = GradDesc::diff();
    this->val -= this->learningRate*s;
    f = GradDesc::diff();
    f = floorf(f * 100) / 100;
    std::cout << "Derivative: " << f << " | x: " << this->val << "| y: " << this->func(this->val) << std::endl;
  }
}

#endif //GRADDESC_CPP
