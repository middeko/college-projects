#include "Game.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Game::Game(string filename)
{
	m_filename = filename;
}

void Game::LoadFile() {
    ifstream inputFile(m_filename);

    // Error message prints if proj2_pokeDex.txt can't be accessed
    if (!inputFile.is_open()) {
        cout << "Error opening file: " << m_filename << endl;
        return;
    }

    // Passes each value onto Pokemon object
    int num, cp, rarity;
    string name;

    for (int i = 0; i < TOTAL_POKEMON; ++i) {
        inputFile >> num >> name >> cp >> rarity;
        m_pokeDex[i] = Pokemon(num, name, cp, rarity);
    }

    inputFile.close();
}

void Game::DisplayPokeDex() {
    // Display the Pokemon with proper indentation and alignment
    for (int i = 0; i < TOTAL_POKEMON; ++i) {
        cout << setw(NUM_WIDTH) << right << i + 1 << ". ";
        cout << setw(NAME_WIDTH) << right << m_pokeDex[i].GetName() << endl;
    }
}



void Game::MainMenu() {
    int choice;

    do {
        // Print statements for user choice
        cout << "What would you like to do?: \n";
        cout << "1. Display Complete Pokedex\n";
        cout << "2. Display your Team\n";
        cout << "3. Search for a new Pokemon\n";
        cout << "4. Battle your Pokemon\n";
        cout << "5. Train your Pokemon\n";
        cout << "6. Exit\n";
        cin >> choice;

        // Switch cases for user choice
        switch (choice) {
        case 1:
            DisplayPokeDex();
            break;
        case 2:
            DisplayTeam();
            break;
        case 3:
            CatchPokemon();
            break;
        case 4:
            BattlePokemon();
            break;
        case 5:
            TrainPokemon();
            break;
        case 6:
            cout << "Thanks for playing!\n";
            break;
        
        }
    } while (choice != 6); // For cases where user misinputs value not between 1-6
}

void Game::CatchPokemon() {
    int rarity = CatchMenu();
    int randomNum = rand() % 100;
    cout << "You start to search.\n";
    // Check if randomNum is less than the original rarity
    if (randomNum < rarity) {
        // If so, adjust the rarity based on specified conditions
        if (rarity == 45) {
            rarity = 1;
        }
        else if (rarity == 25) {
            rarity = 2;
        }
        else if (rarity == 1) {
            rarity = 3;
        }

        // Now, proceed to FoundPokemon and AddPokemon with the adjusted rarity
        Pokemon newPokemon = FoundPokemon(rarity);
        AddPokemon(newPokemon);
    }
    else {
        cout << "No Pokemon found.\n";
    }
}


int Game::CatchMenu() {
    int choice;
    bool validChoice = false;

    do {
        // Print statements for user choice (catching new pokemon)
        cout << "What rarity of Pokemon would you like to catch?:\n";
        cout << "1. Common (High Probability)\n";
        cout << "2. Uncommon (Normal Probability)\n";
        cout << "3. Ultra Rare (Extremely Low Probability)\n";
        cin >> choice;

        // Switch cases for user choice
        switch (choice) {
        case 1:
            validChoice = true;
            return COMMON;
        case 2:
            validChoice = true;
            return UNCOMMON;
        case 3:
            validChoice = true;
            return ULTRA;
        default:
            break;
        }
    } while (!validChoice);

    // This return statement is added to satisfy the compiler.
    return -1; 
}






Pokemon Game::FoundPokemon(int rarity) {
    // Count how many Pokemon have the specified rarity
    int validCount = 0;
    for (int i = 0; i < TOTAL_POKEMON; ++i) {
        if (m_pokeDex[i].GetRarity() == rarity) {
            ++validCount;
        }
    }

    // For case where Pokemon is not found
    if (validCount == 0) {
        cout << "No Pokemon Found.\n";
    }

    // Randomly select from the valid indices
    int randomIndex;
    do {
        randomIndex = rand() % TOTAL_POKEMON;
    } while (m_pokeDex[randomIndex].GetRarity() != rarity);

    Pokemon newPokemon = m_pokeDex[randomIndex];
    int cpReduction = rand() % (MAX_FIND - MIN_FIND + 1) + MIN_FIND;
    int newCP = newPokemon.GetCP() - cpReduction;

    if (newCP < 0) {
        newCP = 0;
    }

    // If Pokemon is found, update CP and print found statement
    newPokemon.SetCP(newCP);
    cout << "You found a " << newPokemon.GetName() << "\n";
    return newPokemon;
}


void Game::AddPokemon(Pokemon newPokemon) {
    if (TeamSize() < NUM_TEAM) {
        // Adds Pokemon object to team array if team size is < 4 
        m_team[TeamSize()] = newPokemon;
        cout << newPokemon.GetName() << " added to your team!\n";
    }
    else {
        int lowestCPIndex = 0;
        for (int i = 1; i < NUM_TEAM; ++i) {
            if (m_team[i].GetCP() < m_team[lowestCPIndex].GetCP()) {
                lowestCPIndex = i;
            }
        }

        if (newPokemon.GetCP() > m_team[lowestCPIndex].GetCP()) {
            m_team[lowestCPIndex] = newPokemon;
            cout << newPokemon.GetName() << " added to your team!\n";
        }
        else {
            // Functionality for when team size > 4
            cout << "Could not add " << newPokemon.GetName() << " to your team. Team is full, and it has lower CP.\n";
        }
    }
}

int Game::TeamSize() {
    // Generates array of 4 indices to hold Pokemon 
    int count = 0;
    for (int i = 0; i < NUM_TEAM; ++i) {
        if (m_team[i].GetNum() != 0) {
            count++;
        }
    }
    return count;
}



void Game::DisplayTeam() {
    // Check if the team is empty
    if (TeamSize() == 0) {
        cout << "You have no team yet. Maybe search for a Pokemon?!" << endl;
        return;
    }

    for (int i = 0; i < NUM_TEAM; ++i) {
        if (m_team[i].GetNum() != 0) {
            // Use setw and right for both name and CP
            cout << (i + 1) << ". " << setw(NAME_WIDTH) << right << m_team[i].GetName() << "  " << setw(NUM_WIDTH) << right << m_team[i].GetCP() << endl;
        }
    }
}






int Game::FindPokemon(string name) {
    // Loops through all Pokémon in the Pokédex
    for (int i = 0; i < TOTAL_POKEMON; ++i) {
        // Checks if the name of the current Pokémon matches the given name
        if (m_pokeDex[i].GetName() == name) {
            // If the name matches, return the index of the Pokémon
            return i;
        }
    }
    // If the Pokémon with the given name is not found, return -1
    return -1;
}


void Game::TrainPokemon() {
    // Check if the player has any Pokémon in their team
    if (TeamSize() == 0) {
        cout << "You have no team yet. Maybe search for a Pokemon?! \n";
        return;
    }

    int choice;
    cout << "Which of your Pokémon would you like to train?:\n";
    // Display the player's Pokémon team
    DisplayTeam();
    cin >> choice;

    // Check if the player's choice is valid
    if (choice < 1 || choice > NUM_TEAM || m_team[choice - 1].GetNum() == 0) {
        cout << "Invalid choice. Please try again.\n";
        return;
    }

    // Get the maximum CP of the selected Pokémon from the Pokédex
    int maxCP = m_pokeDex[m_team[choice - 1].GetNum() - 1].GetCP();
    // Train the selected Pokémon with the maximum CP
    m_team[choice - 1].Train(maxCP);
    // Display a message indicating that the Pokémon's CP has increased
    cout << "Your " << m_team[choice - 1].GetName() << "'s CP goes up!\n";
}



void Game::BattlePokemon() {
    // Check if the player has any Pokémon in their team
    if (TeamSize() == 0) {
        cout << "You have no team yet. Maybe search for a Pokemon?! \n";
        return;
    }

    // Generate a random index to select a random enemy Pokémon from the Pokédex
    int randomEnemyIndex = rand() % TOTAL_POKEMON;
    // Retrieve the enemy Pokémon object from the Pokédex
    Pokemon enemy = m_pokeDex[randomEnemyIndex];
    // Generate a random Combat Power (CP) for the enemy Pokémon
    int enemyCP = rand() % (enemy.GetCP() + ENEMY_ADD + 1);

    // Display information about the enemy Pokémon and its CP
    cout << "You are going to fight a " << enemy.GetName() << "\nThe enemy has a CP of " << enemyCP << endl;
    cout << "Which of your Pokémon would you like to use?:\n";
    // Display the player's Pokémon team
    DisplayTeam();
    int choice;
    cin >> choice;

    // Check if the player's choice is valid
    if (choice < 1 || choice > NUM_TEAM || m_team[choice - 1].GetNum() == 0) {
        cout << "Invalid choice. Please try again.\n";
        return;
    }

    // Retrieve the player's selected Pokémon from their team
    Pokemon playerPokemon = m_team[choice - 1];

    // Compare the CP of the player's Pokémon with the enemy Pokémon's CP to determine the battle result
    if (playerPokemon.GetCP() > enemyCP) {
        cout << "You won!! " << endl;
    }
    else {
        // If the player loses, display a message indicating the loss and set the CP of the player's Pokémon to 0
        cout << "You lost.\nYour " << playerPokemon.GetName() << " can't lift its head.\nYou should replace it.\n";
        m_team[choice - 1].SetCP(0);
    }
}


void Game::Start() {
    // Starts game and Main Menu
    LoadFile();
    MainMenu();
}
