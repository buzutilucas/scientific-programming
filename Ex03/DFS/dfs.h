/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file dfs.h                                                          |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 07/08/2019                                                  |
| @modified 07/08/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
                Header file containing the DFS class
----------------------------------------------------------------------*/

#ifndef DFS_H
#define DFS_H

#include "puzzle.h"
#include "stack.h"
#include "dlist.h"

#define DEEP 13 //depth to be searched

class DFS : public puzzle8
{
  private:
    stk::Stack<int> tree; //search tree

  public:
    DFS(int (*initial)[3], int (*goal)[3]) : puzzle8()
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
    ~DFS() { } //destructor

    /*Methods (function prototypes)*/
    void search();
};

#endif //DFS_H
