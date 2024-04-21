CXX = g++
CXXFLAGS = -Wall

lab9: Bird.o Penguin.o Ifrita.o lab9.cpp
	$(CXX) $(CXXFLAGS) Bird.o Penguin.o Ifrita.o lab9.cpp -o lab9

Penguin.o: Penguin.h Penguin.cpp Bird.o
	$(CXX) $(CXXFLAGS) -c Penguin.cpp

Ifrita.o: Ifrita.h Ifrita.cpp Bird.o
	$(CXX) $(CXXFLAGS) -c Ifrita.cpp

Bird.o: Bird.h Bird.cpp
	$(CXX) $(CXXFLAGS) -c Bird.cpp

run:
	./lab9
clean:
	rm *~
	rm *.o
