#Project
EXEC = main

#Compiler
CC = gcc

#Language standards
LANG = c++11

#Library
LIBS = -lstdc++ -lm

#
#Compilation and linking
#

all: $(EXEC) clean

newtoncotes.o: newtoncotes.cpp newtoncotes.h
	$(CC) -c newtoncotes.cpp $(LIBS) -std=$(LANG)

main.o: main.cpp
	$(CC) -c main.cpp $(LIBS) -std=$(LANG)

main: main.o newtoncotes.o
	$(CC) -o $(EXEC) main.o newtoncotes.o $(LIBS)

clean:
	rm -rf *.o *.h.*

run:
	./$(EXEC)
