#include <iostream>
#include "dlist.h"

using namespace std;
//using namespace dll;

int main(int argc, char *argv[])
{
  dll::LinkedList<int> list;
  int element[] = {1,2,3,4,5,6,7,8,9,10};

  /*Adding elements in a list.*/
  cout << "Adding elements in a list...\n";
  cout << "List: ";
  for(int i = 0; i < 10; i++)
  {
    try
    {
      list.insertBack(new dll::Node<int>(element[i]));
      cout << element[i] << " ";
    } catch(dll::LinkedListException &e) {
      cerr << "Exception occurred: " << e.what() << endl;
    }
  }
  cout << endl;
  cout << "List backwards: ";
  list.listingBackwards();

  /*Adding two elements to the same list, but in the second element added,
  an error is expected because the accessed position does not exist.*/
  try
  {
    cout << "\n\nAdding the element '100' in the position [5].\n";
    list.insert(new dll::Node<int>(100), 5);

    cout << "List now: ";
    list.listing();
    cout << "List backwards: ";
    list.listingBackwards();

    cout << "\nAdding another element in the position [12], but an error is expected.\n";
    list.insert(new dll::Node<int>(100), 12);
  } catch(dll::LinkedListException &e) {
    cerr << "Exception occurred: " << e.what() << endl;
  }

  /*Adding another element to the front of the same list.*/
  cout << "\nAdding the element '50' to the front.\n";
  list.insertFront(new dll::Node<int>(50));

  cout << "List now: ";
  list.listing();
  cout << "List backwards: ";
  list.listingBackwards();

  /*Adding another element to the back of the same list.*/
  cout << "\nAdding the element '150' to the back.\n";
  list.insertBack(new dll::Node<int>(150));

  cout << "List now: ";
  list.listing();
  cout << "List backwards: ";
  list.listingBackwards();

  /*Removes two elements to the same list, but in the second element added,
  an error is expected because the accessed position does not exist.*/
  int data;
  try
  {
    cout << "\n\nRemoving the element '100'.\n";
    data = list.remove(100);
    cout << "Data remove: " << data << endl;

    cout << "List now: ";
    list.listing();
    cout << "List backwards: ";
    list.listingBackwards();

  } catch(dll::LinkedListException &e) {
    cerr << "Exception occurred: " << e.what() << endl;
  }

  /*Removes an element to the front of the same list.*/
  try
  {
    cout << "\n\nRemoves an element to the front.\n";
    data = list.removeFront();
    cout << "Data remove: " << data << endl;

    cout << "List now: ";
    list.listing();
    cout << "List backwards: ";
    list.listingBackwards();

  } catch(dll::LinkedListException &e) {
    cerr << "Exception occurred: " << e.what() << endl;
  }

  /*Removes an element to the back of the same list.*/
  try
  {
    cout << "\nRemoves an element to the back.\n";
    data = list.removeBack();
    cout << "Data remove: " << data << endl;

    cout << "List now: ";
    list.listing();
    cout << "List backwards: ";
    list.listingBackwards();

  } catch(dll::LinkedListException &e) {
    cerr << "Exception occurred: " << e.what() << endl;
  }

  /*Searches some elements.*/
  cout << "\n\nSearching the element '10'.\n";
  dll::Node<int>* temp;
  int i = 10;
  temp = list.search(i);
  cout << "Element searched: " << temp->getData() << endl;

  cout << "\nSearching the element '11'.\n";
  i = 11;
  if(!list.search(i))
  {
    cout << "Element not found\n";
  }

  /*Removes all element to the same list and
  try again remove another element in the list.*/
  try
  {
    cout << "\n\nRemoves all element...\n";
    for(int i = list.getSize()-1; i >=0; --i)
    {
      data = list.removeBack();
    }

    cout << "List now: ";
    list.listing();

    cout << "Removes another element...\n";
    data = list.removeBack();

  } catch(dll::LinkedListException &e) {
    cerr << "Exception occurred: " << e.what() << endl;
  }

  return 0;
}
