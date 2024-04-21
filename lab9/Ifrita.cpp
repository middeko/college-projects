#include "Bird.h"
#include "Penguin.h"
#include "Ifrita.h" // Include the Ifrita header file

// Ifrita default constructor implementation
Ifrita::Ifrita() : Bird(), m_toxin("") {}

// Ifrita constructor implementation with parameters
Ifrita::Ifrita(string species, int age, string toxin) : Bird(species, age), m_toxin(toxin) {}

// Display function implementation to match output
void Ifrita::Display() {
    // Display the toxin of the Ifrita bird
    cout << "Don't handle that Ifrita; they have " << m_toxin << " in their feathers and skin!" << endl;
}
