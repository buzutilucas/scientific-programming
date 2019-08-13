#include <iostream>
#include "dlist.h"
#include "graddesc.h"

using namespace std;

int main(int argc, char *argv[]) {

  /**/
  dll::LinkedList<float> poly;
  poly.insertBack(new dll::Node<float>(0.));
  poly.insertBack(new dll::Node<float>(0.));
  poly.insertBack(new dll::Node<float>(1.));

  GradDesc grad(poly, 2., 0.1);
  grad.fit();

  return 0;
}
