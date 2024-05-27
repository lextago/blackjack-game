build: main.cpp game.cpp
	g++ -g main.cpp game.cpp -o main.o

run:
	./main.o 6

valgrind:
	valgrind ./main.o 6

clean:
	rm -f main.o