/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file queue.cpp                                                      |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/12/2019                                                  |
| @modified 06/12/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Source file containing the implementation of the Queue Algorithm
----------------------------------------------------------------------*/

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
#include "queue.h"

/*----------------------------------------------------------------------
                                Methods of queue class
----------------------------------------------------------------------*/
//Default constructor.
template <class Type>
que::Queue<Type>::Queue(int size)
{
  /*
  Param:
    int size - size of the queue.
  */
  q = new Type[size];
  this->size = size;
  p = -1;
}

//Destructor.
template <class Type>
que::Queue<Type>::~Queue()
{
  delete[] q;
}

/*Queue up the next element to the next
queue position.*/
template <class Type>
void que::Queue<Type>::enqueue(Type e)
{
  /*
  Param:
    Type e - element to be queued up in the queue.
  */
  if(Queue::full())
    throw que::QueueException("Queue is full.");
  q[++p] = e;
}

/*Removes the starting element from the
queue.*/
template <class Type>
void que::Queue<Type>::dequeue()
{
  if(Queue::empty())
    throw que::QueueException("Queue is empty.");

  int i = 0;
  while(i<p)
  {
    q[i] = q[i+1];
    i++;
  }
  --p;
}

/*Checks whether the queue is empty and
returns TRUE in case of true statement or
FALSE in the opposite case.*/
template <class Type>
bool que::Queue<Type>::empty()
{
  if(p == -1)
    return true;
  else
    return false;
}

/*Checks whether the queue is full and
returns TRUE in case of true statement or
FALSE in the opposite case.*/
template <class Type>
bool que::Queue<Type>::full()
{
  if(p == size-1)
    return true;
  else
    return false;
}

/*Informs what is the first element.*/
template <class Type>
Type que::Queue<Type>::peek()
{
  /*
  Return: the starting element from the queue.
  */
  if(Queue::empty())
    throw que::QueueException("Queue is empty.");
  return q[0];
}

#endif //QUEUE_CPP
