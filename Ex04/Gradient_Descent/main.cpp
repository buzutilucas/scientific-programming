#include <iostream>
#include <cmath>
#include "graddesc.h"

using namespace std;

float f(float x) {return pow(x,2);}
//float f(float x) {return pow(x,3)-2*pow(x,2)+2;}

int main(int argc, char *argv[]) {

  GradDesc grad(&f, 2., 0.1);
  grad.fit();

  return 0;
}
