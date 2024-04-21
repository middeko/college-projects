// lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Include all required classes
#include "Bird.h" //Parent class
#include "Penguin.h" //Child class
#include "Ifrita.h" //Child class
#include <time.h> //Used to seed srand
#include <cstdlib> //Has rand and srand
#include <iostream> //For output
#include <string> //For strings
using namespace std;

int main() {
	srand(time(NULL)); //Seeds random number generator

	Bird myBird("American Crow (corvus brachyrhynchos)", 3);
	myBird.Display();//Uses the parent class function Display

	Penguin myPenguin("Emperor Penguin (aptenodytes forsteri)", 8);
	myPenguin.Display(); //Uses the parent class function Display
	myPenguin.Dive(); //Extends the parent class with Penguin specific function

	Ifrita myIfrita("Blue-capped Ifrit (ifrita kowaldi)", 1, "batrachotoxin");
	myIfrita.Bird::Display(); //Uses parent class function Display
	myIfrita.Display(); //Replaces the parent class function Display

	return 0;
}
