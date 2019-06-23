#include <iostream>
#include "queue.h"

using namespace std;


int main(int argc, char *argv[]) {
  que::Queue<int> queue;
  int element[] = {1,2,3,4,5,6,7,8,9,10};

  /*Adding elements in a queue.*/
  cout << "Adding Elements.\n";
  for(int i=0; i<10; i++) {
    queue.enqueue(element[i]);
  }
  cout << "Queue: ";
  queue.listing();

  /*Shows first element in the same queue.*/
  try
  {
    int peek = queue.peek();
    cout << "\nFirst element in the queue: " << peek;
  } catch (que::QueueException &e) {
    cerr << "Exception occurred: " << e.what() << endl;
  }

  /*Adding other element in the same queue.*/
  cout << "\n\nAdding other element '11'.";
  queue.enqueue(11);
  cout << "\nQueue now: ";
  queue.listing();

  /*Unpacking all elements in the same queue.*/
  cout << "\nUnpacking...\n";
  int firstElement;
  while(!queue.isEmpty())
  {
    try{
      firstElement = queue.dequeue();
      cout << firstElement << " ";
    } catch(que::QueueException&e) {
      cerr << "Exception occurred: " << e.what() << endl;
    }
  }
  cout << "\nQueue now: ";
  queue.listing();

  /*Unpacking another element in the same queue. An error is
  expected because there are not elements in the queue.*/
  try{
    cout << "\nUnpacking one again.\n";
    firstElement = queue.dequeue();
    cout << firstElement << " ";
  }catch(que::QueueException &e){
    cerr << "Exception occurred: " << e.what() << endl;
  }

  return 0;
}
