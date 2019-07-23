/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file stack.cpp                                                      |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.2                                                      |
| @created 06/21/2019                                                  |
| @modified 07/08/2019                                                 |
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
void stk::Stack<Type>::push(Type data, Type deep, Type** data2d)
{
  /*
  Param:
  Type data   - data to be added in node (data of 1D).
  Type deep   - data to be added in node.(data of 1D).
  Type** data2d - data to be added in node (data of 2D).
  */
  this->insertBack(new dll::Node<Type>(data, deep, data2d));
}

/*Unstacks the element of the stack top
and return it.*/
template <class Type>
dll::Node<Type>* stk::Stack<Type>::pop()
{
  /*
  Return: pointer element of the stack top.
  */
  if(this->isEmpty())
    throw StackException("Stack is empty.");
  return this->removeBack2D();
}

/*Informs what is the element of top.*/
template <class Type>
Type** stk::Stack<Type>::top()
{
  /*
  Return: pointer element of the stack top.
  */
  if(this->isEmpty())
    throw stk::StackException("Stack is empty.");
  dll::Node<Type>* temp = this->last;
  return temp->getData2D();
}

#endif //STACK_CPP
