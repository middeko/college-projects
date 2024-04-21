/*****************************************
//Name: Mining.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Mining class
//       
***********************************************/

#include "Mining.h"

// Constructor
Mining::Mining(string name, int challenge) : Planet(name, challenge + MINING_SPECIAL) {
    // Constructor implementation
}

// GetType method
string Mining::GetType() {
    return "Mining";
}
