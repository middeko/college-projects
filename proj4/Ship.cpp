/*****************************************
//Name: Ship.cpp
//Project: CMSC 202 Project 4, Spring 2024
//Author:  Wilfried Dim
//Date:    4/10/2024
//Desc: This file contains the project details and implementation for the Ship class
//       
***********************************************/

#include "Ship.h"
#include <iomanip>

// Constructor
Ship::Ship(string name) : m_name(name), m_fuel(STARTING_FUEL) {
    // Constructor implementation
}


// GetName method
string Ship::GetName() {
    return m_name;
}

// GetFuel method
int Ship::GetFuel() {
    return m_fuel;
}

// GetItemCount method
int Ship::GetItemCount() {
    return m_shipItems.size();
}

// GetTotal method
int Ship::GetTotal(string type) {
    // Convert the provided type to lowercase for case-insensitive comparison
    for (char& c : type) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';  // Convert uppercase to lowercase
        }
    }

    int total = 0;
    // Iterate through the ship items
    for (Item* item : m_shipItems) {
        // Convert item type to lowercase for case-insensitive comparison
        string itemType = item->GetType();
        for (char& c : itemType) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';  // Convert uppercase to lowercase
            }
        }
        // Check if the item type matches the provided type
        if (itemType == type) {
            total += item->GetValue();
        }
    }
    return total;
}

// AddItem method (trickier function uses item class directly)
void Ship::AddItem(Item* newItem) {
    if (m_shipItems.size() < MAX_ITEMS) {
        m_shipItems.push_back(newItem);
    }
    else {
        ReplaceItem(newItem);
    }
}

// ReplaceItem method (trickier function uses item class directly)
void Ship::ReplaceItem(Item* newItem) {
    cout << "Which item would you like to replace?" << endl;
    DisplayItems(); // Display current items
    int choice;
    cin >> choice;

    // Validate user input
    while (choice < 1 || choice > m_shipItems.size()) {
        cout << "Invalid choice. Please enter a number between 1 and " << m_shipItems.size() << ": ";
        cin >> choice;
    }

    // Replace the item at the chosen index
    m_shipItems[choice - 1] = newItem;
}


// ModifyFuel method
void Ship::ModifyFuel(int amount) {
    m_fuel += amount;
    // Ensure fuel never goes below 0
    if (m_fuel < 0) {
        m_fuel = 0;
    }
}

// DisplayItems method
void Ship::DisplayItems() {
    // Display the items on the ship
    for (size_t i = 0; i < m_shipItems.size(); ++i) {
        string itemType;
        string itemTypeLowerCase = m_shipItems[i]->GetType(); // Get the type of the item in lowercase
        // Convert the item type to lowercase
        for (size_t j = 0; j < itemTypeLowerCase.size(); ++j) {
            if (itemTypeLowerCase[j] >= 'A' && itemTypeLowerCase[j] <= 'Z') {
                itemTypeLowerCase[j] += 'a' - 'A';
            }
        }

        if (itemTypeLowerCase == "engine") {
            itemType = "->ENGINE-> ";
        }
        else if (itemTypeLowerCase == "armor") {
            itemType = "|ARMOR| ";
        }
        else if (itemTypeLowerCase == "weapon") {
            itemType = "**WEAPON** ";
        }
        cout << i + 1 << ". ";
        if (!itemType.empty()) {
            cout << itemType;
        }
        cout << m_shipItems[i]->GetName() << "(" << m_shipItems[i]->GetValue() << ")" << endl;
    }
}





// DisplayShip method
void Ship::DisplayShip() {
    // Prints Ship Stats
    cout << "**************************" << endl;
    cout << "Name: " << m_name << endl;
    cout << "Fuel: " << m_fuel << endl;
    cout << "Attack: " << GetTotal("weapon") << endl;
    cout << "Defense: " << GetTotal("armor") << endl;
    cout << "Engine: " << GetTotal("engine") << endl;
    cout << "**************************" << endl;

    for (size_t i = 0; i < m_shipItems.size(); ++i) {
        string itemType;
        string type = m_shipItems[i]->GetType();

        // Convert item type to lowercase for case-insensitive comparison
        for (char& c : type) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';  // Convert uppercase to lowercase
            }
        }
        
        // Add proper label depending on item type
        if (type == "engine") {
            itemType = "->ENGINE-> ";
        }
        else if (type == "armor") {
            itemType = "|ARMOR| ";
        }
        else if (type == "weapon") {
            itemType = "**WEAPON** ";
        }
        cout << i + 1 << ". " << itemType << m_shipItems[i]->GetName() << "(" << m_shipItems[i]->GetValue() << ")" << endl;
    }
}


