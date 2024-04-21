/*****************************************
//Name: Gas.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Gas class
//       
***********************************************/

#include "Gas.h"

// Constructor
Gas::Gas(string name, int challenge) : Planet(name, challenge) {
    // Constructor implementation
}

// GetType method
string Gas::GetType() {
    return "Gas";
}
