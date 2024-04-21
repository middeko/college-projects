/*
 * Penguin.h -
 * Implement Penguin.cpp
*/
#ifndef PENGUIN_H //Header guard
#define PENGUIN_H //Header guard

//Required libraries and files
#include "Bird.h"
#include <iostream>
#include <string>
using namespace std;

//Constants
const int MAX_DIVE = 565;

//Class declaration
class Penguin : public Bird {
public:
  Penguin();               //Default constructor
  Penguin(string, int);      //Name, Age
  int GetDiveDepth();      //Getter for m_diveDepth
  void SetDiveDepth(int);    //Setter for m_diveDepth
  void Dive();             //The penguin dives underwater
private:
  int m_diveDepth;  //depth of dive in meters
};

#endif //Header guard
