/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file puzzle.h                                                       |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/29/2019                                                  |
| @modified 06/29/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
                Header file containing the puzzle8 class
----------------------------------------------------------------------*/

#ifndef PUZZLE_H
#define PUZZLE_H

#include <exception>
#include <string.h>

#define SIZE 3

class puzzle8
{
  private:
    /*Attribute*/
    int** goal;
    int** game; //initial game

    /*Methods (function prototypes)*/
    int** up(int** game, int row, int column);
    int** down(int** game, int row, int column);
    int** left(int** game, int row, int column);
    int** right(int** game, int row, int column);

  protected:
    /*Methods (function prototypes)*/
    int** nextGame(int position);
    int* allDirection(int** game);

  public:
    puzzle8(); //default constructor
    ~puzzle8(); //destructor

    /*Methods (function prototypes)*/
    void setGoal(int** goal);
    int** getGoal();
    void setGame(int** game);
    int** getGame();

};

#endif //PUZZLE_H
