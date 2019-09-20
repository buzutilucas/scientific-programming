/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file knn.h                                                          |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 09/19/2019                                                  |
| @modified 09/19/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Header file containing the KNN and KNNException class
----------------------------------------------------------------------*/

#ifndef KNN_H
#define KNN_H

#include <vector>
#include <set>
#include <string>

template <class Type>
class kNN{
private:
  int k;
  int target_class;
  std::string distance;
  std::vector<std::vector<Type> > dataset;
  std::vector<std::string> attr_class;

  //function prototypes
  double euclidean_distance(std::vector<Type>& ind1, std::vector<Type>& ind2);
  double manhattan_distance(std::vector<Type>& ind1, std::vector<Type>& ind2);
  void set_classes(std::vector<std::string>& attr_class);

public:
  std::set<std::string> classes;

  kNN<Type>(int k=3, std::string distance="euclidean"); //default constructor
  ~kNN<Type>(); //destructor

  //function prototypes
  void fit(std::vector<std::vector<Type> >& dataset,std::vector<std::string>& attr_class); //default constructor
  std::string predict(std::vector<Type>& ind1);
  double score();
};

#include "knn.cpp"
#endif //KNN_H
