#Kyle Hennessy 12/11/2020
#Makefile
#Contains commands to compile project

CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a cpp file of same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o Semaphore.o Barrier.o
	$(CC) -o main Semaphore.o main.o Barrier.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#deletes all .o files
CLEAN:
	rm *.o
