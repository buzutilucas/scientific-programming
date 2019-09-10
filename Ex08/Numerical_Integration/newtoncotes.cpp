/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file newtoncotes.cpp                                                |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 08/14/2019                                                  |
| @modified 08/16/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Source file containing the implementation of the
                          Numerical Integration
----------------------------------------------------------------------*/

#ifndef NEWTONCOTES_CPP
#define NEWTONCOTES_CPP

#include <iostream>
#include <cmath>
#include <string>
#include <omp.h>
#include "newtoncotes.h"

#define DELTA 0.00001

/*----------------------------------------------------------------------
                      Methods of NewtonCotes class
----------------------------------------------------------------------*/
/*Creat a gradient descent object.*/
NewtonCotes::NewtonCotes(float (*func)(float),  float a, float b)
{
  /*
  Param:
    float (*func)(float) - function address (polynomial that will
                           be applied to the algorithm).
    float a - interval a.
    float b - interval b.
  */
  this->func = func;
  this->a = a;
  this->b = b;
  this->subintervals = 0;
  this->n = 1;
  this->s = 0.;
  this->st = 0.;
  this->old = 0.;
  this->oldst = 0.;
  this->err = 0.;

}

/*Get the derivative of a function given
an initial variable.*/
float NewtonCotes::diff(float x)
{
  /*
      df     f(x+Dx) - f(x)
     ---- = ----------------
      dx           Dx

  Param:
    float x - value of x.
  Return: derivative of a polynomial
  */

  float d = (this->func(x + DELTA) - this->func(x))/DELTA;
  return d;
}

/*Get the derivative of a function given
an initial variable.*/
float NewtonCotes::diff2(float x)
{
  /*
      d^2f     f'(x+Dx) - f'(x)     f(x+2Dx) - 2f(x+Dx) + f(x)
     ------ = ------------------ = ----------------------------
      dx^2             Dx                    Dxˆ2

  Param:
    float x - value of x.
  Return: derivative of a polynomial
  */

  float d = (NewtonCotes::diff(x + DELTA) - NewtonCotes::diff(x))/DELTA;
  return d;
}

/*Get the derivative of a function given
an initial variable.*/
float NewtonCotes::diff3(float x)
{
  /*
      d^3f     f''(x+Dx) - f''(x)
     ------ = --------------------
      dx^3             Dx

  Param:
    float x - value of x.
  Return: derivative of a polynomial
  */

  float d = (NewtonCotes::diff2(x + DELTA) - NewtonCotes::diff2(x))/DELTA;
  return d;
}

/*Get the derivative of a function given
an initial variable.*/
float NewtonCotes::diff4(float x)
{
  /*
      d^4f     f'''(x+Dx) - f^'''(4)(x)
     ------ = --------------------------
      dx^4             Dx

  Param:
    float x - value of x.
  Return: derivative of a polynomial
  */

  float d = (NewtonCotes::diff3(x + DELTA) - NewtonCotes::diff3(x))/DELTA;
  return d;
}

/*Newton-Cotes trapezoidal by step by step.*/
float NewtonCotes::trapezoidal_next()
{
  /*
  Return: derivative of a polynomial
  */
  float sum, s=0., x;
  float width;

  this->subintervals++;
  if(this->subintervals == 1)
  {
    return (sum = 0.5*(this->b - this->a)*(this->func(this->a)+this->func(this->b)));
  }else{
    x = (this->b - this->a)/((float) this->subintervals);

    /*Fork a team of threads with each having a private x variable and reduction(+: of s)*/
    #pragma omp parallel for private(x) reduction(+:s)
    for(int i=0; i<this->subintervals-1; i++)
    {
      x += this->a + 0.5*x;
      s += this->func(x);
    }
    sum = (this->b - this->a)*(sum+2*s)/(2*this->subintervals);
    return sum;
  }
}

/*Newton-Cotes rectangle by step by step.*/
float NewtonCotes::rectangle_next()
{
  /*
  Return: derivative of a polynomial
  */

  float sum, s=0., x;
  float width;

  this->subintervals++;
  if(this->subintervals == 1)
  {
    return (sum = (this->b - this->a)*(this->func(0.5*(this->b - this->a))));
  }else{
    width = (this->b - this->a)/((float) this->subintervals);

    /*Fork a team of threads with each having a private x variable and reduction(+: of s)*/
    #pragma omp parallel for private(x) reduction(+:s)
    for(int i=0; i<this->subintervals-1; i++)
    {
      x = (i+0.5)*width; //midpoint of rectangle
      s += this->func(x);
    }
  }
  sum = sum+(this->b - this->a)*s;
  return sum;
}

/*Adaptive Quadrature whit methods Trapezoidal,
Rectangle and Simpson.*/
float NewtonCotes::adaptQuad(std::string method, float eps)
{
  /*
  Param:
    float (*func)(float) -
    string method - Use 'rect' to rectangle rule,
                    'trap' to trapezoidal rule or
                    'simp' to simpson rule.
    float eps - epsilon (default is 1e-10).

  Return: the integral.
  */

  float h;

  if(method == "trap") //Adaptive Quadrature by Trapezoidal
  {
    this->s = NewtonCotes::trapezoidal_next();
    if(abs(this->s - this->old)<eps*abs(this->old) || (this->s == 0. && this->old == 0.))
    {
      h = (this->b - this->a)/this->n;
      this->err = -1*pow(h,3)/12;              //error trapezoidal
      this->err *= NewtonCotes::diff2(eps);    //-(h^3/12)f"(x0)
      this->err = abs(this->err);             //absolute error
      if(std::isnan(this->s))
        return this->old;
      else
        return this->s;
    }
    this->n++;
    this->old = this->s;
    return NewtonCotes::adaptQuad("trap");

  }else if(method == "rect"){ //Adaptive Quadrature by Rectangle
    this->s = NewtonCotes::rectangle_next();
    if(abs(this->s - this->old)<eps*abs(this->old) || (this->s == 0. && this->old == 0.))
    {
      h = (this->b - this->a)/this->n;
      this->err = pow(h,3)/24;                  //error midpoint
      this->err *= NewtonCotes::diff2(eps);    //+(h^3/24)f"(x0)
      this->err = abs(this->err);              //absolute error
      if(std::isnan(this->s))
        return this->old;
      else
        return this->s;
    }
    this->n++;
    this->old = this->s;
    return NewtonCotes::adaptQuad("rect");

  }else if(method == "simp"){ //Adaptive Quadrature by Simpson
    this->st = NewtonCotes::trapezoidal_next();
    this->s = (4.*this->st-this->oldst)/3.;
    if(abs(this->s - this->old)<eps*abs(this->old) || (this->s == 0. && this->old == 0.))
    {
      h = (this->b - this->a)/this->n;
      this->err = -1*pow(h,5)/2880;             //error simpson
      this->err *= NewtonCotes::diff4(eps);    //-(h^5/2880)f""(x0)
      this->err = abs(this->err);              //absolute error
      if(std::isnan(this->s))
        return this->old;
      else
        return this->s;
    }
    this->n++;
    this->old = this->s;
    this->oldst = this->st;
    return NewtonCotes::adaptQuad("simp");

  }else{
    return 0.0;
  }
}

#endif //NEWTONCOTES_CPP
