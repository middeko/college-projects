#include <iostream>
#include <string>
using namespace std;

int main() {
    string dogName;
    int dogAge;
    int dogChoice;
    cout << "What is your dog's name?" << endl;
    getline(cin, dogName);
    bool validAge = false;
    while (validAge == false) {
        cout << "What is your dog's age?" << endl;
        cin >> dogAge;

        if (dogAge >= 0 && dogAge <= 25) {
            validAge = true; // exits while loop
        }
        else {
            cout << "Invalid age. Please enter a value between 0 and 25." << endl;
        }

    }

    for (int choicesMade = 0; choicesMade < 3; choicesMade++) {
        bool validChoice = false;
        while (validChoice == false) {
            cout << "What would you like to do?\n";
            cout << "1. Play fetch with " << dogName << endl;
            cout << "2. Feed " << dogName << endl;
            cout << "3. Pet " << dogName << endl;
            cin >> dogChoice;

            if (dogChoice >= 1 && dogChoice <= 3) {
                validChoice = true; // exits inner while loop
            }
            else {
                cout << "Invalid choice. Please enter a value between 1 and 3." << endl;
            }
        }

        // processes the choice
        if (dogChoice == 1) {
            cout << dogName << " gets the stick and returns to you!" << endl;
        }
        else if (dogChoice == 2) {
            cout << dogName << " hungrily eats their food." << endl;
        }
        else if (dogChoice == 3) {
            cout << "You happily pet " << dogName << "." << endl;
        }
    }

    cout << "You are a great pet owner! Good-bye" << endl;

    return 0;
}
