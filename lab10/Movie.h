// File: Movie.h
// Desc: This is one of the child classes for lab 10
// Date: 2/1/2022
// Author: Tyler Castle

#ifndef MOVIE_H
#define MOVIE_H
#include "Art.h"
#include <iostream>
using namespace std;
 
class Movie : public Art{
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Movie();
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Movie();
 
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
  Movie(string name);
 
  // CallMyName - Prints name
  // Preconditions: Has a name
  // Postconditions: None
  void CallMyTitle();
 
  // DescribeMe() - gives description of given movie
  // Preconditions: None
  // Postconditions: None
  void DescribeMe();
 
private:
  string m_myTitle;
 
};
 
#endif

