#include <iostream>
#include "stack.h"

using namespace std;

#define SIZE 6 //Changing this value changes the size of a stack.

int main(int argc, char *argv[])
{
  stk::Stack<int> stack(SIZE);
  int e;
  int other;

  //Adding elements in a stack.
  cout << "Adding Elements.\n";
  for(int i=0; i<SIZE; i++) {
    cout << "Element " << i+1 << " of the stack: ";
    cin >> e;
    stack.push(e);
  }

  /*Adding other element in the same stack. An error is
  expected because the stack is full.*/
  try
  {
    cout << "\nAdding other element: ";
    cin >> other;
    stack.push(other);
  }catch(stk::StackException e)
  {
    cerr << "Error: " << e.what() << endl;
  }

  cout << "\nRemove one element.";
  stack.pop();
  cout << "\nAdding another element: ";
  cin >> other;
  stack.push(other);

  //Unpacking all elements in the same stack.
  cout << "\nUnpacking...\n";
  while(!stack.empty())
  {
    cout << stack.top() << " ";
    stack.pop();
  }

  /*Unpacking another element in the same stack. An error is
  expected because there are not elements in the stack.*/
  try
  {
    cout << "\n\nUnpacking one again.\n";
    stack.pop();
  }catch(stk::StackException e)
  {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
