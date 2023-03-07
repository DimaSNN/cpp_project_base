CC=g++
CFLAGS=-I

all: main

main: main.o
	$(CC) main.o -pthread -o main.out

main.o: main.cpp
	$(CC) -g -c --std=c++17 main.cpp

clean:
	rm -rf *.o main.out


