CXX = g++
CXXFLAGS = -Wall

lab7: SteamTeam.o lab7.cpp
	$(CXX) $(CXXFLAGS) SteamTeam.o lab7.cpp -o lab7

SteamTeam.o: SteamTeam.cpp SteamTeam.h
	$(CXX) $(CXXFLAGS) -c SteamTeam.cpp

run:
	./lab7

clean:
	rm *~
