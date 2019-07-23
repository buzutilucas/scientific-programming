#include <iostream>
#include <ctime>
#include "bfs.h"

using namespace std;

int main(int argc, char *argv[]) {
  clock_t time_req;

  /*Goal of the game*/
  int goal[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
  };

  /*Beginning of the game*/
  int initial[3][3] = {
    {4,1,6},
    {3,2,8},
    {7,0,5}
  };

  BFS puzzle(initial, goal);

  time_req = clock();
  puzzle.search();
  time_req = clock() -time_req;

  cout << endl << "Breadth-First Search Algorithm" << endl;
  cout << "Time: " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;

  return 0;
}
