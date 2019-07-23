/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file bfs.cpp                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/29/2019                                                  |
| @modified 07/07/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Source file containing the implementation of the
                       Breadth-First Search Algorithm
----------------------------------------------------------------------*/

#ifndef BFS_CPP
#define BFS_CPP

#include <iostream>
#include "bfs.h"
#include "puzzle.h"
#include "queue.h"

/*----------------------------------------------------------------------
                         Methods of BFS class
----------------------------------------------------------------------*/
/**/
void BFS::search()
{
  int* dict;
  int deep = 0;
  this->tree.enqueue(0,deep,this->getGame()); //placing the parent leaf (root) in the queue

  bool theEnd = false;
  while(!theEnd)
  {
    dll::Node<int>* leaf = this->tree.dequeue();

    /*Print the game in screen*/
    std::cout << std::endl << "+-+-+-+" << std::endl;
    for(int i=0; i<3; i++)
    {
      std::cout << "|";
      for(int j=0; j<3; j++)
      {
        std::cout << leaf->getData2D()[i][j] << "|";
      }
      std::cout << std::endl << "+-+-+-+" << std::endl;
    }
    if(leaf->getDeep()<10)
    {
      if(leaf->getData()<10)
      {
        std::cout << "|0" << leaf->getDeep() << "|0" << leaf->getData() << "|" << std::endl;
        std::cout << "+-+-+-+" << std::endl;
      } else {
        std::cout << "|0" << leaf->getDeep() << "|" << leaf->getData() << "|" << std::endl;
        std::cout << "+-+-+-+" << std::endl;
      }
    } else {
      if(leaf->getData()<10)
      {
        std::cout << "|" << leaf->getDeep() << "|0" << leaf->getData() << "|" << std::endl;
        std::cout << "+-+-+-+" << std::endl;
      } else {
        std::cout << "|" << leaf->getDeep() << "|" << leaf->getData() << "|" << std::endl;
        std::cout << "+-+-+-+" << std::endl;
      }
    }

    /*Check if the goal has been found.*/
    int i = 0;
    do{
      int j = 0;
      do{
        if(leaf->getData2D()[i][j] == this->getGoal()[i][j])
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
    if(!theEnd){
      this->setGame(leaf->getData2D());
      dict = this->allDirection(leaf->getData2D());
      /*Getting the son leafs from the parent leaf.*/
      for(int i=0; i<4; i++)
      {
        if(dict[i]!=0)
        {
          int** nextLeaf = this->nextGame(dict[i]); //son leaf

          deep = leaf->getDeep()+1;
          /*Adding the son leaf in the queue*/
          this->tree.enqueue(0,deep,nextLeaf);
        }
      }
      std::cout << "\033[2J\033[1;1H"; //clean screen
    }
  }
  std::cout << std::endl << "+--------------------+" << std::endl;
  std::cout << "| Successful search! |" << std::endl;
  std::cout << "|    GOAL FOUND      |" << std::endl;
  std::cout << "+--------------------+" << std::endl;
}

#endif //BFS_CPP
