//Name: Enemy.h
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the header details for the Enemy class
//		Enemy class is a subclass of Planet class. 

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Planet.h"

// Enemy are planets that can be used to harvest fuel from

//***Constants***
const int ENEMY_SPECIAL = 2; //Base addition for Enemy

class Enemy: public Planet {
 public:
  // Name: Enemy(string name, int challenge)
  // Description: Creates a new Enemy planet
  // Preconditions: None
  // Postconditions: Creates a new Enemy planet
  Enemy(string, int);
  // Name: GetType
  // Description: Returns type of planet
  // Preconditions: None
  // Postconditions: Returns the type of planet
  string GetType();
};
#endif
