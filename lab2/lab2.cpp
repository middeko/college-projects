/*
 * lab2.cpp
 * This program practices C++ regarding input/output, loops, functions in C++
 */

#include <iostream>
using namespace std;

// FUNCTION PROTOYPES FOR sumOfInts() and divisibleByThree() GO HERE  *
int SumOfInts();
void DivisibleByThree(int);



//*******main********
/*
The user should enter their desired amount of numbers, and the program should display the final
value after the operations, as well as if the total is divisible by 3 or not.
This logic must be implemented in one line. This means that the main() function can have ONE
statement (and the return 0).
*/
//Implement main here:
int main() {
	// Calls SumOfInts and DivisibleByThree functions in one line
	DivisibleByThree(SumOfInts());

	return 0;
}







//******sumOfInts*****
//The user should be prompted to enter how many ints they would like to add together
//Afterwards, the user should enter values until the number of specified ints is reached
//Print and return the sum
//Implement sumOfInts() here:

int SumOfInts() {
	int NumInts, sum = 0;

	// Prompt user for number of ints that will be added together //
	cout << "How many ints would you like to add together? ";
	cin >> NumInts;

	// Loop that gets user input and calculates sum //
	for (int i = 0; i < NumInts; ++i) {
		int input;
		cout << "Enter an int: ";
		cin >> input;
		sum += input;
	}

	// Prints and rerturns sum
	cout << "Sum: " << sum << endl;
	return sum;
}



//******divisibleByThree*****
/*
The program should display a message to indicate whether the int passed is divisible by 3 or not
*/
//Implement divisibleByThree here:
void DivisibleByThree(int num) {
	// Checks if the number is divisible by 3
	if (num % 3 == 0) {
		cout << num << " is divisible by 3!" << endl;
	}
	else {
		cout << num << " is not divisible by 3." << endl;
	}
}

