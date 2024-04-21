// File: Painting.h
// Desc: This is one of the child classes for lab 10
// Date: 2/1/2022
// Author: Tyler Castle

#ifndef PAINTING_H
#define PAINTING_H
#include "Art.h"
#include <iostream>
using namespace std;
 
class Painting : public Art{
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Painting();
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Painting();
 
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
  Painting(string title);
 
  // callMyName - Prints name
  // Preconditions: Has a name
  // Postconditions: None
  void CallMyTitle();
 
  // describeMe() - gives description of given painting
  // Preconditions: None
  // Postconditions: None
  void DescribeMe();
 
private:
  string m_myTitle;
};
 
#endif
