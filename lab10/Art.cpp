#include "Art.h"

// Constructor
Art::Art() {
    // Initialize m_myType to an empty string
    m_myType = "";
}

// Destructor
Art::~Art() {
    // Destructor does not need to do anything specific in this case
}

// callMyType() - Prints object's type
void Art::CallMyType() {
    cout << "My type is " << m_myType << endl;
}

// getType() - returns myType
string Art::GetType() {
    return m_myType;
}

// setType() - sets value of myType
void Art::SetType(string type) {
    m_myType = type;
}
