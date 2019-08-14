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

class GradDesc
{
  private:
    float val; //inicial value
    float learningRate; //learning rate

    /*Methods (function prototypes)*/
    float (*func)(float);
    float diff();

  public:
    GradDesc(float (*func)(float),  float val, float learningRate); //default constructor
    ~GradDesc() { } //destructor

    /*Methods (function prototypes)*/
    void fit(); //train the algorithm
};

//#include "graddesc.cpp"
#endif //GRADDESC_H
