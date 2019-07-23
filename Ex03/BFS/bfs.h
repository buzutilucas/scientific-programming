/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file bfs.h                                                          |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/29/2019                                                  |
| @modified 07/07/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
                Header file containing the BFS class
----------------------------------------------------------------------*/

#ifndef BFS_H
#define BFS_H

#include "puzzle.h"
#include "queue.h"

class BFS : public puzzle8
{
  private:
    que::Queue<int> tree; //search tree

  public:
    BFS(int (*initial)[3], int (*goal)[3]) : puzzle8()
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
    ~BFS() { } //destructor

    /*Methods (function prototypes)*/
    void search();
};

#endif //BFS_H
