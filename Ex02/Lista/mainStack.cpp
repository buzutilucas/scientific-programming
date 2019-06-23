#include <iostream>
#include "stack.h"

using namespace std;

int main(int argc, char *argv[])
{
  stk::Stack<int> stack;
  int element[] = {1,2,3,4,5,6,7,8,9,10};

  /*Adding elements in a stack.*/
  cout << "Adding Elements.\n";
  for(int i=0; i<10; i++) {
    stack.push(element[i]);
  }
  cout << "Stack: ";
  stack.listing();

  /*Shows top element in the same stack.*/
  try
  {
    int top = stack.top();
    cout << "\nTop element in the stack: " << top;
  } catch (stk::StackException &e) {
    cerr << "Exception occurred: " << e.what() << endl;
  }

  /*Adding other element in the same stack.*/
  cout << "\n\nAdding other element '11'.";
  stack.push(11);
  cout << "\nStack now: ";
  stack.listing();

  /*Unpacking all elements in the same stack.*/
  cout << "\nUnpacking...\n";
  int firstElement;
  while(!stack.isEmpty())
  {
    try{
      firstElement = stack.pop();
      cout << firstElement << " ";
    } catch(stk::StackException &e) {
      cerr << "Exception occurred: " << e.what() << endl;
    }
  }
  cout << "\nStack now: ";
  stack.listing();

  /*Unpacking another element in the same stack. An error is
  expected because there are not elements in the stack.*/
  try{
    cout << "\nUnpacking another element.\n";
    firstElement = stack.pop();
    cout << stack.top() << " ";
  } catch(stk::StackException &e) {
    cerr << "Exception occurred: " << e.what() << endl;
  }

  return 0;
}
