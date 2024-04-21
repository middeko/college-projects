#include "Painting.h"

// Constructor
Painting::Painting() {
    // Initialize m_myTitle to an empty string
    m_myTitle = "";
    // Set the type of the Painting object
    SetType("Painting");
}



// Destructor
Painting::~Painting() {
    // Destructor does not need to do anything specific in this case
}

// Overloaded Constructor
Painting::Painting(string title) {
    // Initialize m_myTitle with the provided title
    m_myTitle = title;
    // Set the type of the Painting object
    SetType("Painting");
}


// callMyName - Prints name
void Painting::CallMyTitle() {
    cout << "I am a beautiful painting named " << m_myTitle << endl;
}

// describeMe() - gives description of given painting
void Painting::DescribeMe() {
    cout << "I am made of oil on canvas and look like I belong in a museum." << endl;
}
