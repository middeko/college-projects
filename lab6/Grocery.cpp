#include "Grocery.h"

// Default constructor
Grocery::Grocery() {
    // Initialize member variables to default values
    m_name = "";
    m_type = 0;
}

// Overloaded constructor
Grocery::Grocery(string name, int type) {
    // Initialize member variables with provided values
    m_name = name;
    m_type = type;
}

// GetName() returns the grocery item's name
string Grocery::GetName() {
    return m_name;
}

// GetType() returns the type of the grocery item
int Grocery::GetType() {
    return m_type;
}

// SetName() sets m_name to name
void Grocery::SetName(string name) {
    m_name = name;
}

// SetType() sets m_type to type
void Grocery::SetType(int type) {
    m_type = type;
}
