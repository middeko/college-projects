#include "Bird.h" // Include the Bird header file

// Songbird class declaration, inheriting from Bird class
class Songbird : public Bird {
public:
    Songbird(); // Default constructor
    Songbird(string species, int age, string song); // Constructor with species, age, and song parameters
    void Display(); // Override the Display function to include song information
    string GetSong(); // Getter for the song
    void SetSong(string song); // Setter for the song
private:
    string m_song; // Song of the songbird
};

// Default constructor implementation
Bird::Bird() : m_species(""), m_age(0) {}

// Constructor with parameters implementation
Bird::Bird(string species, int age) : m_species(species), m_age(age) {}

// Display function implementation
void Bird::Display() {
    // Display the bird information
    cout << "Before you is a(n) " << m_age << "-year-old " << m_species << "." << endl;
}

// Getter for species implementation
string Bird::GetSpecies() {
    return m_species;
}

// Getter for age implementation
int Bird::GetAge() {
    return m_age;
}

// Setter for species implementation
void Bird::SetSpecies(string species) {
    m_species = species;
}

// Setter for age implementation
void Bird::SetAge(int age) {
    m_age = age;
}

// Songbird default constructor implementation
Songbird::Songbird() : Bird(), m_song("") {}

// Songbird constructor implementation with parameters
Songbird::Songbird(string species, int age, string song) : Bird(species, age), m_song(song) {}


// Override the Display function to include song information
void Songbird::Display() {
    // Call the base class Display function to show species and age
    Bird::Display();
    // Display the song of the songbird
    cout << "Song: " << m_song << endl;
}

// Getter for the song
string Songbird::GetSong() {
    return m_song;
}

// Setter for the song
void Songbird::SetSong(string song) {
    m_song = song;
}
