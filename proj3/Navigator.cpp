/*****************************************
//Name: Navigator.cpp
//Project: CMSC 202 Project 3, Spring 2024
//Author:  Wilfried Dim
//Date:    3/14/2024
//Desc: This file contains the project details and implementation for the Navigator class
//      The airports are nodes for a route
***********************************************/

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "Airport.h"
#include "Route.h"
#include "Navigator.h"

// Overloaded Constructor
Navigator::Navigator(string fileName) {
    m_fileName = fileName; // Populate m_filename with fileName
}

// Destructor
Navigator::~Navigator() {
    // Deallocate all dynamic aspects of the Navigator
    // Clear all airports
    for (Airport* airport : m_airports) {
        delete airport;
    }
    m_airports.clear();

    // Clear all routes
    for (Route* route : m_routes) {
        delete route;
    }
    m_routes.clear();
}

// ReadFile function definition
void Navigator::ReadFile() {
    // Open the file
    std::ifstream file(m_fileName);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file: " << m_fileName << std::endl;
        return;
    }

    // Read data from the file and dynamically allocate airports
    std::string code, name, city, country;
    double north, west;
    while (file >> code >> name >> city >> country >> north >> west) {
        Airport* airport = new Airport(code, name, city, country, north, west);
        m_airports.push_back(airport);
    }

    // Close the file
    file.close();
}

// Function definition
void Navigator::DisplayAirports() {
    if (m_airports.empty()) {
        cout << "No airports available." << endl;
        return;
    }

    // Display each airport with its corresponding number
    for (size_t i = 0; i < m_airports.size(); ++i) {
        cout << i + 1 << ". " << m_airports[i]->GetName() << ", " << m_airports[i]->GetCity() << endl;
    }
}


// Function definition
void Navigator::InsertNewRoute() {
    // Display all airports
    cout << "List of Airports:" << endl;
    DisplayAirports();

    // Dynamically allocate a new route
    Route* newRoute = new Route();

    // Prompt the user to select airports for the route
    int airportIndex;
    do {
        cout << "Enter the number of the airport to add to your Route: (-1 to end)" << endl;
        cin >> airportIndex;

        if (airportIndex >= 1 && static_cast<size_t>(airportIndex) <= m_airports.size()) {
            // Add the selected airport to the route
            Airport* selectedAirport = m_airports[airportIndex - 1];
            newRoute->InsertEnd(selectedAirport->GetCode(), selectedAirport->GetName(),
                selectedAirport->GetCity(), selectedAirport->GetCountry(),
                selectedAirport->GetNorth(), selectedAirport->GetWest());
        }
        else if (airportIndex == 0 || airportIndex > 40) {
            cout << "Invalid airport number - Try again" << endl;
        }
    } while (airportIndex != -1);

    // Check if the route has at least two airports
    if (newRoute->GetSize() < 2) {
        cout << "Route must have at least two airports." << endl;
        delete newRoute; // Free memory
        return;
    }

    // Update the name of the route
    string updatedName = newRoute->UpdateName();
    cout << "Done Building a New Route named " << updatedName << endl;

    // Insert the new route into m_routes
    m_routes.push_back(newRoute);
}


// Function definition
int Navigator::ChooseRoute() {
    // Check if there are routes available
    if (m_routes.empty()) {
        return -1; // Return -1 indicating no route selected
    }

    // Display numbered list of routes
    cout << "Which route would you like to use?" << endl;
    for (size_t i = 0; i < m_routes.size(); ++i) {
        cout << i + 1 << ". " << m_routes[i]->GetName() << endl;
    }

    // Prompt the user to choose a route
    int choice;
    cin >> choice;

    // Validate user input
    if (choice < 1 || static_cast<size_t>(choice) > m_routes.size()) {
        return -1; // Return -1 indicating invalid selection
    }

    // Return the index of the selected route minus 1
    return choice - 1;
}


// Function definition
double Navigator::RouteDistance(Route* route) {
    // Check if the route is empty or has only one airport
    if (route == nullptr || route->GetSize() < 2) {
        return 0; // Return 0 miles for empty or single-airport routes
    }

    double totalDistance = 0.0;
    Airport* currentAirport = route->GetData(0); // Get the first airport

    // Iterate through the airports in the route and calculate distances
    for (int i = 1; i < route->GetSize(); ++i) {
        Airport* nextAirport = route->GetData(i); // Get the next airport
        // Calculate distance between current and next airport
        totalDistance += CalcDistance(currentAirport->GetNorth(), currentAirport->GetWest(),
            nextAirport->GetNorth(), nextAirport->GetWest());
        currentAirport = nextAirport; // Update current airport for next iteration
    }

    return totalDistance; // Return the total distance in miles
}


// Function definition
void Navigator::DisplayRoute() {
    // Check if there are routes available
    if (m_routes.empty()) {
        cout << "No routes to display" << endl;
        return;
    }

    bool validRouteChosen = false;
    while (!validRouteChosen) {
        // Choose a route to display
        int routeIndex = ChooseRoute();
        if (routeIndex != -1) {
            // Get the selected route
            Route* selectedRoute = m_routes[routeIndex];

            // Display the route name
            cout << selectedRoute->GetName() << endl;

            // Display the airports in the selected route
            selectedRoute->DisplayRoute();

            // Calculate and display total miles of the route using RouteDistance function
            double totalMiles = RouteDistance(selectedRoute);
            cout << "The total miles of this route is " << totalMiles << " miles" << endl;

            // Set the flag to true indicating a valid route has been chosen
            validRouteChosen = true;
        }
    }
}





void Navigator::RemoveAirportFromRoute() {
    // Display numbered list of all routes
    int chosenRouteIndex = ChooseRoute();
    if (chosenRouteIndex == -1) {
        cout << "No routes to remove airports" << endl;
        return;
    }

    // Get the chosen route from m_routes
    Route* chosenRoute = m_routes[chosenRouteIndex];

    // Display the old name of the chosen route
    string oldRouteName = chosenRoute->GetName();
    cout << oldRouteName << endl;

    // Check if the route has only two airports
    if (chosenRoute->GetSize() == 2) {
        cout << "Route cannot have less than two airports." << endl;
        return;
    }

    // Display numbered list of all airports in selected route
    chosenRoute->DisplayRoute();

    int airportIndexToRemove;
    cout << "Which airport would you like to remove?" << endl;
    cin >> airportIndexToRemove;

    // Check if the index is valid
    if (airportIndexToRemove < 1 || airportIndexToRemove > chosenRoute->GetSize()) {
        cout << "Invalid airport index." << endl;
        return;
    }

    // Remove airport from route
    chosenRoute->RemoveAirport(airportIndexToRemove - 1);

    // Update name of route if first or last airport removed
    chosenRoute->UpdateName();

    // Display updated route with removed airport
    cout << oldRouteName << endl;
    chosenRoute->DisplayRoute();
    string updatedRouteName = chosenRoute->GetName();
    cout << "Route named " << updatedRouteName << " updated" << endl;
}




void Navigator::ReverseRoute() {
    // Choose a route from m_routes
    int chosenRouteIndex = ChooseRoute();
    if (chosenRouteIndex == -1) {
        cout << "No routes to reverse" << endl;
        return;
    }

    // Get the chosen route from m_routes
    Route* chosenRoute = m_routes[chosenRouteIndex];

    // Get the original name of the route
    string originalName = chosenRoute->GetName();

    // Reverse the route
    chosenRoute->ReverseRoute();

    // Update the name of the route
    string updatedName = originalName.substr(originalName.find("to") + 3) + " to " + originalName.substr(0, originalName.find("to") - 1);
    chosenRoute->SetName(updatedName);

    // Display the reversed route
    cout << "Done reversing Route " << updatedName << endl;
}



// Main Menu Function
void Navigator::MainMenu() {
    ReadFile(); // Read the file

    bool quit = false;

    while (!quit) {
        int choice = 0;

        cout << "What would you like to do?:\n"
            << "1. Create New Route\n"
            << "2. Display Route\n"
            << "3. Remove Airport From Route\n"
            << "4. Reverse Route\n"
            << "5. Exit\n";

        cin >> choice;

        switch (choice) {
        case 1: {
            InsertNewRoute();
            break;
        }
        case 2: {
            DisplayRoute();
            break;
        }
        case 3: {
            RemoveAirportFromRoute();
            break;
        }
        case 4: {
            ReverseRoute();
            break;
        }
        case 5: {
            cout << "Routes removed from memory" << endl;
            cout << "Deleting Airports" << endl;
            cout << "Deleting Routes" << endl;
            quit = true;
            break;
        }
        default: {
            cout << "Invalid choice. Enter a number between 1 and 5." << endl;
            break;
        }
        }
    }
}




// Start Function Definition
void Navigator::Start() {
    // Open the file
    std::ifstream file(m_fileName);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file: " << m_fileName << std::endl;
        return;
    }

    // Read airports from the file and populate m_airports
    std::string line;
    while (std::getline(file, line)) {
        // Find the positions of commas in the line
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);
        size_t pos4 = line.find(',', pos3 + 1);
        size_t pos5 = line.find(',', pos4 + 1);

        // Check if all commas are found
        if (pos1 != std::string::npos && pos2 != std::string::npos &&
            pos3 != std::string::npos && pos4 != std::string::npos && pos5 != std::string::npos) {
            // Extract data from substrings
            std::string code = line.substr(0, pos1);
            std::string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string city = line.substr(pos2 + 1, pos3 - pos2 - 1);
            std::string country = line.substr(pos3 + 1, pos4 - pos3 - 1);
            double north = std::stod(line.substr(pos4 + 1, pos5 - pos4 - 1));
            double west = std::stod(line.substr(pos5 + 1));

            // Create Airport object
            Airport* airport = new Airport(code, name, city, country, north, west);
            // Add Airport object to m_airports
            m_airports.push_back(airport);
        }
        else {
            std::cout << "Error: Invalid format in file." << std::endl;
        }
    }

    // Close the file
    file.close();

    // Display information
    std::cout << "Opened File" << std::endl;
    std::cout << "Airports loaded: " << m_airports.size() << std::endl;

    // Call MainMenu function
    MainMenu();
}





