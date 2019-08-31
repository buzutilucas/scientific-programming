/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file montecarlo.cpp                                                 |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 08/28/2019                                                  |
| @modified 08/28/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Source file containing the implementation of the
                          Monte Carlo Integration
----------------------------------------------------------------------*/

#ifndef MONTECARLO_CPP
#define MONTECARLO_CPP

#include <iostream>
#include <cmath>
#include <mpi.h>
#include "montecarlo.h"

#define MASTER 0

/*----------------------------------------------------------------------
                      Methods of MonteCarlo class
----------------------------------------------------------------------*/
/*Creat a gradient descent object.*/
MonteCarlo::MonteCarlo(float (*func)(float), float (*func2)(float), int a, int b)
{
  /*
  Param:
    float (*func)(float)  - function address (polynomial that will
                            be applied to the algorithm).
    float (*func2)(float) - power of two function address (polynomial that will
                            be applied to the error).
    int a - interval a.
    int b - interval b.
  */
  this->func = func;
  this->func2 = func2;
  this->a = (float)a;
  this->b = (float)b;
  this->result = 0.;
  srand((unsigned)time(NULL)); //start the generator random

}

/*Given a number of interation and a function,
the result of interation is found.*/
float MonteCarlo::integrate(int n)
{
  /*
  Param:
    int n - number of integration.
  Return: result of integration.
  */
  float sum = 0,    //summation of function
        r;          //random numbers

  for(int i=0; i<n; i++)
  {
    r = this->a + (float)(rand()) /((float)(RAND_MAX/(this->b - this->a)));
    sum += func(r);
  }
  sum/=n;
  sum *= (this->b - this->a);
  return sum;
}

/*Given a number of interation, a function and
the same function power of two, the error of
interation is found.*/
float MonteCarlo::error(int n)
{
  /*
  Param:
    int n - number of integration.
  Return: the error of function.
  */
  float sum = 0,     //summation of function
        sum2 = 0,    //summation power of two function
        r,           //random numbers
        err;         //error of integration
  for(int i=0; i<n; i++)
  {
    r = this->a + (float)(rand())/((float)(RAND_MAX/(this->b - this->a)));
    sum += func(r);
    sum2 += func2(r);
  }
  sum/=n;
  sum2/=n;

  err = (sum2 - pow(sum,2))/n;
  return (this->b - this->a)*sqrt(err);
}

/*Find the integration and error given a function.*/
void MonteCarlo::fit(int n)
{
  /*
  Param:
    int n - number of integration.
  Return: print value of integration and print error.
  */
  double startime,   //start timer
         stoptime;   //stop timer
  float homeinteg,   //value of integrate calculated by current task
        integsum,    //sum of tasks' integrate values
        homeerror,   //value of error calculated by current task
        errsum;      //sum of tasks' integrate values
  int	taskid,        //task ID - also used as seed number
  	  numtasks,      //number of tasks
  	  rs,            //return code sum integration
      re;            //return code error
  char hostname[MPI_MAX_PROCESSOR_NAME]; //hostname of each process

  /*Obtain number of tasks and task ID*/
  MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD,&taskid);

  srandom (taskid); //set seed for random number generator equal to task ID

  startime = MPI_Wtime();
  /*
  Monte Carlos Integration by MPI
  */
  homeinteg = MonteCarlo::integrate(n);
  rs = MPI_Reduce(&homeinteg, &integsum, 1, MPI_FLOAT,
                  MPI_SUM, MASTER, MPI_COMM_WORLD);

  if(rs != MPI_SUCCESS)
    std::cout << taskid << " failure on rs/MPI_Reduce" << std::endl;

  if(taskid == MASTER)
  {
    this->result = integsum/numtasks; //the average of integration to all processor
    std::cout << "integrate: " << integsum/numtasks << std::endl;
  }

  /*
  Error Monte Carlos by MPI
  */
  homeerror = MonteCarlo::error(n);
  re = MPI_Reduce(&homeerror, &errsum, 1, MPI_FLOAT,
                  MPI_SUM, MASTER, MPI_COMM_WORLD);

  if(re != MPI_SUCCESS)
    std::cout << taskid << " failure on re/MPI_Reduce" << std::endl;

  if(taskid == MASTER)
  {
    this->err = errsum/numtasks; //the average of error to all processor
    std::cout << "Error: " << errsum/numtasks << std::endl;
  }

  stoptime = MPI_Wtime();
  std::cout << "Time of processor "<< taskid << ": " << stoptime - startime << std::endl;
}

#endif //MONTECARLO_CPP
