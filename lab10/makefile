CXX = g++
CXXFLAGS = -Wall

lab10: Art.o Painting.o Movie.o lab10.cpp
	$(CXX) $(CXXFLAGS) Art.o Painting.o Movie.o lab10.cpp -o lab10

Movie.o: Movie.h Movie.cpp Art.o
	$(CXX) $(CXXFLAGS) -c Movie.cpp

Painting.o: Painting.h Painting.cpp Art.o
	$(CXX) $(CXXFLAGS) -c Painting.cpp

Art.o: Art.h Art.cpp
	$(CXX) $(CXXFLAGS) -c Art.cpp

run:
	./lab10
clean:
	rm *~
	rm *.o
