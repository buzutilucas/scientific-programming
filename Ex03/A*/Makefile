#Project
EXEC = main

#Compiler
CC = gcc

#Language standards
LANG = c++11

#Library
LIBS = -lstdc++

#
#Compilation and linking
#

all: $(EXEC) clean

dlist.o: dlist.cpp dlist.h
	$(CC) -c dlist.cpp $(LIBS) -std=$(LANG)

puzzle.o: puzzle.cpp puzzle.h
	$(CC) -c puzzle.cpp $(LIBS) -std=$(LANG)

astar.o: astar.cpp astar.h
	$(CC) -c astar.cpp $(LIBS) -std=$(LANG)

main.o: main.cpp
	$(CC) -c main.cpp $(LIBS) -std=$(LANG)

main: main.o astar.o puzzle.o dlist.o
	$(CC) -o $(EXEC) main.o astar.o puzzle.o dlist.o $(LIBS)

clean:
	rm -rf *.o *.h.*

run:
	./$(EXEC)
