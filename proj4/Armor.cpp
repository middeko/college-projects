/*****************************************
//Name: Armor.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Armor class
//       
***********************************************/

#include "Armor.h"


// Constructor
Armor::Armor(string name, string type, int value) : Item(name, type, value) {
    // Constructor implementation
}

// Display method
void Armor::Display() {
    cout << ARMOR << GetName() << "(" << GetValue() << ")" << endl;
}