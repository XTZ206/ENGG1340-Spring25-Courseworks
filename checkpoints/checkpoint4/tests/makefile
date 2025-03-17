mathint.o: mathint.cpp mathint.hpp
		g++ -c mathint.cpp
main.o: main.cpp mathint.hpp
		g++ -c main.cpp

main: mathint.o main.o
		g++ main.o mathint.o -o main