/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file montecarlo.h                                                   |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 08/28/2019                                                  |
| @modified 08/28/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Header file containing the MonteCarlo class
----------------------------------------------------------------------*/

#ifndef MONTECARLO_H
#define MONTECARLO_H


class MonteCarlo
{
  private:
    float a;
    float b;
    float result;
    float err;
    float (*func)(float);
    float (*func2)(float);

    /*Methods (function prototypes)*/
    float integrate(int n);
    float error(int n);

  public:
    MonteCarlo(float (*func)(float), float (*func2)(float), int a, int b); //default constructor
    ~MonteCarlo() { } //destructor

    /*Methods (function prototypes)*/
    void fit(int n);
    float getResult() {return this->result;}
    float getErr() {return this->err;}

};

#endif //MONTECARLO_H
