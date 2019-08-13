/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file graddesc.h                                                     |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 08/11/2019                                                  |
| @modified 08/13/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
              Header file containing the GradDesc class
----------------------------------------------------------------------*/

#ifndef GRADDESC_H
#define GRADDESC_H

#include "dlist.h"

class GradDesc
{
  private:
    dll::LinkedList<float>* poly; //funtion polynomial
    float val; //inicial value
    float learningRate; //learning rate

    /*Methods (function prototypes)*/
    float diff();
    float func();

  public:
    GradDesc(dll::LinkedList<float> &poly,  float val, float learningRate); //default constructor
    ~GradDesc() { } //destructor

    /*Methods (function prototypes)*/
    void fit(); //train the algorithm
};

//#include "graddesc.cpp"
#endif //GRADDESC_H
