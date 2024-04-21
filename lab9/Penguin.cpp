#include "Bird.h"
#include "Penguin.h" // Include the Penguin header file

#include <iostream>

// Penguin default constructor implementation
Penguin::Penguin() : Bird(), m_diveDepth(0) {}

// Penguin constructor implementation with parameters
Penguin::Penguin(string species, int age) : Bird(species, age), m_diveDepth(0) {}

// Getter for the dive depth
int Penguin::GetDiveDepth() {
    return m_diveDepth;
}

// Setter for the dive depth
void Penguin::SetDiveDepth(int) {
    // Generate a random depth between 0 and MAX_DIVE
    m_diveDepth = rand() % (MAX_DIVE + 1);
}


// Dive function implementation
void Penguin::Dive() {
    // Check if the dive depth exceeds the maximum dive depth
    if (m_diveDepth > MAX_DIVE) {
        cout << "Dive depth exceeds maximum dive depth!" << endl;
    }
    else {
        cout << "The Penguin dives " << m_diveDepth << " meters!" << endl;
    }
}

