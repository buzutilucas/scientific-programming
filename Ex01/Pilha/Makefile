all: main clean

stack.o: stack.cpp stack.h
	gcc -c stack.cpp -lstdc++ -std=c++11

main.o: main.cpp
	gcc -c main.cpp -lstdc++ -std=c++11

main: main.o stack.o
	gcc -o main main.o stack.o -lstdc++

clean:
	rm -rf *.o *.h.*

run:
	./main
