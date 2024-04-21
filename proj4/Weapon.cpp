/*****************************************
//Name: Weapon.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Weapon class
//       
***********************************************/

#include "Weapon.h"


// Constructor
Weapon::Weapon(string name, string type, int value) : Item(name, type, value) {
    // Constructor implementation
}

// Display method
void Weapon::Display() {
    cout << WEAPON << GetName() << "(" << GetValue() << ")" << endl;
}
