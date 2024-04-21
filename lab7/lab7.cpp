// File: lab7.cpp
// Date: 2/3/2024                                                                               
// Description: This file handles the story line
#include "SteamTeam.h"

const int STEAM_TEAM_SIZE = 7;

int main() {
    SteamTeam engines; //A new list of trains
    //Part 1: We line up Thomas and his friends
    engines.InsertEnd("Thomas");
    engines.InsertEnd("Emily");
    engines.InsertEnd("Rebecca");
    engines.InsertEnd("Gordon");
    engines.InsertEnd("Nia");
    engines.InsertEnd("Percy");
    engines.InsertEnd("James");

    cout << "The Steam Team came back to Tidmouth Sheds "
        << "after one of their big adventures. \n"
        << "They lined up so that they can enter their "
        << "berths one at a time. "
        << "Thomas is first in line and James is last." << endl;
    engines.Display();
    cout << endl;

    //The steam engines go to their berths one at a time
    for (int i = 0; i < STEAM_TEAM_SIZE; i++) {
        if (engines.GetFirstInLine() == "") {
            cout << "Thomas and his friends were now all "
                << "in their berths and ready to sleep." << endl;
        }
        else {
            cout << engines.GetFirstInLine()
                << " says good night and leaves the line." << endl;
            engines.RemoveFirst();
        }
        // Every time we say goodbye to a steam engine, display the linked list
        engines.Display();
        cout << endl;
    }

    //It is now the next day and the Steam Team is ready for another adventure
    cout << "The next day, Thomas and his friends wake up "
        << "and get ready to the leave shed and go on another "
        << "big adventure! They leave the shed in the order "
        << "they entered it." << endl << endl;

    //Reload the list with the steam team
    engines.InsertEnd("Thomas");
    engines.InsertEnd("Emily");
    engines.InsertEnd("Rebecca");
    engines.InsertEnd("Gordon");
    engines.InsertEnd("Nia");
    engines.InsertEnd("Percy");
    engines.InsertEnd("James");

    engines.Display();
    cout << endl << "The world is just a train ride away. " << endl;
    cout << "BIG WORLD!" << endl;
    cout << "BIG ADVENTURES!" << endl;
    return 0;
}

