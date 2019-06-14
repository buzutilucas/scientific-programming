#include <iostream>
#include "queue.h"

using namespace std;

#define SIZE 6 //Changing this value changes the size of a queue.

int main(int argc, char *argv[]) {
  que::Queue<int> queue(SIZE);
  int e;
  int other;

  //Adding elements in a queue.
  cout << "Adding Elements.\n";
  for(int i=0; i<SIZE; i++) {
    cout << "Element " << i+1 << " of the queue: ";
    cin >> e;
    queue.enqueue(e);
  }

  /*Adding other element in the same queue. An error is
  expected because the queue is full.*/
  try{
    cout << "\nAdding another element: ";
    cin >> other;
    queue.enqueue(other);
  }catch(que::QueueException e){
    cerr << "Error: " << e.what() << endl;
  }

  cout << "\nRemove one element.";
  queue.dequeue();
  cout << "\nAdding another element: ";
  cin >> other;
  queue.enqueue(other);

  //Unpacking all elements in the same queue.
  cout << "\nUnpacking...\n";
  while(!queue.empty()) {
    cout << queue.peek() << " ";
    queue.dequeue();
  }

  /*Unpacking another element in the same queue. An error is
  expected because there are not elements in the queue.*/
  try{
    cout << "\n\nUnpacking one again.\n";
    queue.dequeue();
  }catch(que::QueueException e){
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
