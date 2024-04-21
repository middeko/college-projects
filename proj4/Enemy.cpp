/*****************************************
//Name: Enemy.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Enemy class
//       
***********************************************/

#include "Enemy.h"

// Constructor
Enemy::Enemy(string name, int challenge) : Planet(name, challenge + ENEMY_SPECIAL) {
    // Constructor implementation
}

// GetType method
string Enemy::GetType() {
    return "Enemy";
}

