#include "Movie.h"

// Constructor
Movie::Movie() {
    // Initialize m_myTitle to an empty string
    m_myTitle = "";
    // Set the type of the Movie object
    SetType("Movie");
}

// Destructor
Movie::~Movie() {
    // Destructor does not need to do anything specific in this case
}

// Overloaded Constructor
Movie::Movie(string name) {
    // Initialize m_myTitle with the provided name
    m_myTitle = name;
    // Set the type of the Movie object
    SetType("Movie");
}

// CallMyName - Prints name 
void Movie::CallMyTitle() {
    cout << "I am a film named '" << m_myTitle << "'" << endl;
}

// DescribeMe() - gives description of given movie
void Movie::DescribeMe() {
    cout << "I am a box office success!" << endl;
}
