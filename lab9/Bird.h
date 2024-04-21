/*
 * Bird.h -
 * Implement Bird.cpp
*/

#ifndef BIRD_H //Header Guard
#define BIRD_H //Header Guard
#include <iostream> //Required library
#include <string> //Required library
using namespace std;

//Class declaration
class Bird {
public:
  Bird();                //Default constructor
  Bird(string, int);       //Species and Age
  void Display();        //Using the member variables, displays a brief description
  string GetSpecies();     //Getter for m_name
  int GetAge();          //Getter for m_age
  void SetSpecies(string); //Setter for m_name
  void SetAge(int);      //Setter for m_age
private:
  string m_species;      //Bird's species (binomial name)
  int m_age;             //Age in years
};

#endif //Header guard
