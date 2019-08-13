/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file puzzle.cpp                                                     |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/29/2019                                                  |
| @modified 06/29/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
    Source file containing the implementation of the game 8-Puzzle
----------------------------------------------------------------------*/

#ifndef PUZZLE_CPP
#define PUZZLE_CPP

#include <iostream>
#include "puzzle.h"

/*----------------------------------------------------------------------
                       Methods of puzzle8 class
----------------------------------------------------------------------*/

/*Default constructor*/
puzzle8::puzzle8() { }

/*Destructor*/
puzzle8::~puzzle8()
{
  for(int i=0; i<SIZE; i++)
  {
      delete[] this->goal[i];
      delete[] this->game[i];
  }
  delete[] this->goal;
  delete[] this->game;
}

/*Set the currently goal state to new state.*/
void puzzle8::setGoal(int** goal)
{
  /*
  Param:
    int** goal - goal pointer.
  */
  this->goal = new int*[SIZE];
  for (int i=0; i<SIZE; i++)
  {
    this->goal[i] = new int[SIZE];
    for (int j=0; j<SIZE; j++)
    {
      this->goal[i][j] = goal[i][j];
    }
  }
}

/*Get the goal.*/
int** puzzle8::getGoal()
{
  /*
  Return: the goal of the game.
  */
  return this->goal;
}

/*Set the currently game state to new state.*/
void puzzle8::setGame(int** game)
{
  /*
  Param:
    int** game - new game pointer.
  */
  this->game = new int*[SIZE];
  for (int i=0; i<SIZE; i++)
  {
    this->game[i] = new int[SIZE];
    for (int j=0; j<SIZE; j++)
    {
      this->game[i][j] = game[i][j];
    }
  }
}

/*Get the currently game state.*/
int** puzzle8::getGame()
{
  /*
  Return: pointer to the currently game state.
  */
  return this->game;
}

/*Move the piece to up.*/
int** puzzle8::up(int** game, int row, int column)
{
  /*
  Param:
    int** game - pointer of the game state.
    int row - row to move the piece.
    int column - column to move the piece.

  Return: pointer to the new game state.
  */
  int aux;
  int** newGame = new int* [SIZE];
  for (int i=0; i<SIZE; i++)
  {
    newGame[i] = new int[SIZE];
    for (int j=0; j<SIZE; j++)
    {
      newGame[i][j] = game[i][j];
    }
  }

  aux = newGame[row][column];
  newGame[row][column] = newGame[row-1][column];
  newGame[row-1][column] = aux;
  return newGame;
}

/*Move the piece to down.*/
int** puzzle8::down(int** game, int row, int column)
{
  /*
  Param:
    int** game - pointer of the game state.
    int row - row to move the piece.
    int column - column to move the piece.

  Return: pointer to the new game state.
  */
  int aux;
  int** newGame = new int* [SIZE];
  for (int i=0; i<SIZE; i++)
  {
    newGame[i] = new int[SIZE];
    for (int j=0; j<SIZE; j++)
    {
      newGame[i][j] = game[i][j];
    }
  }

  aux = newGame[row][column];
  newGame[row][column] = newGame[row+1][column];
  newGame[row+1][column] = aux;
  return newGame;
}

/*Move the piece to left.*/
int** puzzle8::left(int** game, int row, int column)
{
  /*
  Param:
    int** game - pointer of the game state.
    int row - row to move the piece.
    int column - column to move the piece.

  Return: pointer to the new game state.
  */
  int aux;
  int** newGame = new int* [SIZE];
  for (int i=0; i<SIZE; i++)
  {
    newGame[i] = new int[SIZE];
    for (int j=0; j<SIZE; j++)
    {
      newGame[i][j] = game[i][j];
    }
  }

  aux = newGame[row][column];
  newGame[row][column] = newGame[row][column-1];
  newGame[row][column-1] = aux;
  return newGame;
}

/*Move the piece to right.*/
int** puzzle8::right(int** game, int row, int column)
{
  /*
  Param:
    int** game - pointer of the game state.
    int row - row to move the piece.
    int column - column to move the piece.

  Return: pointer to the new game state.
  */
  int aux;
  int** newGame = new int* [SIZE];
  for (int i=0; i<SIZE; i++)
  {
    newGame[i] = new int[SIZE];
    for (int j=0; j<SIZE; j++)
    {
      newGame[i][j] = game[i][j];
    }
  }

  aux = newGame[row][column];
  newGame[row][column] = newGame[row][column+1];
  newGame[row][column+1] = aux;
  return newGame;
}

/*Determines the next state of the game from
a movement (right, left, up or down).*/
int** puzzle8::nextGame(int position)
{
  /*
  Param:
    int position - a position to move the piece zero.

  Return: the next game state form a position.
  */
  /*Check all parts until you find
  ZERO and move it.*/
  for(int i=0; i<SIZE; i++)
  {
    for(int j=0; j<SIZE; j++)
    {
      /*Find zero in the first row*/
      if(i==0)
      {
        if(j==0)
        {
          if(this->game[i][j]==0)
          {
            if(position==2)
            {
              return puzzle8::right(this->game,i,j);
            }
            if(position==3)
            {
              return puzzle8::down(this->game,i,j);
            }
          }
        } else if(j==1) {
          if(this->game[i][j]==0)
          {
            if(position==2)
            {
              return puzzle8::right(this->game,i,j);
            }
            if(position==3)
            {
              return puzzle8::down(this->game,i,j);
            }
            if(position==4)
            {
              return puzzle8::left(this->game,i,j);
            }
          }
        } else {
          if(this->game[i][j]==0)
          {
            if(position==4)
            {
              return puzzle8::left(this->game,i,j);
            }
            if(position==3)
            {
              return puzzle8::down(this->game,i,j);
            }
          }
        }
      /*Find zero in the second row*/
      } else if(i==1) {
        if(j==0)
        {
          if(this->game[i][j]==0)
          {
            if(position==2)
            {
              return puzzle8::right(this->game,i,j);
            }
            if(position==3)
            {
              return puzzle8::down(this->game,i,j);
            }
            if(position==1)
            {
              return puzzle8::up(this->game,i,j);
            }
          }
        } else if(j==1) {
          if(this->game[i][j]==0)
          {
            if(position==2)
            {
              return puzzle8::right(this->game,i,j);
            }
            if(position==3)
            {
              return puzzle8::down(this->game,i,j);
            }
            if(position==1)
            {
              return puzzle8::up(this->game,i,j);
            }
            if(position==4)
            {
              return puzzle8::left(this->game,i,j);
            }
          }
        } else {
          if(this->game[i][j]==0)
          {
            if(position==3)
            {
              return puzzle8::down(this->game,i,j);
            }
            if(position==1)
            {
              return puzzle8::up(this->game,i,j);
            }
            if(position==4)
            {
              return puzzle8::left(this->game,i,j);
            }
          }
        }
      /*Find zero in the third row*/
      } else {
        if(j==0)
        {
          if(this->game[i][j]==0)
          {
            if(position==2)
            {
              return puzzle8::right(this->game,i,j);
            }
            if(position==1)
            {
              return puzzle8::up(this->game,i,j);
            }
          }
        } else if(j==1) {
          if(this->game[i][j]==0)
          {
            if(position==2)
            {
              return puzzle8::right(this->game,i,j);
            }
            if(position==1)
            {
              return puzzle8::up(this->game,i,j);
            }
            if(position==4)
            {
              return puzzle8::left(this->game,i,j);
            }
          }
        } else {
          if(this->game[i][j]==0)
          {
            if(position==1)
            {
              return puzzle8::up(this->game,i,j);
            }
            if(position==4)
            {
              return puzzle8::left(this->game,i,j);
            }
          }
        }
      }
    }
  }
  return NULL;
}

/*Vector with all possible piece moves.
e.g. (up, right, down, left) -> [1,2,3,4] and 0 = empty.*/
int* puzzle8::allDirection(int** game)
{
  /*
  Param:
    int (*game)[SIZE] - a game.

  Return: pointer to the vector with possible piece movement.
  */
  int* direction = new int[4];
  for (int i=0; i<SIZE; i++)
  {
    for (int j=0; j<SIZE; j++)
    {
      if(game[i][j]==0 && i==0 && j==0)
      {
        direction[0] = 0;
        direction[1] = 2;
        direction[2] = 3;
        direction[3] = 0;
        return direction;
      }
      if(game[i][j]==0 && i==0 && j==1)
      {
        direction[0] = 0;
        direction[1] = 2;
        direction[2] = 3;
        direction[3] = 4;
        return direction;
      }
      if(game[i][j]==0 && i==0 && j==2)
      {
        direction[0] = 0;
        direction[1] = 0;
        direction[2] = 3;
        direction[3] = 4;
        return direction;
      }
      if(game[i][j]==0 && i==1 && j==0)
      {
        direction[0] = 1;
        direction[1] = 2;
        direction[2] = 3;
        direction[3] = 0;
        return direction;
      }
      if(game[i][j]==0 && i==1 && j==1)
      {
        direction[0] = 1;
        direction[1] = 2;
        direction[2] = 3;
        direction[3] = 4;
        return direction;
      }
      if(game[i][j]==0 && i==1 && j==2)
      {
        direction[0] = 1;
        direction[1] = 0;
        direction[2] = 3;
        direction[3] = 4;
        return direction;
      }
      if(game[i][j]==0 && i==2 && j==0)
      {
        direction[0] = 1;
        direction[1] = 2;
        direction[2] = 0;
        direction[3] = 0;
        return direction;
      }
      if(game[i][j]==0 && i==2 && j==1)
      {
        direction[0] = 1;
        direction[1] = 2;
        direction[2] = 0;
        direction[3] = 4;
        return direction;
      }
      if(game[i][j]==0 && i==2 && j==2)
      {
        direction[0] = 1;
        direction[1] = 0;
        direction[2] = 0;
        direction[3] = 4;
        return direction;
      }
    }
  }
  return NULL;
}

#endif //PUZZLE_CPP
