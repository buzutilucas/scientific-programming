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

hillc.o: hillc.cpp hillc.h
	$(CC) -c hillc.cpp $(LIBS) -std=$(LANG)

main.o: main.cpp
	$(CC) -c main.cpp $(LIBS) -std=$(LANG)

main: main.o hillc.o puzzle.o dlist.o
	$(CC) -o $(EXEC) main.o hillc.o puzzle.o dlist.o $(LIBS)

clean:
	rm -rf *.o *.h.*

run:
	./$(EXEC)
