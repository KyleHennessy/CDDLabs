#Kyle Hennessy 02/11/2020
#Lab 02 Makefile
#Used to contain commands to compile Semaphore lab project

CC=g++
CFLAGS= -std=c++11 -pthread


ALL: main.o
	$(CC) main.cpp Semaphore.cpp -o main $(CFLAGS)

DEBUGFLAGS = -g -O0

CLEAN:
	rm *.o
