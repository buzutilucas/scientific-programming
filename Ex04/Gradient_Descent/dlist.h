/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file dlist.h                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.4                                                      |
| @created 06/19/2019                                                  |
| @modified 08/11/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Header file containing the LinkedList and LinkedListException class
----------------------------------------------------------------------*/

#ifndef DLIST_H
#define DLIST_H

#include <exception>
#include <string.h>

namespace dll //Doubly Linked List
{
  template <class Type>
  class Node
  {
    private:
      /*Attribute*/
      /*All data of the node.*/
      Type data; //element of node (data of 1D)
      Type** data2D; //elemente of node (data of 2D)
      Type deep; //element of node (data of 1D)

    public:
      /*Attribute*/
      Node<Type>* next; //object pointer to next node
      Node<Type>* before; //object pointer to previous node

      Node<Type>(Type data); //first constructor
      Node<Type>(Type** data); //second constructor
      Node<Type>(Type data, Type deep, Type** data2d); //third constructor
      ~Node<Type>(); //destructor

      /*Method (function prototype)*/
      Type getDeep();
      Type getData();
      Type** getData2D();
  };

  template <class Type>
  class LinkedList
  {
    protected:
      /*Attribute*/
      Node<Type>* begin; //pointer to head list
      Node<Type>* last; //pointer to tail list
      int size;

    public:
      LinkedList<Type>(); //default constructor
      ~LinkedList<Type>(); //destructor

      /*Methods (function prototypes)*/
      int getSize();
      void insert(Node<Type>* node, unsigned int position=0);
      void insertBack(Node<Type>* node);
      void insertFront(Node<Type>* node);
      Type remove(Type data);
      Node<Type>* remove(unsigned int position);
      Type removeBack();
      Node<Type>* removeBack2D();
      Type removeFront();
      Node<Type>* removeFront2D();
      Node<Type>* search(Type data);
      Node<Type>* search(Type** data, int row, int column);
      Node<Type>* search(unsigned int position);
      void listing();
      void listingBackwards();
      bool isEmpty();
  };

  class LinkedListException : public std::exception
  {
    protected:
      char msg[100];

    public:
      LinkedListException(const char* e) { strcpy(msg, e); } //default constructor
      ~LinkedListException() {} //destructor
      virtual const char* what() { return msg; } //function
  };
}

#include "dlist.cpp"
#endif //DLIST_H
