/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file queue.h                                                        |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 06/12/2019                                                  |
| @modified 06/12/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
Header file containing the Queue and QueueException class
----------------------------------------------------------------------*/

#ifndef QUEUE_H
#define QUEUE_H

#include <exception>
#include <string.h>

namespace que
{
  template <class Type>
  class Queue
  {
    private:
      Type* q;
      int size;
      int p;

    public:
      Queue<Type>(int e); //default constructor
      ~Queue<Type>(); //destructor
      //Methods (function prototypes)
      void enqueue(Type e);
      void dequeue();
      bool empty();
      bool full();
      Type peek();

  };

  class QueueException : public std::exception
  {
    protected:
      char msg[100];

    public:
      QueueException(const char* e) { strcpy(msg, e); } //default constructor
      ~QueueException() {}; //destructor
      virtual const char* what() { return msg; } //function
  };
}

#include "queue.cpp"
#endif //QUEUE_H
