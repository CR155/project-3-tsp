CC = g++ -std=c++14
CFLAGS = -Wall -g
main: tsp.o
	$(CC) $(CFLAGS) -o tsp tsp.o
tsp.o: tsp.cpp
