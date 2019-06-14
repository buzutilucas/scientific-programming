/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file stack.cpp                                                      |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/12/2019                                                  |
| @modified 06/12/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Source file containing the implementation of the Stack Algorithm
----------------------------------------------------------------------*/

#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
#include "stack.h"

/*----------------------------------------------------------------------
                                Methods of stack class
----------------------------------------------------------------------*/
//Default constructor (Stack class).
template <class Type>
stk::Stack<Type>::Stack(int size)
{
  /*
  Param:
    int size - size of the stack.
  */
  s = new Type[size];
  this->size = size;
  t = -1;
}

//Destructor (Stack class).
template <class Type>
stk::Stack<Type>::~Stack()
{
  delete[] s;
}

/*Stack up the next element to the next
empty stack position.*/
template <class Type>
void stk::Stack<Type>::push(Type e)
{
  /*
  Param:
    Type e - element to be stacked up in the stack.
  */
  if(Stack::full())
    throw stk::StackException("Stack is full.");
  s[++t] = e;
}

/*Unstacks the element of the stack top
and return it.*/
template <class Type>
Type stk::Stack<Type>::pop()
{
  /*
  Return: the element of the stack top.
  */
  if(Stack::empty())
    throw stk::StackException("Stack is empty.");
  return s[t--];
}

/*Checks whether the stack is empty and
returns TRUE in case of true statement or
FALSE in the opposite case.*/
template <class Type>
bool stk::Stack<Type>::empty()
{
  if(t == -1)
    return true;
  else
    return false;
}

/*Checks whether the stack is full and
returns TRUE in case of true statement or
FALSE in the opposite case.*/
template <class Type>
bool stk::Stack<Type>::full()
{
  if(t == size-1)
    return true;
  else
    return false;
}

/*Informs what is the element of top.*/
template <class Type>
Type stk::Stack<Type>::top()
{
  /*
  Return: the element of the stack top.
  */
  if(Stack::empty())
    throw stk::StackException("Stack is empty.");
  return s[t];
}

#endif //STACK_CPP
