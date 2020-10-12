CC = g++
all: my_allocator
FLAGS = -std=c++17 -Wall
my_allocator: Allocator.o  main.o
	$(CC) $(FLAGS) -o my_allocator Allocator.o main.o
main.o: main.cpp Allocator.hpp
	$(CC) $(FLAGS) -c main.cpp
allocator.o: Allocator.cpp Allocator.hpp
	$(CC) $(FLAGS) -c Allocator.cpp
clean:
	rm -rf *.o my_allocator