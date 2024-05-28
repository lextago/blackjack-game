blackjack: main.o player.o dealer.o
	g++ main.o player.o dealer.o -o blackjack

tests: tests.o player.o dealer.o
	g++ tests.o player.o dealer.o -o tests

main.o: main.cpp
	g++ -c -g main.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

dealer.o: dealer.cpp dealer.h
	g++ -c dealer.cpp

tests.o: tests.cpp
	g++ -c -g tests.cpp

run:
	./blackjack 6

run_tests:
	./tests 1

valgrind:
	valgrind ./blackjack 6

valgrind_tests:
	valgrind ./tests 1

clean:
	rm *.o blackjack tests
