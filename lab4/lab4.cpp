#include <iostream>
using namespace std;

// Global Constants
const double ABSOLUTE_ZERO_CELSIUS = -273.15;
const double ABSOLUTE_ZERO_KELVIN = 0.0;
const double KELVIN_OFFSET = 273.15;



int main() {
    double temperature = 0.0;
    int choice = 0;

    cout << "Welcome to Temperature Conversion tool" << endl << endl;

    do {
        cout << "Please select below:" << endl;
        cout << "1. Convert from Kelvin to Celsius" << endl;
        cout << "2. Convert from Celsius to Kelvin" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "\nTemperature in Kelvin: ";
            cin >> temperature;
            toCelsius(temperature); // Pass by reference
        }
        else if (choice == 2) {
            cout << "\nTemperature in Celsius: ";
            cin >> temperature;
            toKelvin(&temperature); // Pass address of temperature
        }

        cout << endl;

    } while (choice != 3);

    cout << "Have a good one!" << endl;

    return 0;
}

// Function to convert from Kelvin to Celsius using pass by reference
void toCelsius(int &temperature) {
    temperature -= KELVIN_OFFSET;
    if (temperature < ABSOLUTE_ZERO_CELSIUS) {
        cout << "The temperature is below absolute zero." << endl;
    }
    else {
        cout << "Temperature in Celsius: " << temperature << endl;
    }
}

// Function to convert from Celsius to Kelvin using pointers
void toKelvin(double *temperature) {
    *temperature += KELVIN_OFFSET;
    if (*temperature < ABSOLUTE_ZERO_KELVIN) {
        cout << "The temperature is below absolute zero." << endl;
    }
    else {
        cout << "Temperature in Kelvin: " << *temperature << endl;
    }
}
