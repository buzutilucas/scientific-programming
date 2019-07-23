/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file dfs.cpp                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 07/07/2019                                                  |
| @modified 07/07/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Source file containing the implementation of the
                       Depth-First Search Algorithm
----------------------------------------------------------------------*/

#ifndef DFS_CPP
#define DFS_CPP

#include <iostream>
#include "dfs.h"
#include "puzzle.h"
#include "stack.h"
#include "dlist.h"

/*----------------------------------------------------------------------
                         Methods of DFS class
----------------------------------------------------------------------*/
/**/
void DFS::search()
{
  int* dict;
  int deep = 0;
  this->tree.push(0,deep,this->getGame()); //placing the parent leaf (root) in the stack

  try{
    bool theEnd = false;
    while(!theEnd)
    {
      dll::Node<int>* leaf = this->tree.pop();

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
      if(!theEnd)
      {
        bool flag = false;
        this->setGame(leaf->getData2D());
        dict = this->allDirection(leaf->getData2D());

        /*Getting the son leafs from the parent leaf.*/
        int aux = 0;
        for(int i=3; i>=0; i--)
        {
          if(dict[i]!=0)
          {
            int** nextLeaf = this->nextGame(dict[i]); //son leaf

            /*Checking the end tree.*/
            if(leaf->getDeep()<DEEP)
            {
              deep = leaf->getDeep()+1;
              this->tree.push(0,deep,nextLeaf); //adding the son leaf in the stack
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

  }catch(stk::StackException &e) {

    std::cout << std::endl << "+----------------+" << std::endl;
    std::cout << "| Search failed! |" << std::endl;
    std::cout << "| GOAL NOT FOUND |" << std::endl;
    std::cout << "+----------------+" << std::endl;
  }

}

#endif //DFS_CPP
