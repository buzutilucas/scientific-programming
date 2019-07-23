/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file astar.cpp                                                      |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 07/08/2019                                                  |
| @modified 07/08/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Source file containing the implementation of the
                          A* Search Algorithm
----------------------------------------------------------------------*/

#ifndef ASTAR_CPP
#define ASTAR_CPP

#include <iostream>
#include <cmath>
#include "astar.h"
#include "puzzle.h"
#include "dlist.h"

/*----------------------------------------------------------------------
                         Methods of AStar class
----------------------------------------------------------------------*/
/*Manhattan distance calculation.*/
int AStar::manhattan(int** data)
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

/*Floating ordering where a list is
ordered from highest to lowest.*/
void AStar::bubble_sort(dll::LinkedList<int> &list)
{
  /*
  Param:
    LinkedList<int> &list - address of a list.
  */
  dll::Node<int>* aux;

  for(int i=list.getSize(); i>0; i--)
  {
    unsigned int idex;
    for(unsigned int j=1; j<i; j++)
    {
      idex = j-1;
      dll::Node<int>* now = list.search(idex);
      dll::Node<int>* next = list.search(j);

      /*Evaluating nodes combining the cost to
      reach each node [g(n)] and the estimated cost
      to go from this node to the goal [h(n)]: f(n)=g(n)+h(n).*/
      if(next != NULL)
      {
        if((now->getData()+now->getDeep())<(next->getData()+next->getDeep()))
        {
          aux = list.remove(idex);
          list.insert(aux,j);
        } else if((now->getData()+now->getDeep())==(next->getData()+next->getDeep())) {
          if(now->getDeep()<next->getDeep())
          {
            aux = list.remove(idex);
            list.insert(aux,j);
          }
        }
      }
    }
  }
}

/**/
void AStar::search()
{
  int* dict;
  int deep = 0;
  int distance = AStar::manhattan(this->getGame());
  this->tree.insert(new dll::Node<int>(distance, deep, this->getGame())); //placing the parent leaf (root) in the stack

  bool theEnd = false;
  while(!theEnd)
  {
    dll::Node<int>* root = this->tree.removeBack2D();

    /*Print the game in screen*/
    std::cout << std::endl << "+-+-+-+" << std::endl;
    for(int i=0; i<3; i++)
    {
      std::cout << "|";
      for(int j=0; j<3; j++)
      {
        std::cout << root->getData2D()[i][j] << "|";
      }
      std::cout << std::endl << "+-+-+-+" << std::endl;
    }
    if(root->getDeep()<10)
    {
      if(root->getData()<10)
      {
        std::cout << "|0" << root->getDeep() << "|0" << root->getData() << "|" << std::endl;
        std::cout << "+-+-+-+" << std::endl;
      } else {
        std::cout << "|0" << root->getDeep() << "|" << root->getData() << "|" << std::endl;
        std::cout << "+-+-+-+" << std::endl;
      }
    } else {
      if(root->getData()<10)
      {
        std::cout << "|" << root->getDeep() << "|0" << root->getData() << "|" << std::endl;
        std::cout << "+-+-+-+" << std::endl;
      } else {
        std::cout << "|" << root->getDeep() << "|" << root->getData() << "|" << std::endl;
        std::cout << "+-+-+-+" << std::endl;
      }
    }

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

          distance = AStar::manhattan(nextLeaf);
          deep = root->getDeep()+1;
          /*Adding node with the son leaf, leaf deep and cost to goal.*/
          this->tree.insertFront(new dll::Node<int>(distance, deep, nextLeaf));
        }
      }

      /*Definition of the next leaf to be opened.*/
      AStar::bubble_sort(tree);

      std::cout << "\033[2J\033[1;1H"; //clean screen
    }
  }
  std::cout << std::endl << "+--------------------+" << std::endl;
  std::cout << "| Successful search! |" << std::endl;
  std::cout << "|    GOAL FOUND      |" << std::endl;
  std::cout << "+--------------------+" << std::endl;
}

#endif //ASTAR_CPP
