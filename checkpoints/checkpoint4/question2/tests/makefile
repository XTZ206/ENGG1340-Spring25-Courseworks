gcd.o: gcd.cpp gcd.h
	g++ -c gcd.cpp
lcm.o: lcm.cpp lcm.h
	g++ -c lcm.cpp
calc.o: calc.cpp gcd.h lcm.h
	g++ -c calc.cpp
calc: calc.o gcd.o lcm.o
	g++ calc.o gcd.o lcm.o -o calc

clean:
	rm *.o calc
.PHONY: clean