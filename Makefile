CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14


all: 
	g++ $(CFLAGS) -c program1.cpp -o program1.o
	g++ $(CFLAGS) -c Vector.cpp -o Vector.o
	g++ $(CFLAGS) -c List.cpp -o List.o
	g++ $(CFLAGS) -c Star.cpp -o Star.o
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o
	g++ program1.o Vector.o List.o Star.o Planet.o -o program1

run: all
	./program1

clean: all
	rm -rf program1 *.o
