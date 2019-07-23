/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file stack.h                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.2                                                      |
| @created 06/21/2019                                                  |
| @modified 07/08/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Header file containing the Stack and StackException class
----------------------------------------------------------------------*/

#ifndef STACK_H
#define STACK_H

#include <exception>
#include <string.h>
#include "dlist.h"

namespace stk
{
  template <class Type>
  class Stack : public dll::LinkedList<Type>
  {
    public:
      Stack<Type>() : dll::LinkedList<Type>() { }; //default constructor
      ~Stack<Type>() { }; //destructor

      /*Methods (function prototypes)*/
      void push(Type data, Type deep, Type** data2d);
      dll::Node<Type>* pop();
      Type** top();
  };

  class StackException
  {
    protected:
      char msg[100];

    public:
      StackException(const char* e) { strcpy(msg, e); } //default constructor
      ~StackException() {} //destructor
      virtual const char* what() { return msg; } //methods
  };
}

#include "stack.cpp"
#endif //STACK_H
