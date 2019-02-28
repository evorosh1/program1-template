P = program1
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: program1.o vector.o planet.o star.o list.o
	g++ $(CFLAGS) program1.o planet.o vector.o star.o list.o -o program1

program1.o: program1.cpp
	g++ -c program1.cpp -o program1.o

vector.o: Vector.cpp
	g++ -c Vector.cpp -o vector.o

planet.o: Planet.cpp
	g++ -c Planet.cpp -o planet.o

star.o: Star.cpp
	g++ -c Star.cpp -o star.o

list.o: List.cpp
	g++ -c List.cpp -o list.o

run: all
	./$(P)

clean:
	rm -rf *.o $(P)

memcheck: all
	valgrind -v ./$(P)
