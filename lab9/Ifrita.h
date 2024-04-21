/*
 * Ifrita.h -
 * Implement Ifrita.cpp
*/
#ifndef IFRITA_H //Header Guard
#define IFRITA_H //Header Guard
#include "Bird.h"
#include <iostream> //Required library
#include <string> //Required library
using namespace std;

//Class declaration
class Ifrita : public Bird {
public:
  Ifrita();                    //Default constructor
  Ifrita(string, int, string); //Name and Age
  void Display();              //Using m_toxin, display the Ifrita to match output
private:
  string m_toxin;
};

#endif //Header Guard
