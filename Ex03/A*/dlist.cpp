/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file dlist.cpp                                                      |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.4                                                      |
| @created 06/19/2019                                                  |
| @modified 07/08/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
            Source file containing the implementation of the
                       Doubly Linked List Algorithm
----------------------------------------------------------------------*/

#ifndef DLIST_CPP
#define DLIST_CPP

#include <iostream>
#include "dlist.h"

/*----------------------------------------------------------------------
                        Methods of Node class
----------------------------------------------------------------------*/
//First constructor
template <class Type>
dll::Node<Type>::Node(Type data)
{
  /*
  Param:
    Type data - data to be added in node.
  */
  this->data = data;
  this->data2D = NULL;
  this->next = NULL;
  this->before = NULL;
}

//Second constructor
template <class Type>
dll::Node<Type>::Node(Type** data)
{
  /*
  Param:
    Type** data - data to be added in node (data of 2D).
  */
  this->data2D = new Type*[3];
  for(int i=0; i<3; i++)
  {
    this->data2D[i] = new Type[3];
    for(int j=0; j<3; j++)
    {
      this->data2D[i][j] = data[i][j];
    }
  }
  this->data = 0;
  this->next = NULL;
  this->before = NULL;
}

//Third constructor
template <class Type>
dll::Node<Type>::Node(Type data, Type deep, Type** data2d)
{
  /*
  Param:
    Type data   - data to be added in node.
    Type** data - data to be added in node (data of 2D).
  */
  this->data2D = new Type*[3];
  for(int i=0; i<3; i++)
  {
    this->data2D[i] = new Type[3];
    for(int j=0; j<3; j++)
    {
      this->data2D[i][j] = data2d[i][j];
    }
  }
  this->data = data;
  this->deep = deep;
  this->next = NULL;
  this->before = NULL;
}

//Destructor
template <class Type>
dll::Node<Type>::~Node() { }

//Get the element in node
template <class Type>
Type dll::Node<Type>::getDeep()
{
  /*
  Return: the element 1D in node.
  */
  return this->deep;
}

//Get the element in node
template <class Type>
Type dll::Node<Type>::getData()
{
  /*
  Return: the element 1D in node.
  */
  return this->data;
}

//Get the element in node
template <class Type>
Type** dll::Node<Type>::getData2D()
{
  /*
  Return: the element pointer 2D in node.
  */
  return this->data2D;
}

/*----------------------------------------------------------------------
                        Methods of LinkedList class
----------------------------------------------------------------------*/
/*Default constructor*/
template <class Type>
dll::LinkedList<Type>::LinkedList()
{
  this->begin = NULL;
  this->last = NULL;
  this->size = 0;
}

/*Destructor*/
template <class Type>
dll::LinkedList<Type>::~LinkedList()
{
  for(int i = this->size-1; i >= 0; --i)
  {
    LinkedList::removeFront();
  }
}

/*Get the size in list*/
template <class Type>
int dll::LinkedList<Type>::getSize()
{
  /*
  Return: the size in list.
  */
  return this->size;
}

/*Inserts an element in any position. Check if the list
is empty and start the list by adding the first node to it.
If the position is not found an exception is thrown.*/
template <class Type>
void dll::LinkedList<Type>::insert(Node<Type>* node, unsigned int position)
{
  /*
  Param:
    Node<Type>* node  - pointer to node object.
    int position - Position to insert an element (default: second position [1]).
  */
  if(LinkedList::isEmpty())
  {
    /*Adds the node in the list if
    there is no start node.*/
    this->begin = node;
    this->last = this->begin;
    this->size++;
  } else if(position == 0) {
    /*Adds node in the first position [0].*/
    LinkedList::insertFront(node);
  } else if(position == this->size) {
    /*Adds node in the last position [n].*/
    LinkedList::insertBack(node);
  } else if(position > this->size) {
    /*Throws an exception when it fails
    to access a position.*/
    throw dll::LinkedListException("Position access failure.");
  } else {
    /*Inserts an element in
    position ([1] to [n-1]) found.*/
    unsigned int count = 1;
    Node<Type>* tempPrevious = this->begin;
    Node<Type>* tempNext = this->begin->next;

    while(count != position)
    {
      /*Finds the position.*/
      count++;
      tempPrevious = tempPrevious->next;
      tempNext = tempNext->next;
    }
    /*Inserts an element in the
    position found.*/
    node->next = tempPrevious->next;
    tempPrevious->next = node;
    node->before = tempNext->before;
    tempNext->before = node;
    this->size++;
  }
}

/*Inserts an element in the last position of the list.
Check if the list is empty and start the list by
adding the first node to it.*/
template <class Type>
void dll::LinkedList<Type>::insertBack(Node<Type>* node)
{
  /*
  Param:
    Node<Type>* node  - pointer to node object.
  */
  if(LinkedList::isEmpty())
  {
    /*Adds the node in the list if
    there is no start node.*/
    this->begin = node;
    this->last = this->begin;
    this->size++;
  } else {
    /*Adds the node at the
    end of the list.*/
    this->last->next = node;
    node->before = this->last;
    this->last = node;
    this->size++;
  }
}

/*Inserts an element in the first position of the list.
Check if the list is empty and start the list by
adding the first node to it.*/
template <class Type>
void dll::LinkedList<Type>::insertFront(Node<Type>* node)
{
  /*
  Param:
    Node<Type>* node  - pointer to node object.
  */
  if(LinkedList::isEmpty())
  {
    /*Adds the node in the list if
    there is no start node.*/
    this->begin = node;
    this->last = this->begin;
    this->size++;
  } else {
    /*Adds the node at the
    top of the list.*/
    this->begin->before = node;
    node->next = this->begin;
    this->begin = node;
    this->size++;
  }
}

/*Removes an element in any position of the list.
Check the status of the list and if is empty or
element was not found, so an exception is thrown.*/
template <class Type>
Type dll::LinkedList<Type>::remove(Type data)
{
  /*
  Param:
    Type data - data to be removed.

  Return: the data removed.
  */
  if(LinkedList::isEmpty()) //checking the status of the list
    throw dll::LinkedListException("List is empty.");

  Node<Type>* temp = LinkedList::search(data); //the element's pointer selected
  if(temp == NULL) //checking if the element exists in the list
    /*Throws an exception when an element is not found.*/
    throw dll::LinkedListException("Element not found to be removed.");

  Type element;
  if(temp->before == NULL) //checks if the element is in the first position
  {
    /*Removes element in the first position [0].*/
    element = LinkedList::removeFront();
    return element;
  } else if(temp->next == NULL) { //checks if the element is in the last position
    /*Removes element in the last position [n].*/
    element = LinkedList::removeBack();
    return element;
  } else {
    /*Removes the elements that are between
    the head and the tail of the list.*/
    temp->before->next = temp->next;
    temp->next->before = temp->before;
    element = temp->getData();
    delete temp; //delete the element selected
    this->size--;
    return element;
  }
}

/*Removes an element in any position of the list.
Check the status of the list and if is empty or
element was not found, so an exception is thrown.*/
template <class Type>
dll::Node<Type>* dll::LinkedList<Type>::remove(unsigned int position)
{
  /*
  Param:
    unsigned int position - lista position to be removed.

  Return: node pointer removed.
  */
  if(LinkedList::isEmpty()) //checking the status of the list
    throw dll::LinkedListException("List is empty.");

  Node<Type>* temp = LinkedList::search(position); //the element's pointer selected
  if(temp == NULL) //checking if the element exists in the list
    /*Throws an exception when an element is not found.*/
    throw dll::LinkedListException("Node not found to be removed.");

  if(temp->before == NULL) //checks if the element is in the first position
  {
    /*Removes element in the first position [0].*/
    temp = LinkedList::removeFront2D();
    return temp;
  } else if(temp->next == NULL) { //checks if the element is in the last position
    /*Removes element in the last position [n].*/
    temp = LinkedList::removeBack2D();
    return temp;
  } else {
    /*Removes the elements that are between
    the head and the tail of the list.*/
    temp->before->next = temp->next;
    temp->next->before = temp->before;
    this->size--;
    return temp;
  }
}

/*Removes an element in the last position of the list.
Check the status of the list and if is empty an exception
is thrown.*/
template <class Type>
Type dll::LinkedList<Type>::removeBack()
{
  /*
  Return: the data removed.
  */
  if(LinkedList::isEmpty()) //checking the status of the list
    throw dll::LinkedListException("List is empty.");

  Node<Type>* temp = this->last; //the last element's pointer
  this->last = this->last->before;
  if(this->size == 1)
  {
    /*Reset head and tail list.*/
    this->begin = NULL;
    this->last = NULL;
  } else {
    this->last->next = NULL;
  }

  Type data = temp->getData(); //data remove
  delete temp; //delete the last element
  this->size--;
  return data;
}

/*Removes an element in the last position of the list.
Check the status of the list and if is empty an exception
is thrown.*/
template <class Type>
dll::Node<Type>* dll::LinkedList<Type>::removeBack2D()
{
  /*
  Return: the data removed (data of 2D).
  */
  if(LinkedList::isEmpty()) //checking the status of the list
    throw dll::LinkedListException("List is empty.");

  Node<Type>* temp = this->last; //the last element's pointer
  this->last = this->last->before;
  if(this->size == 1)
  {
    /*Reset head and tail list.*/
    this->begin = NULL;
    this->last = NULL;
  } else {
    this->last->next = NULL;
  }

  this->size--;
  return temp;
}

/*Removes an element in the first position of the list.
Check the status of the list and if is empty an exception
is thrown.*/
template <class Type>
Type dll::LinkedList<Type>::removeFront()
{
  /*
  Return: the data removed.
  */
  if(LinkedList::isEmpty()) //checking the status of the list
    throw dll::LinkedListException("List is empty.");

  Node<Type>* temp = this->begin; //the start element's pointer
  this->begin = this->begin->next;
  if(this->size == 1)
    this->last = NULL;
  else
    this->begin->before = NULL;

  Type data = temp->getData(); //data remove
  delete temp; //delete the start element
  this->size--;
  return data;
}

/*Removes an element in the first position of the list.
Check the status of the list and if is empty an exception
is thrown.*/
template <class Type>
dll::Node<Type>* dll::LinkedList<Type>::removeFront2D()
{
  /*
  Return: the data removed.
  */
  if(LinkedList::isEmpty()) //checking the status of the list
    throw dll::LinkedListException("List is empty.");

  Node<Type>* temp = this->begin; //the start element's pointer
  this->begin = this->begin->next;
  if(this->size == 1)
    this->last = NULL;
  else
    this->begin->before = NULL;

  this->size--;
  return temp;
}

/*Searches for an element in the list.*/
template <class Type>
dll::Node<Type>* dll::LinkedList<Type>::search(Type data)
{
  /*
  Param:
    Type2 data - data to be searched.

  Return: Searches for an element in the list
  and returns an object node or NULL if the element
  is not found.
  */
  Node<Type>* temp = this->begin;
  while(temp)
  {
    /*Finds the element.*/
    if(temp->getData() == data)
      return temp;
    temp = temp->next;
  }
  return NULL;
}

/*Searches for an element 2D in the list.*/
template <class Type>
dll::Node<Type>* dll::LinkedList<Type>::search(Type** data, int row, int column)
{
  /*
  Param:
    Type** data - pointer data to be searched.
    int row     - number of row in the data.
    int column  - number of column in the data.

  Return: Searches for an element in the list
  and returns an object node or NULL if the element
  is not found.
  */
  Node<Type>* temp = this->begin;
  while(temp)
  {
    /*Finds the element.*/
    int count = 0;
    int target = row*column;
    for(int i=0; i<row; i++)
    {
      for(int j=0; j<column; j++)
      {
        if(temp->getData2D()[i][j] == data[i][j])
          count++;
      }
    }
    if(count == target)
      return temp;
    temp = temp->next;
  }
  return NULL;
}

/*Searches for an element in the list.*/
template <class Type>
dll::Node<Type>* dll::LinkedList<Type>::search(unsigned int position)
{
  /*
  Param:
    int position - position to search a node.

  Return: Searches for a node in the list and returns
  an object node or NULL if the element is not found.
  */
  Node<Type>* temp = this->begin;
  unsigned int count = 0;
  while(temp)
  {
    /*Finds the element.*/
    if(count == position)
      return temp;
    temp = temp->next;
    count++;
  }
  return NULL;
}

/*Prints all elements in the list.*/
template <class Type>
void dll::LinkedList<Type>::listing()
{
  Node<Type>* temp = this->begin;
  while(temp)
  {
    std::cout << temp->getData() << " ";
    temp = temp->next;
  }
  std::cout << "\n";
}

/*Prints backwards all elements in the list.*/
template <class Type>
void dll::LinkedList<Type>::listingBackwards()
{
  Node<Type>* temp = this->last;
  while(temp)
  {
    std::cout << temp->getData() << " ";
    temp = temp->before;
  }
  std::cout << "\n";
}

/*Checks if the list is empty.*/
template <class Type>
bool dll::LinkedList<Type>::isEmpty()
{
  /*
  Return: if the list is empty then return TRUE else return FALSE.
  */
  if(this->size == 0)
    return true;
  else
    return false;
}

#endif //DLIST_CPP
