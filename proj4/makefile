CXX = g++
CXXFLAGS = -Wall -g
IODIR = ../../proj4_IO/

proj4: Mining.o Gas.o Enemy.o Planet.o Ship.o Armor.o Engine.o Weapon.o Item.o Game.o proj4.cpp 
	$(CXX) $(CXXFLAGS) Mining.o Gas.o Enemy.o Planet.o Ship.o Armor.o Engine.o Weapon.o Item.o Game.o proj4.cpp -o proj4

Game.o: Item.o Weapon.o Engine.o Armor.o Ship.o Planet.o Enemy.o Gas.o Mining.o Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Mining.o: Planet.o Mining.h Mining.cpp
	$(CXX) $(CXXFLAGS) -c Mining.cpp

Gas.o: Planet.o Gas.h Gas.cpp
	$(CXX) $(CXXFLAGS) -c Gas.cpp

Enemy.o: Planet.o Enemy.h Enemy.cpp
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

Planet.o: Ship.o Planet.h Planet.cpp
	$(CXX) $(CXXFLAGS) -c Planet.cpp

Ship.o: Item.o Ship.h Ship.cpp
	$(CXX) $(CXXFLAGS) -c Ship.cpp

Armor.o: Item.o Armor.h Armor.cpp
	$(CXX) $(CXXFLAGS) -c Armor.cpp

Engine.o: Item.o Engine.h Engine.cpp
	$(CXX) $(CXXFLAGS) -c Engine.cpp

Weapon.o: Item.o Weapon.h Weapon.cpp
	$(CXX) $(CXXFLAGS) -c Weapon.cpp

Item.o: Item.h Item.cpp
	$(CXX) $(CXXFLAGS) -c Item.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj4 proj4_items.txt proj4_planets.txt

run1:
	./proj4 proj4_items.txt proj4_planets.txt

val1:
	valgrind ./proj4 proj4_items.txt proj4_planets.txt

submit:
	cp Game.h Game.cpp Ship.h Ship.cpp Item.h Item.cpp Armor.h Armor.cpp Engine.h Engine.cpp Weapon.h Weapon.cpp Planet.h Planet.cpp Enemy.h Enemy.cpp Gas.h Gas.cpp Mining.h Mining.cpp  ~/cs202proj/proj4

##########Grading Commands############

##Used to do regular tests
grading:
	valgrind ./proj4 $(IODIR)proj4_grading.txt

##Used if the student forgot the header files
copy_headers:
	cp $(IODIR)Ship.h $(IODIR)Item.h $(IODIR)Armor.h $(IODIR)Engine.h $(IODIR)Weapon.h $(IODIR)Planet.h $(IODIR)Enemy.h $(IODIR)Gas.h $(IODIR)Mining.h $(IODIR)Game.h .

##Used to copy the test file into the current directory
copy_test:
	cp $(IODIR)proj4_grading.txt .
