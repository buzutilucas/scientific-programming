/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file queue.cpp                                                      |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.2                                                      |
| @created 06/21/2019                                                  |
| @modified 07/01/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Source file containing the implementation of the Queue Algorithm
----------------------------------------------------------------------*/

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
#include "queue.h"
#include "dlist.h"

/*----------------------------------------------------------------------
                          Methods of queue class
----------------------------------------------------------------------*/

/*Queue up the next element to the next
queue position.*/
template <class Type>
void que::Queue<Type>::enqueue(Type data, Type deep, Type** data2d)
{
  /*
  Param:
    Type data   - data to be added in node (data of 1D).
    Type deep   - data to be added in node.(data of 1D).
    Type** data2d - data to be added in node (data of 2D).
  */
  this->insertFront(new dll::Node<Type>(data, deep, data2d));
}

/*Removes the starting element from the
queue.*/
template <class Type>
dll::Node<Type>* que::Queue<Type>::dequeue()
{
  if(this->isEmpty())
    throw que::QueueException("Queue is empty.");
  return this->removeBack2D();
}

/*Informs what is the first element.*/
template <class Type>
Type que::Queue<Type>::peek()
{
  /*
  Return: the starting element from the queue.
  */
  if(this->isEmpty())
    throw que::QueueException("Queue is empty.");
  dll::Node<Type>* temp = this->last;
  return temp->getData();
}

#endif //QUEUE_CPP
