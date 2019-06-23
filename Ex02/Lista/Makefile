all: mainList mainQueue mainStack clean

dlist.o: dlist.cpp dlist.h
	gcc -c dlist.cpp -lstdc++ -std=c++11

mainList.o: mainList.cpp
	gcc -c mainList.cpp -lstdc++ -std=c++11

mainList: mainList.o dlist.o
	gcc -o mainList mainList.o dlist.o -lstdc++

queue.o: queue.cpp queue.h
	gcc -c queue.cpp -lstdc++ -std=c++11

mainQueue.o: mainQueue.cpp
	gcc -c mainQueue.cpp -lstdc++ -std=c++11

mainQueue: mainQueue.o queue.o
	gcc -o mainQueue mainQueue.o queue.o -lstdc++

stack.o: stack.cpp stack.h
	gcc -c stack.cpp -lstdc++ -std=c++11

mainStack.o: mainStack.cpp
	gcc -c mainStack.cpp -lstdc++ -std=c++11

mainStack: mainStack.o stack.o
	gcc -o mainStack mainStack.o stack.o -lstdc++

clean:
	rm -rf *.o *.h.*
