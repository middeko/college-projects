#include "Grocery.h"
#include <iostream>
#include <vector>

using namespace std;

//Sets FRUITS = 0, VEGETABLES = 1, and DAIRY = 2
enum GROCERY_TYPE { FRUITS, VEGETABLES, DAIRY };

// Write addToShoppingList
// Ask the user how many items they want to add to the shopping list
// For each item, ask the user for the name and type (0-2)
// Create a Grocery object with the information and add it to the vector
// You might have to use if(cin.peek() == '\n') cin.ignore(256,'\n') to clear the buffer
void addToShoppingList(vector<Grocery>& ShoppingList) {
    int numItems;
    cout << "How many items would you like to add to the shopping list? ";
    cin >> numItems;
    cin.ignore(); // Clear the buffer

    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << i + 1 << ":" << endl;
        cout << "What is the name of the item? \n";
        string name;
        getline(cin, name);

        int type;
        cout << "What type of grocery is this item?\n(0 for fruits, 1 for vegetables, 2 for dairy) \n";
        cin >> type;
        cin.ignore(); // Clear the buffer

        ShoppingList.push_back(Grocery(name, type));
    }
}

// Write displayWithoutIterator
// Display the number of items on the shopping list
// For each item, display the name, type, and category
// Use a switch statement to display the type and category
// Don't forget to display the name as well
void displayWithoutIterator(vector<Grocery>& ShoppingList) {
    cout << "We have " << ShoppingList.size() << " items on the shopping list." << endl;
    for (size_t i = 0; i < ShoppingList.size(); ++i) {
        switch (ShoppingList.at(i).GetType()) {
        case FRUITS:
            cout << "Fruits: ";
            break;
        case VEGETABLES:
            cout << "Vegetables: ";
            break;
        case DAIRY:
            cout << "Dairy: ";
            break;
        default:
            cout << "Grocery: ";
            break;
        }
        cout << ShoppingList.at(i).GetName() << "." << endl;
    }
}



void DisplayWithIterator(vector<Grocery>& ShoppingList) {
    cout << "We have " << ShoppingList.size() << " items on the shopping list." << endl;

    // Iterate over the ShoppingList vector using an iterator
    for (auto it = ShoppingList.begin(); it != ShoppingList.end(); ++it) {
        // Switch statement to display the type and category
        switch (it->GetType()) {
        case FRUITS:
            cout << "Fruits: ";
            break;
        case VEGETABLES:
            cout << "Vegetables: ";
            break;
        case DAIRY:
            cout << "Dairy: ";
            break;
        default:
            cout << "Grocery: ";
            break;
        }

        cout << it->GetName() << "." << endl;
    }
}



// Main
// Provided.
int main() {
    vector<Grocery> ShoppingList;
    addToShoppingList(ShoppingList);
    cout << "Displaying Shopping List without iterator:" << endl;
    displayWithoutIterator(ShoppingList);
    cout << endl;
    cout << "Displaying Shopping List with iterator:" << endl;
    DisplayWithIterator(ShoppingList);
    cout << endl << "What a good-looking shopping list!" << endl;
    return 0;
}
