/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file stack.h                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/12/2019                                                  |
| @modified 06/12/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Header file containing the Stack and StackException class
----------------------------------------------------------------------*/

#ifndef STACK_H
#define STACK_H

#include <exception>
#include <string.h>

namespace stk
{
  template <class Type>
  class Stack
  {
    private:
      Type* s;
      int size;
      int t;

    public:
      Stack<Type>(int e); //default constructor
      ~Stack<Type>(); //destructor
      //Methods (function prototypes)
      void push(Type e);
      Type pop();
      bool empty();
      bool full();
      Type top();

  };

  class StackException : public std::exception
  {
    protected:
      char msg[100];

    public:
      StackException(const char* e) { strcpy(msg, e); } //default constructor
      ~StackException() {} //destructor
      virtual const char* what() { return msg; } //function
  };
}

#include "stack.cpp"
#endif //STACK_H
