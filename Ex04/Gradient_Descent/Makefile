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

dlist.o: dlist.cpp dlist.h
	$(CC) -c dlist.cpp $(LIBS) -std=$(LANG)

graddesc.o: graddesc.cpp graddesc.h
	$(CC) -c graddesc.cpp $(LIBS) -std=$(LANG)

main.o: main.cpp
	$(CC) -c main.cpp $(LIBS) -std=$(LANG)

main: main.o graddesc.o dlist.o
	$(CC) -o $(EXEC) main.o graddesc.o dlist.o $(LIBS)

clean:
	rm -rf *.o *.h.*

run:
	./$(EXEC)
