#include <iostream>
using namespace std;

// Global Constants
const int NUM_DAYS = 7; // Number of days in the week
const int NUM_HOURS = 24; // Max hours in a day

// Function Name: getTotalNum
// Pre-conditions: Requires an array
// Post-conditions: Returns the cumulative number in the array
int getTotalNum(int array[]) {
    int cum_number = 0;

    // Calculate the total time
    for (int i = 0; i < NUM_DAYS; i++) {
        cum_number += array[i];
    }

    return cum_number;
}

// Function Name: getLargestNum
// Pre-conditions: Requires an array
// Post-conditions: Returns the largest number in the array
int getLargestNum(int array[]) {
    int largest_element = array[0]; // Assume the first element is the largest

    for (int i = 1; i < NUM_DAYS; i++) {
        if (array[i] > largest_element) {
            largest_element = array[i];
        }
    }

    return largest_element;
}

// Function Name: getAverageNum
// Pre-conditions: Requires an array
// Post-conditions: Returns the average number in the array
double getAverageNum(int array[]) {
    int total = getTotalNum(array); // Use the provided function to get the total
    return static_cast<double>(total) / NUM_DAYS; // Calculate and return the average
}

int main() {
    // Declare array (hours)
    int hours[NUM_DAYS];

    // Declare necessary variable
    int input;

    // Prompt the user for hours spent online each day for every day of the week
    for (int i = 0; i < NUM_DAYS; i++) {
        do {
            cout << "Enter screentime for day " << i + 1 << " in hours: ";
            cin >> input;

            // Check for valid input (non-negative and below max hours in a day)
            if (!(input >= 0 && input <= NUM_HOURS)) {
                cout << "Invalid input. Please enter a non-negative number below " << NUM_HOURS << "." << endl;
            }
            else {
                // Otherwise, insert the input into the array
                hours[i] = input;
            }

        } while (!(input >= 0 && input <= NUM_HOURS)); // Keep prompting until valid input is provided
    }

    // Display results with function calls
    cout << "Most amount of time spent in one day: " << getLargestNum(hours) << " hours" << endl;
    cout << "Total time spent in the week: " << getTotalNum(hours) << " hours" << endl;
    cout << "Average time spent per day: " << getAverageNum(hours) << " hours" << endl;

    return 0;
}
