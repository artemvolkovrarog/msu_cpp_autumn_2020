CC = g++
all: test
FLAGS = -std=c++17 -Wall
test: parser.o  main.o
	$(CC) $(FLAGS) -o test parser.o main.o
main.o: main.cpp parser.hpp
	$(CC) $(FLAGS) -c main.cpp
parser.o: parser.cpp parser.hpp
	$(CC) $(FLAGS) -c parser.cpp
clean:
	rm -rf *.o my_parser