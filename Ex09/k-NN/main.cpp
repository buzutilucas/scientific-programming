#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <stdlib.h>
#include <chrono>
#include "knn.h"

using namespace std;
using namespace std::chrono;

void confusionMatrix(set<string>* classes, vector<string>* test, vector<string>* predict);
void load_data(vector<vector<double> >* feature, vector<string>* classes, string* path_to_dataset, int attr, int num);

int main(int argc, char *argv[]) {
  int attr = 32; //number of attribute
  string path_dataset = "./dataset/cancer.data";
  int num_data = 529; //number of data
  string path_data_test = "./dataset/cancer_test.data";
  int num_data_test = 40; //number of data test

  vector<vector<double> > feature_train;
  vector<string> classes_train;
  vector<vector<double> > feature_test;
  vector<string> classes_test;

  set<string> classes;
  vector<string> classes_predict;

  load_data(&feature_train, &classes_train, &path_dataset, attr, num_data); //Load Dataset Training
  load_data(&feature_test, &classes_test, &path_data_test, attr, num_data_test); //Load Dataset testing

  int k = 11; // K
  string prediction = " ";
  kNN<double> knn(k,"euclidean");
  knn.fit(feature_train,classes_train);
  for(int i=0; i<feature_test.size(); i++) {
    prediction = knn.predict(feature_test[i]);
    classes_predict.push_back(prediction);
  }

  classes = knn.classes;
  confusionMatrix(&classes, &classes_test, &classes_predict);

  return 0;
}

void confusionMatrix(set<string>* classes, vector<string>* test, vector<string>* predict) {
  vector<int> myvector;
  vector<vector<int> > matrix;
  set<string>::iterator it, iit;

  for(int w=0; w<classes->size(); w++)
    myvector.push_back(0);

  //Compute Confusion Matrix
  for(it=classes->begin(); it!=classes->end(); it++) {
    for(int j=0; j<test->size(); j++) {
      if(test->at(j).compare(*it) == 0) {
        int k = 0;
        for(iit=classes->begin(); iit!=classes->end(); iit++) {
          if(predict->at(j).compare(*iit) == 0)
            myvector[k] += 1;
          k++;
        }
      }
    }
    matrix.push_back(myvector);
    for(int w=0; w<classes->size(); w++)
      myvector[w] = 0;
  }

  //Print the Confusion Matrix
  for(int i=0; i<classes->size(); i++)
    cout << "C" << i+1 << "  | ";
  cout << endl;
  for(int i=0; i<matrix.size(); i++) {
    for(int j=0; j<matrix[i].size(); j++)
      cout << matrix[i][j] << "  | ";
    cout << "C" << i+1 << endl;
  }
  cout << endl << "Label Class" << endl;
  int num = 1;
  for(it=classes->begin(); it!=classes->end(); it++)
    cout << *it << " -> C" << num++ << endl;

}

void load_data(vector<vector<double> >* feature, vector<string>* classes, string* path_to_dataset, int attr, int num) {
  ifstream read(*path_to_dataset);

  vector<string> temp_vet;
  string line;
  string temp;

  if(read.fail()) {
    cout << "Failure to open a file." << endl;
    cout << "File: " << *path_to_dataset << endl;
    exit(0);
  }

  while(getline(read, line)) {
    istringstream iss(line); //string stream
    while(getline(iss, temp, ',')) {
      temp_vet.push_back(temp);
    }
  }

  read.close();

  int k = 0;
  for(int i=0; i<num; i++) {
    vector<double> myvector;
    for(int j=0; j<attr; j++) {
      if(isalpha(temp_vet[k].c_str()[0]))
        classes->push_back(temp_vet[k]);
      else
        myvector.push_back(atof(temp_vet[k].c_str()));
      k++;
    }
    feature->push_back(myvector);
  }
}
