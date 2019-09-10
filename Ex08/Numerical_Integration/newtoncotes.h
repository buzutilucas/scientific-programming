/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file newtoncotes.h                                                  |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 08/14/2019                                                  |
| @modified 08/16/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Header file containing the NewtonCotes class
----------------------------------------------------------------------*/

#ifndef NEWTONCOTES_H
#define NEWTONCOTES_H

#include <string>

class NewtonCotes
{
  private:
    float a;
    float b;
    int subintervals;
    int n;
    float s;
    float st;
    float old;
    float oldst;
    float err;

    /*Methods (function prototypes)*/
    float (*func)(float);
    float trapezoidal_next();
    float rectangle_next();
    float diff(float x);
    float diff2(float x);
    float diff3(float x);
    float diff4(float x);

  public:
    NewtonCotes(float (*func)(float),  float a, float b); //default constructor
    ~NewtonCotes() { } //destructor

    /*Methods (function prototypes)*/
    float adaptQuad(std::string method, float eps=1.e-10);
    int getN(){return this->n;}
    float getErr(){return this->err;}

};

#endif //NEWTONCOTES_H
