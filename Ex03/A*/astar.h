/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file astar.h                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 07/09/2019                                                  |
| @modified 07/09/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
               Header file containing the AStar class
----------------------------------------------------------------------*/

#ifndef ASTAR_H
#define ASTAR_H

#include "puzzle.h"
#include "dlist.h"

class AStar : public puzzle8
{
  private:
    dll::LinkedList<int> tree; //search tree open list

    /*Methods (function prototypes)*/
    int manhattan(int** data);
    void bubble_sort(dll::LinkedList<int> &list);

  public:
    AStar(int (*initial)[3], int (*goal)[3]) : puzzle8()
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
    ~AStar() { } //destructor

    /*Methods (function prototypes)*/
    void search();
};

#endif //ASTAR_H
