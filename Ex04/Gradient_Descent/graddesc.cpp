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
#include "dlist.h"

/*----------------------------------------------------------------------
                         Methods of GradDesc class
----------------------------------------------------------------------*/
/*Creat a gradient descent object.*/
GradDesc::GradDesc(dll::LinkedList<float> &poly,  float val, float learningRate)
{
  /*
  Param:
    dll::LinkedList<float> &poly - address of list object (polynomial that
                                   will be applied to the algorithm).
    float val - inicial value.
    float learningRate - learning rate.
  */
  this->poly = poly;
  this->val = val;
  this->learningRate = learningRate;

}

/*Get the derivative of a function given
an initial variable.*/
float GradDesc::diff()
{
  /*
  Return: derivative of a polynomial
  */

  unsigned int power = 0;
  float ans = 0.;
  while(power != this->poly.getSize())
  {
    if(power != 0)
    {
      dll::Node<float>* coeff = this->poly.search(power);
      ans += coeff->getData()*power*pow(this->val, power-1);
    }
    power++;
  }
  return ans;
}

/*Get the result of a function given
an initial variable.*/
float GradDesc::func()
{
  /*
  Return: polynomial on val
  */

  unsigned int power = 0;
  float ans = 0.;
  while(power != this->poly.getSize())
  {
    dll::Node<float>* coeff = this->poly.search(power);
    if(power != 0)
    {
      ans += coeff->getData()*pow(this->val, power);
    }else{
      ans += coeff->getData();
    }
    power++;
  }
  return ans;
}

/*Runs the gradient descent algorithm.*/
void GradDesc::fit()
{
  float f = GradDesc::func();

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Derivative: " << GradDesc::diff() << " | x: " << this->val << "| y: " << f << std::endl;
  while(f != 0.00)
  {
    float s = GradDesc::diff();
    this->val -= this->learningRate*s;
    f = GradDesc::diff();
    f = floorf(f * 100) / 100;
    std::cout << "Derivative: " << f << " | x: " << this->val << "| y: " << GradDesc::func() << std::endl;
  }
}

#endif //GRADDESC_CPP
