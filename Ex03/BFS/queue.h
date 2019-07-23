/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file queue.h                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.2                                                      |
| @created 06/21/2019                                                  |
| @modified 07/01/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Header file containing the Queue and QueueException class
----------------------------------------------------------------------*/

#ifndef QUEUE_H
#define QUEUE_H

#include <exception>
#include <string.h>
#include "dlist.h"

namespace que
{
  template <class Type>
  class Queue : public dll::LinkedList<Type>
  {
    public:
      Queue<Type>() : dll::LinkedList<Type>() { } //default constructor
      ~Queue<Type>() { } //destructor

      /*Methods (function prototypes)*/
      void enqueue(Type data, Type depp, Type** data2d);
      dll::Node<Type>* dequeue();
      Type peek();

  };

  class QueueException : public std::exception
  {
    protected:
      char msg[100];

    public:
      QueueException(const char* e) { strcpy(msg, e); } //default constructor
      ~QueueException() {}; //destructor
      virtual const char* what() { return msg; } //methods
  };
}

#include "queue.cpp"
#endif //QUEUE_H
