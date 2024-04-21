/*****************************************
//Name: Planet.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Planet class
//      Serves as base class for enemy, mining, and gas subclasses.   
***********************************************/

#include "Planet.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Planet::Planet(string name, int challenge) : m_name(name), m_challenge(challenge), m_isExplored(false) {
    // Constructor implementation
}

// Destructor
Planet::~Planet() {
    // Destructor implementation
    // Since there's no dynamic memory allocation in this class,
    // there's nothing specific to deallocate here.
}




// GetName method
string Planet::GetName() {
    return m_name;
}

// SetIsExplored method
void Planet::SetIsExplored() {
    m_isExplored = true;
}

// GetIsExplored method
bool Planet::GetIsExplored() {
    return m_isExplored;
}

// GetChallenge method
int Planet::GetChallenge() {
    return m_challenge;
}

// Overloaded << operator
ostream& operator<<(ostream& os, Planet& planet) {
    os << "Planet Name: " << planet.m_name << ", Challenge: " << planet.m_challenge;
    return os;
}


// Battle method
bool Planet::Battle(Ship* ship) {
    cout << "Battle commencing!" << endl;

    // Randomly choose difficulty
    srand(time(0)); // Seed for random number generator
    int difficulty = rand() % (m_challenge + 1);

    // Get ship's attack
    int shipAttack = ship->GetTotal("Weapon");

    // Compare difficulty with ship's attack
    if (difficulty > shipAttack) {
        cout << "The planet's defense is too strong for your ship!" << endl;
        // Calculate penalty and modify ship fuel
        int fuelPenalty = (difficulty - shipAttack) * FUEL_COST_DELTA;
        ship->ModifyFuel(-fuelPenalty);
        return false;
    }
    else {
        cout << "Your planetary bombardment worked. You won!" << endl;
        // Increase ship's fuel and set planet as explored
        ship->ModifyFuel(FUEL_MULTI_WIN);
        cout << "Your fuel has been modified by 20 fuel" << endl;
        SetIsExplored();
        return true;
    }
}




