//Name: Weapon.h
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the header details for the Weapon class
//		Weapon class is a subclass of Item class. 

#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"

//Constants
const string WEAPON = "**WEAPON** ";

// The Weapon is a type of item used by your ship. It affects attack.

class Weapon: public Item {
 public:
  // Name: Weapon(string name, string type, int value)
  // Description: Creates a new Weapon item
  // Preconditions: None
  // Postconditions: Can create a Weapon
  Weapon(string, string, int);
  // Name: Display
  // Description: Displays WEAPON, name, and value of weapon
  // Preconditions: None
  // Postconditions: Displays information about the weapon
  void Display();
};
#endif
