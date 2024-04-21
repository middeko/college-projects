/*****************************************
//Name: Airport.cpp
//Project: CMSC 202 Project 3, Spring 2024
//Author:  Wilfried Dim
//Date:    3/14/2024
//Desc: This file contains the project details and implemmentation for the Airport class
//      The airports are nodes for a route.
***********************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Airport.h"

// Default Constructor
Airport::Airport() {
    m_code = "New Airport";
    m_name = "New Location";
    m_city = "";
    m_country = "";
    m_north = 0.0;
    m_west = 0.0;
    m_next = nullptr;
}

// Overloaded Constructor
Airport::Airport(string code, string name, string city, string country, double north, double west) {
    m_code = code;
    m_name = name;
    m_city = city;
    m_country = country;
    m_north = north;
    m_west = west;
    m_next = nullptr; // Assuming you want to initialize the pointer to nullptr
}

// Destructor
Airport::~Airport() {
    // Empty destructor
    // No actions needed for destruction
}

// GetCode function definition
string Airport::GetCode() {
    return m_code; // Return the three-letter code of the airport
}

// GetName function definition
string Airport::GetName() {
    return m_name; // Return the name of the airport
}

// GetNext function definition
Airport* Airport::GetNext() {
    return m_next; // Return the pointer to the next airport
}

// GetNorth function definition
double Airport::GetNorth() {
    return m_north; // Return the northern coordinates of the airport
}

// GetWest function definition
double Airport::GetWest() {
    return m_west; // Return the western coordinates of the airport
}

// GetCity function definition
string Airport::GetCity() {
    return m_city; // Return the city where the airport is located
}

// GetCountry function definition
string Airport::GetCountry() {
    return m_country; // Return the country where the airport is located
}

// SetNext function definition
void Airport::SetNext(Airport* nextAirport) {
    m_next = nextAirport; // Set the next airport
}
