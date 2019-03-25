all: a.out
	 ./a.out

a.out: Game.o Card.o Player.o main.o
	   g++ -std=c++11 Game.o Card.o Player.o main.o

main.o: main.cpp
		g++ -std=c++11 --compile main.cpp -o main.o

Card.o: Card.cpp Card.h
		g++ -std=c++11 --compile Card.cpp -o Card.o

Game.o: Game.cpp Game.h
		g++ -std=c++11 --compile Game.cpp -o Game.o

Player.o: Player.cpp Player.h
		  g++ -std=c++11 --compile Player.cpp -o Player.o

clean: 
		rm -f Game.o Card.o Player.o main.o a.out