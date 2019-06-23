/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file stack.cpp                                                      |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/21/2019                                                  |
| @modified 06/21/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Source file containing the implementation of the Stack Algorithm
----------------------------------------------------------------------*/

#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
#include "stack.h"
#include "dlist.h"

/*----------------------------------------------------------------------
                                Methods of stack class
----------------------------------------------------------------------*/

/*Stack up the next element to the next
empty stack position.*/
template <class Type>
void stk::Stack<Type>::push(Type data)
{
  /*
  Param:
    Type e - element to be stacked up in the stack.
  */
  this->insertBack(new dll::Node<Type>(data));
}

/*Unstacks the element of the stack top
and return it.*/
template <class Type>
Type stk::Stack<Type>::pop()
{
  /*
  Return: the element of the stack top.
  */
  if(this->isEmpty())
    throw StackException("Stack is empty.");
  return this->removeBack();
}

/*Informs what is the element of top.*/
template <class Type>
Type stk::Stack<Type>::top()
{
  /*
  Return: the element of the stack top.
  */
  if(this->isEmpty())
    throw stk::StackException("Stack is empty.");
  dll::Node<Type>* temp = this->last;
  return temp->getData();
}

#endif //STACK_CPP
