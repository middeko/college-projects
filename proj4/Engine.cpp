/*****************************************
//Name: Engine.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implemmentation for the Engine class
//       
***********************************************/

#include "Engine.h"


// Constructor
Engine::Engine(string name, string type, int value) : Item(name, type, value) {
    // Constructor implementation
}

// Display method
void Engine::Display() {
    cout << ENGINE << GetName() << "(" << GetValue() << ")" << endl;
}
