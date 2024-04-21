#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // For rand function
#include <ctime>    // For srand function

using namespace std;

// Number of categories and data pairs
const int NUM_PAIRS = 24;

// Function prototype for printPuzzle
void printPuzzle(const string& puzzle);

// Function prototype for getInput
void getInput(const string& puzzle);

// Function prototype for isCompleted
bool isCompleted(const string& guessedWord, const string& puzzle);


// Function to load data from the file
void LoadFile(string dataMatrix[NUM_PAIRS][2]) {
    // Open the file
    ifstream inputFile("proj1_data.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Variables to store data
    string category, data;

    // Read data from the file
    for (int i = 0; i < NUM_PAIRS; ++i) {
        // Read category and data (ex. category: Thing, data: A BRISK PACE)
        getline(inputFile, category);
        getline(inputFile, data);

        // Store in the 2D array
        dataMatrix[i][0] = category;
        dataMatrix[i][1] = data;
    }

    // Close the file
    inputFile.close();

    // Print success message
    cout << NUM_PAIRS << " puzzles loaded." << endl;
}

// Function to get a random category and its corresponding data pair
void getAnswer(string dataMatrix[NUM_PAIRS][2]) {
    // Seed for random number generation
    srand(time(NULL));

    // Generate a random index within the range of NUM_PAIRS
    int randomIndex = rand() % NUM_PAIRS;

    // Print the randomly chosen category and data (data is commented out)
    cout << "Category is: " << dataMatrix[randomIndex][0] << endl;
    // cout << "Data is: " << dataMatrix[randomIndex][1] << endl;

    // Call the function to print the initial puzzle
    printPuzzle(dataMatrix[randomIndex][1]);

    // Call the function to get user input and update the puzzle
    getInput(dataMatrix[randomIndex][1]);
}

// Function to print the puzzle with underscores
void printPuzzle(const string& puzzle) {
    for (char c : puzzle) {
        if (c == ' ') {
            cout << ' ';
        }
        else {
            cout << '_';
        }
    }
    cout << endl;
}

// Function to get user input and update the puzzle
void getInput(const string& puzzle) {
    string guessedWord(puzzle.length(), '_');  // Initialize guessedWord with underscores
    string guessedLetters; // String to store guessed letters

    while (true) {
        bool validInput = true; // Flag to indicate whether the input is valid

        cout << "What letter would you like to try?" << endl;
        char userInput;
        cin >> userInput;

        // Check if the user input is an uppercase letter
        if (isupper(userInput)) {
            char guessedLetter = tolower(userInput);

            // Check if the guessed letter has already been guessed
            if (guessedLetters.find(guessedLetter) != string::npos) {
                cout << userInput << " already guessed." << endl;
                validInput = false;
            }
            else {
                // Update guessedWord with the guessed letter
                int letterCount = 0; // Count of the guessed letter in the answer
                for (size_t i = 0; i < puzzle.length(); ++i) {
                    if (tolower(puzzle[i]) == guessedLetter) {
                        guessedWord[i] = toupper(puzzle[i]);
                        letterCount++;
                    }
                }

                // Check if the guessed letter is in the puzzle
                if (letterCount > 0) {
                    cout << letterCount << " " << userInput << " found in the puzzle." << endl;
                }
                else {
                    cout << userInput << " not found in the puzzle." << endl;
                }

                // Print the updated guessedWord, handling spaces correctly
                for (size_t i = 0; i < puzzle.length(); ++i) {
                    if (puzzle[i] == ' ') {
                        cout << ' ';
                    }
                    else {
                        cout << guessedWord[i];
                    }
                }
                cout << endl;

                guessedLetters += guessedLetter; // Add guessed letter to the string
            }
        }
        else {
            cout << "Invalid input. Please enter an uppercase letter." << endl;
            validInput = false; // Set the flag to false to prevent proceeding with the next iteration
        }

        // Check if the puzzle is complete
        if (isCompleted(guessedWord, puzzle)) {
            return;
        }

        // If validInput is false, prompt the user again
        if (!validInput) {
            cin.clear(); // Clear the error flag

            // Discard invalid input by reading characters until a newline character is encountered
            while (cin.get() != '\n') {
                // Does nothing
            }
        }

    }
}


// Function to check if the puzzle is complete
bool isCompleted(const string& guessedWord, const string& puzzle) {
    for (size_t i = 0; i < puzzle.length(); ++i) {
        if (puzzle[i] != ' ' && guessedWord[i] != puzzle[i]) {
            return false;
        }
    }
    return true;
}



int main() {
    std::cout << "Welcome to UMBC Fortune Wheel!\n";

    // Create a 2D array to store category and data pairs
    string dataMatrix[NUM_PAIRS][2];

    // Call the function to load data from the file
    LoadFile(dataMatrix);

    bool playAgain = false;  // Initialize the playAgain flag

    do {
        // Call the function to get a random category and its corresponding data pair
        getAnswer(dataMatrix);

        // Check if the puzzle is complete
        cout << "You won!" << endl;

        // Set playAgain to false, indicating the game should not continue
        playAgain = false;

    } while (playAgain);

    return 0;
}

