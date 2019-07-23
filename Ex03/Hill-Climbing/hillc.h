/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file hillc.h                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 07/11/2019                                                  |
| @modified 07/11/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
             Header file containing the HillClimbing class
----------------------------------------------------------------------*/

#ifndef HILLC_H
#define HILLC_H

#include "puzzle.h"
#include "dlist.h"

class HillClimbing : public puzzle8
{
  private:
    //stk::Stack<int> tree; //search tree
    dll::LinkedList<int> tree; //search tree open list

    /*Methods (function prototypes)*/
    int manhattan(int** data);
    void print(dll::Node<int>* node);

  public:
    HillClimbing(int (*initial)[3], int (*goal)[3]) : puzzle8()
    {
      /*Default constructor*/
      int** ptrGoal = new int*[3];
      int** ptrInitial = new int*[3];
      for (int i=0; i<3; i++)
      {
        ptrGoal[i] = new int[3];
        ptrInitial[i] = new int[3];
        for (int j=0; j<3; j++)
        {
          ptrGoal[i][j] = goal[i][j];
          ptrInitial[i][j] = initial[i][j];
        }
      }

      this->setGame(ptrInitial);
      this->setGoal(ptrGoal);
    }
    ~HillClimbing() { } //destructor

    /*Methods (function prototypes)*/
    void search();
};

#endif //HILLC_H
