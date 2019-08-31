#include <iostream>
#include <cmath>
#include <mpi.h>
#include "montecarlo.h"

using namespace std;

float st_f(float x) {return 4/(1+pow(x,2));}
float st_f2(float x) {return pow(st_f(x),2);}

float nd_f(float x) {return sqrt(x+sqrt(x));}
float nd_f2(float x) {return pow(nd_f(x),2);}

int main(int argc, char *argv[]) {
  MPI_Init(&argc,&argv);

  /*---------- Function: 4/(1+x^2) ----------*/
  MonteCarlo mc1(&st_f,&st_f2,0,1);
  mc1.fit(100);

  /*---------- Function: sqrt(x+sqrt(x)) ----------*/
  //MonteCarlo mc2(&nd_f,&nd_f2,0,1);
  //mc2.fit(100);

  MPI_Finalize();

  return 0;
}
