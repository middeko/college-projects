//Name: Gas.h
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the header details for the gas class
//		Gas class is a subclass of Planet class. 

#ifndef _GAS_H_
#define _GAS_H_

#include "Planet.h"

// Gas are planets that can be used to harvest fuel from

class Gas: public Planet {
 public:
  // Name: Gas(string name)
  // Description: Creates a new Gas planet with name and challenge
  // Preconditions: None
  // Postconditions: Creates a new Gas planet
  Gas(string, int);
  // Name: GetType
  // Description: Returns type of planet
  // Preconditions: None
  // Postconditions: Returns the type of planet
  string GetType();
};
#endif
