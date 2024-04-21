/*****************************************
//Name: Item.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Item class
//      Serves as base class for weapon, armor, and engine subclasses.   
***********************************************/

#include "Item.h"
#include <iostream>
#include <string>
using namespace std;


// Constructor
Item::Item(string name, string type, int value) {
    // Constructor implementation
    m_name = name;
    m_type = type;
    m_value = value;
}

// Virtual Destructor
Item::~Item() {
    // Destructor implementation
    // Since there's no dynamic memory allocation in this base class,
    // there's nothing specific to deallocate here.
}

// GetType method
string Item::GetType() {
    return m_type; // Return the type of item (weapon, armor, engine)
}

// GetName method
string Item::GetName() {
    return m_name; // Return name of item
}

// GetValue method
int Item::GetValue() {
    return m_value; // Return the value of item
}

// Display method (pure virtual)
void Item::Display() {
    // This method is pure virtual and must be implemented in the derived classes.
    // There's no implementation here in the base class.
}

