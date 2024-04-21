/*****************************************
//Name: Route.cpp
//Project: CMSC 202 Project 3, Spring 2024
//Author:  Wilfried Dim
//Date:    3/14/2024
//Desc: This file contains the project details and implementation for the Route class
//      The airports are nodes for a route
***********************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Route.h"

// Default Constructor
Route::Route() {
    m_name = "Test"; // Initialize the name of the Route to an empty string
    m_head = nullptr; // Set the head pointer to nullptr
    m_tail = nullptr; // Set the tail pointer to nullptr
    m_size = 0; // Initialize the size of the Route to 0
}

// Destructor
Route::~Route() {
    // Delete all dynamically allocated airports in the route
    while (m_head != nullptr) {
        Airport* temp = m_head;
        m_head = m_head->GetNext(); // Move head pointer to the next airport
        delete temp; // Delete the current airport
    }
    // Set pointers and size to initial state
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

// InsertEnd function definition
void Route::InsertEnd(string code, string name, string city, string country, double north, double west) {
    // Create a new airport with the provided data
    Airport* newAirport = new Airport(code, name, city, country, north, west);

    // If the route is empty, set both head and tail to the new airport
    if (m_head == nullptr) {
        m_head = newAirport;
        m_tail = newAirport;
    }
    else {
        // Otherwise, insert the new airport at the end of the route
        m_tail->SetNext(newAirport); // Link the current tail to the new airport
        m_tail = newAirport; // Update the tail to the new airport
    }

    // Increment the size of the route
    m_size++;
}

// SetName function definition
void Route::SetName(string name) {
    m_name = name; // Set the name of the route
}

// UpdateName function definition
string Route::UpdateName() {
    // Check if the route has at least two airports
    if (m_size < 2) {
        // If there are less than two airports, return an empty string
        return "";
    }

    // Get the names of the first and last airports in the route
    string firstName = m_head->GetCity();
    string lastName = m_tail->GetCity();

    // Construct the new name of the route based on the first and last airport names
    string updatedName = firstName + " to " + lastName;

    // Update the name of the route
    m_name = updatedName;

    // Return the updated name
    return updatedName;
}

// GetSize function definition
int Route::GetSize() {
    return m_size; // Return the size of the route
}

// GetName function definition
string Route::GetName() {
    return m_name; // Return the name of the route
}


// GetData function definition
Airport* Route::GetData(int index) {
    // Check if the index is valid
    if (index < 0 || index >= m_size) {
        return nullptr; // Return nullptr if the index is out of bounds
    }

    // Traverse the linked list to the specified index
    Airport* temp = m_head;
    for (int i = 0; i < index; ++i) {
        temp = temp->GetNext();
    }

    // Return the airport at the specified index
    return temp;
}

// DisplayRoute function definition
void Route::DisplayRoute() {
    // Check if the route is empty
    if (m_head == nullptr) {
        std::cout << "No routes to display" << std::endl;
        return;
    }

    // Traverse the linked list and display each airport
    Airport* current = m_head;
    int index = 1;
    while (current != nullptr) {
        std::cout << index << ". " << current->GetCode() << ", " << current->GetName() << ", "
            << current->GetCity() << ", " << current->GetCountry() << " (N" << current->GetNorth()
            << " W" << current->GetWest() << ")" << std::endl;
        current = current->GetNext(); // Move to the next airport
        index++;
    }
}

// RemoveAirport function definition
void Route::RemoveAirport(int index) {
    // Check if the index is within valid bounds
    if (index < 0 || index >= m_size || m_size <= 2) {
        std::cout << "Route cannot have less than two airports." << std::endl;
        return;
    }

    // If removing the first airport
    if (index == 0) {
        Airport* temp = m_head;
        m_head = m_head->GetNext();
        delete temp;
    }
    // If removing the last airport
    else if (index == m_size - 1) {
        Airport* current = m_head;
        while (current->GetNext() != m_tail) {
            current = current->GetNext();
        }
        delete m_tail;
        m_tail = current;
        m_tail->SetNext(nullptr);
    }
    // If removing a middle airport
    else {
        Airport* current = m_head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->GetNext();
        }
        Airport* temp = current->GetNext();
        current->SetNext(temp->GetNext());
        delete temp;
    }

    // Decrement the size of the route
    m_size--;
}

// ReverseRoute function definition
void Route::ReverseRoute() {
    if (m_size < 2) {
        // If the route has less than two airports, no need to reverse
        return;
    }

    // Initialize pointers
    Airport* prev = nullptr;
    Airport* current = m_head;
    Airport* next = nullptr;

    // Traverse the linked list and reverse pointers
    while (current != nullptr) {
        next = current->GetNext(); // Save the next pointer
        current->SetNext(prev);    // Reverse the pointer
        prev = current;            // Move prev to current
        current = next;            // Move current to next
    }

    // Swap head and tail pointers
    m_tail = m_head;
    m_head = prev;
}

