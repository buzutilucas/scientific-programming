#include <iostream>
#include <ctime>
#include "dfs.h"

using namespace std;

int main(int argc, char *argv[]) {
  clock_t time_req;

  /*+++++ To test the algorithm ++++++*/
  /*
  int initial[3][3] = {
    {0,2,3},
    {1,4,5},
    {8,7,6}
  };

  int goal[3][3] = {
    {1,2,3},
    {8,0,4},
    {7,6,5}
  };
  */
  /*++++++++++++++++++++++++++++++++++*/

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

  DFS puzzle(initial, goal);

  time_req = clock();
  puzzle.search();
  time_req = clock() - time_req;

  cout << endl << "Depth-First Search Algorithm" << endl;
  cout << "Time: " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;

  return 0;
}
