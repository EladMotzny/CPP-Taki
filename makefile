#Elad Motzny 204093694
#Alex Fishman 319451514

all: a.out
	 ./a.out

a.out: Game.o Card.o Player.o main.o
	   g++ -std=c++0x Game.o Card.o Player.o main.o

main.o: main.cpp
		g++ -std=c++0x --compile main.cpp -o main.o

Card.o: Card.cpp Card.h
		g++ -std=c++0x --compile Card.cpp -o Card.o

Game.o: Game.cpp Game.h
		g++ -std=c++0x --compile Game.cpp -o Game.o

Player.o: Player.cpp Player.h
		  g++ -std=c++0x --compile Player.cpp -o Player.o

clean: 
		rm -f Game.o Card.o Player.o main.o a.out