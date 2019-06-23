/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file dlist.h                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/19/2019                                                  |
| @modified 06/21/2019                                                 |
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
      Type data; //elemente of node

    public:
      /*Attribute*/
      Node<Type>* next; //object pointer to next node
      Node<Type>* before; //object pointer to previous node

      Node<Type>(Type data); //default constructor
      ~Node<Type>(); //destructor
      Type getData(); //method (function prototype)
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
      Type removeBack();
      Type removeFront();
      Node<Type>* search(Type data);
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
