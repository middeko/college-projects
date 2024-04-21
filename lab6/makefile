CXX = g++
CXXFLAGS = -Wall

lab6: lab6.cpp Grocery.o
	$(CXX) $(CXXFLAGS) lab6.cpp Grocery.o -o lab6

Grocery.o: Grocery.cpp Grocery.h
	$(CXX) $(CXXFLAGS) -c Grocery.cpp

run:
	./lab6

clean:
	rm *~
