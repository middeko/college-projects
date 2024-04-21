/*****************************************
//Name: Game.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Game class
// 
***********************************************/

//Includes of required classes
#include "Ship.h"
#include "Planet.h"
#include "Enemy.h"
#include "Gas.h"
#include "Mining.h"
#include "Item.h"
#include "Armor.h"
#include "Engine.h"
#include "Weapon.h"
#include "Game.h"

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Constructor
Game::Game(string itemFile, string planetFile) : m_winEngine(0), m_ship(nullptr), m_curPlanet(nullptr), m_fileItems(itemFile), m_filePlanets(planetFile) {
    // Constructor implementation
}



// Destructor
Game::~Game() {
    // Deallocate dynamically allocated ship
    delete m_ship;

    // Set ship pointer to nullptr to avoid dangling pointer
    m_ship = nullptr;

    // Deallocate dynamically allocated items added to the ship
    for (Item* item : m_items) {
        delete item;
    }

    // Clear the items vector
    m_items.clear();

    // Deallocate dynamically allocated planets
    for (Planet* planet : m_planets) {
        delete planet;
    }

    // Clear the planets vector
    m_planets.clear();
}


// Load items from data file
void Game::LoadItems() {
    ifstream inputStream(m_fileItems);
    if (!inputStream.is_open()) {
        cerr << "Error: Unable to open item file: " << m_fileItems << endl;
        return;
    }

    string fileLine;
    while (getline(inputStream, fileLine)) {
        // Initialize variables for each item
        string itemName = "", itemType = "";
        int itemValue = 0;
        size_t numOfDelimiters = 0; // Change the type to size_t to match fileLine.size()
        bool skipItem = false; // Flag to indicate whether to skip the current item

        // Iterate through each character in the line until all delimiters are met
        for (size_t i = 0; i < fileLine.size(); ++i) { // Change the type to size_t
            char firstChar = fileLine[i];
            switch (numOfDelimiters) {
            case 0:
                if (firstChar != DELIMITER) {
                    itemName += firstChar;
                }
                else {
                    numOfDelimiters++;
                }
                break;
            case 1:
                if (firstChar != DELIMITER) {
                    itemType += firstChar;
                }
                else {
                    numOfDelimiters++;
                }
                break;
            case 2:
                if (firstChar != DELIMITER && isdigit(firstChar)) { // Check if it's a digit
                    itemValue = itemValue * 10 + (firstChar - '0');
                }
                else {
                    numOfDelimiters++;
                }
                break;
            }
        }

        // If the item is Basic armor, Basic weapon, or Basic engine, add 1 to the value
        if (itemName == "Basic armor" || itemName == "Basic weapon" || itemName == "Basic engine") {
            itemValue++;
        }

        // Dynamically allocate the item based on its type
        Item* newItem = nullptr;
        if (itemType == "armor") {
            newItem = new Armor(itemName, itemType, itemValue);
        }
        else if (itemType == "engine") {
            newItem = new Engine(itemName, itemType, itemValue);
        }
        else if (itemType == "weapon") {
            newItem = new Weapon(itemName, itemType, itemValue);
        }
        else {
            cerr << "Error: Unknown item type encountered: " << itemType << endl;
            skipItem = true; // Set the flag to skip this item
        }

        // Add the item to the m_items vector if not flagged to be skipped
        if (!skipItem) {
            m_items.push_back(newItem);
        }
    }

    inputStream.close();
}



// Load planets from data file
void Game::LoadPlanets() {
    const int CHALLENGE_ADJUST = 2; // Define the constant for challenge adjustment

    ifstream inputStream(m_filePlanets);
    if (!inputStream.is_open()) {
        cerr << "Error: Unable to open planet file: " << m_filePlanets << endl;
        return;
    }

    string fileLine;
    while (getline(inputStream, fileLine)) {
        // Initialize variables for each planet
        string planetName = "", planetType = "";
        int planetChallenge = 0; // Removed unused variable planetId
        size_t numOfDelimiters = 0; // Change the type to size_t to match fileLine.size()
        bool skipPlanet = false; // Flag to indicate whether to skip the current planet

        // Iterate through each character in the line until all delimiters are met
        for (size_t i = 0; i < fileLine.size(); ++i) { // Change the type to size_t
            char firstChar = fileLine[i];
            switch (numOfDelimiters) {
            case 0:
                if (firstChar != DELIMITER) {
                    planetName += firstChar;
                }
                else {
                    numOfDelimiters++;
                }
                break;
            case 1:
                if (firstChar != DELIMITER) {
                    planetType += firstChar;
                }
                else {
                    numOfDelimiters++;
                }
                break;
            case 2:
                if (firstChar != DELIMITER) {
                    planetChallenge = planetChallenge * 10 + (firstChar - '0');
                }
                else {
                    numOfDelimiters++;
                }
                break;
            }
        }

        // Adjust the challenge value based on planet type
        if (planetType == "enemy" || planetType == "mining") {
            planetChallenge -= CHALLENGE_ADJUST; // Subtract CHALLENGE_ADJUST from the challenge value
        }

        // Dynamically allocate the planet based on its type and add it to the m_planets vector
        Planet* newPlanet = nullptr;
        if (planetType == "gas") {
            newPlanet = new Gas(planetName, planetChallenge);
        }
        else if (planetType == "mining") {
            newPlanet = new Mining(planetName, planetChallenge);
        }
        else if (planetType == "enemy") {
            newPlanet = new Enemy(planetName, planetChallenge);
        }
        else {
            cerr << "Error: Unknown planet type: " << planetType << endl;
            skipPlanet = true; // Set the flag to skip this planet
        }

        // Add the planet to the m_planets vector if not flagged to be skipped
        if (!skipPlanet) {
            m_planets.push_back(newPlanet);
        }
    }

    inputStream.close();
}






// Create ship object with proper items
void Game::ShipCreation() {
    string shipName;
    cout << "Ship Name: ";
    getline(cin, shipName);

    // Create a new ship object with the provided name
    m_ship = new Ship(shipName);

    // Add default items to the ship
    m_ship->AddItem(m_items[START_ENGINE]);
    m_ship->AddItem(m_items[START_ARMOR]);
    m_ship->AddItem(m_items[START_WEAPON]);
}

// Loads Game
void Game::StartGame() {
    // Welcome message
    cout << "Welcome to Super Space Exploration!" << endl;

    // Load planets and items
    LoadPlanets();
    LoadItems();

    // Count the number of loaded planets
    int numPlanetsLoaded = m_planets.size();
    int numItemsLoaded = m_items.size();

    cout << numPlanetsLoaded << " planets loaded." << endl;
    cout << numItemsLoaded << " items loaded." << endl;

    // Create ship
    ShipCreation();

    // Set current planet to the first planet in the vector
    m_curPlanet = m_planets[START_PLANET];

    // Print details of the first planet
    cout << m_curPlanet->GetName() << "(" << m_curPlanet->GetType() << ") Challenge: " << m_curPlanet->GetChallenge() << endl;

    // Randomize win engine value
    srand(time(nullptr)); // Seed for random number generator
    m_winEngine = rand() % (UTOPIA_MAX - UTOPIA_MIN + 1) + UTOPIA_MIN;

    // Call Action (main menu)
    Action();
}

// Main Menu
void Game::Action() {
    // Check if the ship has run out of fuel
    if (m_ship->GetFuel() <= 0) {
        cout << "You have run out of fuel. Game over!" << endl;
        cout << "Goodbye!" << endl;
        return; // Exit the game
    }

    // Display menu options
    cout << endl << "What would you like to do?" << endl;
    cout << "1. Examine Items" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Planet" << endl;
    cout << "4. Travel to Utopia" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;

    // Get player's choice
    int choice;
    cin >> choice;

    // Process player's choice
    switch (choice) {
    case 1:
        DisplayShipItems();
        break;
    case 2:
        Move();
        break;
    case 3:
        AttackPlanet();
        break;
    case 4: {
        int result = TravelUtopia();
        if (result == -1) {
            cout << "Oh no! Your engines were not developed enugh to make it to Utopia!" << endl;
            cout << "Goodbye!" << endl;
            return;
        }
        else if (result == 0) {
            cout << "You are not prepared to try to travel to Utopia yet." << endl;
            cout << "Perhaps develop your engines more?!" << endl;
        }
        else {
            cout << "Congratulations! You have successfully traveled to Utopia and won the game!" << endl;
            cout << "Goodbye!" << endl;
            return; // Exit the game
        }
        break;
    }
    case 5:
        Stats();
        break;
    case 6:
        cout << "Goodbye!" << endl;
        return; // Exit the game
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }

    // Recursively call Action until the player quits or dies
    Action();
}

// Move ship to new planet
void Game::Move() {
    // Check if there are any planets to move to
    if (m_planets.empty()) {
        cout << "There are no planets to move to!" << endl;
        return;
    }

    // Get a random index for the new planet
    srand(time(nullptr));
    int newIndex = rand() % m_planets.size();

    // Calculate fuel cost for the move
    int fuelCost = MOVE_FUEL;

    // Check if the ship has enough fuel to make the move
    if (m_ship->GetFuel() < abs(fuelCost)) {
        cout << "You don't have enough fuel to make the move!" << endl;
        return;
    }

    // Deduct fuel cost for the move
    m_ship->ModifyFuel(fuelCost);

    // Update current planet to the new planet
    m_curPlanet = m_planets[newIndex];


    // Display information about the new planet
    cout << "You travel to the next planet." << endl;
    cout << m_curPlanet->GetName() << "(" << m_curPlanet->GetType() << ") Challenge: " << m_curPlanet->GetChallenge() << endl;

    // Display the fuel modification
    cout << "Your fuel has been modified by " << fuelCost << " fuel." << endl;
}




// Simulate combat between ship and planet
void Game::AttackPlanet() {
    // Check if the ship is orbiting a planet
    if (!m_curPlanet) {
        cout << "You are not orbiting any planet to attack!" << endl;
        return;
    }

    // Check if the planet has already been defeated
    if (m_curPlanet->GetIsExplored()) {
        cout << "This planet has already been defeated." << endl;
        cout << "You should move to a new planet." << endl;
        return;
    }

    // Perform battle with the current planet
    bool win = m_curPlanet->Battle(m_ship);

    // Display battle result
    if (win) {
        // Identify an item and add it to the ship
        IdentifyItem(m_curPlanet->GetChallenge());
    }
    else {
        cout << "You were defeated by " << m_curPlanet->GetName() << "." << endl;
    }
}

// Find random item of planet challenge value
void Game::IdentifyItem(int challenge) {
    // Create a vector to store items with a value equal to the challenge
    vector<Item*> matchingItems;

    // Find items with value equal to the challenge
    for (size_t i = 0; i < m_items.size(); ++i) {
        Item* item = m_items[i];
        if (item->GetValue() == challenge) {
            matchingItems.push_back(item);
        }
    }

    // Check if there are any matching items
    if (matchingItems.empty()) {
        cout << "No item found with a value equal to the challenge." << endl;
        return;
    }

    // Generate a random index for the matching items vector
    int index = rand() % matchingItems.size();

    // Get the random item
    Item* newItem = matchingItems[index];

    // Output the identified item with type information (before adding to m_ship)
    cout << "New item found: " << newItem->GetName() << "(" << newItem->GetType() << ") " << newItem->GetValue() << endl;

    // Add the item to the ship
    m_ship->AddItem(newItem);
}



// Display Ship's stats
void Game::Stats() {
    

    m_ship->DisplayShip(); // Call the ship's DisplayShip method
}

// Attempt to travel to Utopia
int Game::TravelUtopia() {
    // Get the total engine value
    int totalEngineValue = m_ship->GetTotal("engine");  

    // Check if total engine value is below UTOPIA_MIN
    if (totalEngineValue < UTOPIA_MIN) {
        return 0; // Return 0 indicating continue
    }

    // Check if total engine value is above m_winEngine
    if (totalEngineValue > m_winEngine) {
        return 1; // Return 1 indicating win
    }

    // Otherwise, return -1 indicating lose
    return -1;
}


// Displays ship items
void Game::DisplayShipItems() {
    // Constants for item types
    const string WEAPON = "**WEAPON** ";
    const string ARMOR = "|ARMOR| ";
    const string ENGINE = "->ENGINE-> ";

    // Check if m_ship is not initialized
    if (!m_ship) {
        cout << "No ship found." << endl;
        return;
    }

    // Display ship's items
    m_ship->DisplayItems();
}










