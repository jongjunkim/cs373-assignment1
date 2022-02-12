all: main


main: main.o Machine.o State.o Transition.o
	g++ main.o Machine.o State.o Transition.o -o main

main.o: main.cpp Machine.h
	g++ -c main.cpp

Machine.o: Machine.h Machine.cpp 
	g++ -c Machine.cpp 

State.o: State.h State.cpp
	g++ -c State.cpp

Transition.o: Transition.h Transition.cpp
	g++ -c Transition.cpp

clean:
	rm -f *.o main