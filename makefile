build:
	rm -f main.o
	g++ -g main.cpp game.cpp -o main.o

run:
	./main.o 6

valgrind:
	valgrind ./main.o 6