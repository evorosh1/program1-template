P = program1

all: program1.o planet.o vector.o star.o list.o
	g++ program1.o planet.o vector.o star.o list.o -o program1

program1.o: program1.cpp
	g++ -c program1.cpp -o program1.o

vector.o: vector.cpp
	g++ -c vector.cpp -o vector.o

planet.o: planet.cpp
	g++ -c planet.cpp -o planet.o

star2.o: star.cpp
	g++ -c star.cpp -o star.o

list.o: list.cpp
	g++ -c list.cpp -o list.o

run: all
	./$(P)

clean:
	rm -rf *.o $(P)

memcheck: all
	valgrind -v ./(P)