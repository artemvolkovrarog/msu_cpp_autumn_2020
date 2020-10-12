CC = g++
all: test
FLAGS = -std=c++17 -Wall
test: Allocator.o  main.o
	$(CC) $(FLAGS) -o test Allocator.o main.o
main.o: main.cpp Allocator.hpp
	$(CC) $(FLAGS) -c main.cpp
allocator.o: Allocator.cpp Allocator.hpp
	$(CC) $(FLAGS) -c Allocator.cpp
clean:
	rm -rf *.o my_allocator