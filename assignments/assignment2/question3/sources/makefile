CXX = g++
CXXFLAGS = -std=c++11 -pedantic-errors

main: main.o random.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp random.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

random.o: random.cpp random.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: main
	./main

autotest: main
	echo 100000 | ./main
	echo 200000 | ./main
	echo 500000 | ./main

clean:
	rm *.o main

.PHONY: run autorun clean