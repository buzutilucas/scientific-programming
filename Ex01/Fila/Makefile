all: main clean

queue.o: queue.cpp queue.h
	gcc -c queue.cpp -lstdc++ -std=c++11

main.o: main.cpp
	gcc -c main.cpp -lstdc++ -std=c++11

main: main.o queue.o
	gcc -o main main.o queue.o -lstdc++

clean:
	rm -rf *.o *.h.*

run:
	./main
