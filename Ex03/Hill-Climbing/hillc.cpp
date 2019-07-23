/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file hillc.cpp                                                      |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 07/11/2019                                                  |
| @modified 07/11/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Source file containing the implementation of the
                    Hill-Climbing Search Algorithm
----------------------------------------------------------------------*/

#ifndef HILLC_CPP
#define HILLC_CPP

#include <iostream>
#include <cmath>
#include "hillc.h"
#include "puzzle.h"
#include "dlist.h"

/*----------------------------------------------------------------------
                         Methods of AStar class
----------------------------------------------------------------------*/
/*Manhattan distance calculation.*/
int HillClimbing::manhattan(int** data)
{
  /*
  Mdist = |x1 - x2| + |y1 - y2|

  Param:
    int** data - pointer to the data that will be
                computed from Manhattan distance.

  Return: manhattan distance.
  */
  int sum = 0;
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      int k = 0;
      do{
        int z = 0;
        do{
          if(data[i][j] != 0)
          {
            if(data[i][j] == this->getGoal()[k][z])
            {
              int dx = i-k;
              int dy = j-z;
              sum += abs(dx) + abs(dy);
            }
          }
          z++;
        }while(z<3);
        k++;
      }while(k<3);
    }
  }
  return sum;
}

/*Print the leaf in screen*/
void HillClimbing::print(dll::Node<int>* node)
{
  std::cout << std::endl << "+-+-+-+" << std::endl;
  for(int i=0; i<3; i++)
  {
    std::cout << "|";
    for(int j=0; j<3; j++)
    {
      std::cout << node->getData2D()[i][j] << "|";
    }
    std::cout << std::endl << "+-+-+-+" << std::endl;
  }
  if(node->getDeep()<10)
  {
    if(node->getData()<10)
    {
      std::cout << "|0" << node->getDeep() << "|0" << node->getData() << "|" << std::endl;
      std::cout << "+-+-+-+" << std::endl;
    } else {
      std::cout << "|0" << node->getDeep() << "|" << node->getData() << "|" << std::endl;
      std::cout << "+-+-+-+" << std::endl;
    }
  } else {
    if(node->getData()<10)
    {
      std::cout << "|" << node->getDeep() << "|0" << node->getData() << "|" << std::endl;
      std::cout << "+-+-+-+" << std::endl;
    } else {
      std::cout << "|" << node->getDeep() << "|" << node->getData() << "|" << std::endl;
      std::cout << "+-+-+-+" << std::endl;
    }
  }
}

/**/
void HillClimbing::search()
{
  int* dict;
  int deep = 0;
  int distance = HillClimbing::manhattan(this->getGame());
  this->tree.insert(new dll::Node<int>(distance, deep, this->getGame())); //placing the parent leaf (root) in the stack

  dll::Node<int>* ptrTemp;
  try{
    bool theEnd = false;
    while(!theEnd)
    {
      dll::Node<int>* root = this->tree.removeBack2D();

      /*Print the leaf in screen*/
      HillClimbing::print(root);

      /*Check if the goal has been found.*/
      int i = 0;
      do{
        int j = 0;
        do{
          if(root->getData2D()[i][j] == this->getGoal()[i][j])
          {
            j++;
            theEnd = true;
          } else {
            j = 3;
            i = 2;
            theEnd = false;
          }
        }while(j<3);
        i++;
      }while(i<3);

      /*Get the next leafs*/
      if(!theEnd)
      {
        this->setGame(root->getData2D());
        dict = this->allDirection(root->getData2D());

        /*Getting the son leafs from the parent leaf.*/
        for(int i=3; i>=0; i--)
        {
          if(dict[i]!=0)
          {
            int** nextLeaf = this->nextGame(dict[i]); //son leaf

            /*Definition of the next leaf to be opened.*/
            distance = HillClimbing::manhattan(nextLeaf);
            deep = root->getDeep()+1;
            if(distance<root->getData())
            {
              /*Adding node with the son leaf, leaf deep and cost to goal.*/
              this->tree.insertFront(new dll::Node<int>(distance,deep,nextLeaf));
            } else {
              dll::Node<int> temp(distance,deep,nextLeaf);
              ptrTemp = &temp;
            }
          }
        }
        std::cout << "\033[2J\033[1;1H"; //clean screen
      }
    }

    std::cout << std::endl << "+--------------------+" << std::endl;
    std::cout << "| Successful search! |" << std::endl;
    std::cout << "|    GOAL FOUND      |" << std::endl;
    std::cout << "+--------------------+" << std::endl;

  }catch(dll::LinkedListException &e) {

    /*Print the leaf in screen*/
    HillClimbing::print(ptrTemp);

    std::cout << std::endl << "+----------------+" << std::endl;
    std::cout << "| Search failed! |" << std::endl;
    std::cout << "| GOAL NOT FOUND |" << std::endl;
    std::cout << "+----------------+" << std::endl;
  }
}

#endif //HILLC_CPP
