###
### @author - Adil Chaudhry <chaudhra@oregonstate.edu>
### @description - Makefile for Project2  
###

CFLAGS = -std=c++11

Project1: main.o Animal.o Zoo.o Tiger.o Penguin.o Turtle.o inputValidation.o 
	g++ $(CFLAGS) main.o Animal.o Zoo.o Tiger.o Penguin.o Turtle.o inputValidation.o -o Project2

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

	
Animal.o: Animal.cpp Animal.h
	g++ $(CFLAGS) -c Animal.cpp
	
Zoo.o: Zoo.cpp Zoo.h
	g++ $(CFLAGS) -c Zoo.cpp
	
Tiger.o: Tiger.cpp Tiger.h
	g++ $(CFLAGS) -c Tiger.cpp
	
Penguin.o: Penguin.cpp Penguin.h
	g++ $(CFLAGS) -c Penguin.cpp
	
Turtle.o: Turtle.cpp Turtle.h
	g++ $(CFLAGS) -c Turtle.cpp

inputValidation.o: inputValidation.cpp inputValidation.h
	g++ $(CFLAGS) -c inputValidation.cpp
	
clean:
	rm *.o Project2