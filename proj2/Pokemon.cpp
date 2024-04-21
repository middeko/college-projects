#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Pokemon.h"

Pokemon::Pokemon() {
	// Default constructor initializes member variables to default values
	m_num = 0;         // Default number
	m_name = "";       // Default name
	m_CP = 0;          // Default combat power
	m_rarity = 1;      // Default rarity (set to 1 for simplicity)
}


Pokemon::Pokemon(int num, string name, int cp, int rarity)
{
	// Initialize member variables with passed values
	m_num = num;
	m_name = name;
	m_CP = cp;
	m_rarity = rarity;
}

int Pokemon::GetCP()
{
	// Passes m_CP var to other functions in code
	return m_CP;
}


int Pokemon::GetRarity()
{
	// Passes m_rarity var to other functions in code
	return m_rarity;
}

string Pokemon::GetName() {
	// Passes m_name var to other functions in code
	return m_name;
}

int Pokemon::GetNum()
{
	// Passes m_num var to other functions in code
	return m_num;
}

void Pokemon::SetRarity(int newRarity) {
	// Update m_rarity with the valid input
	m_rarity = newRarity;
}

void Pokemon::SetName(string newName) {
	// Update m_name with the new name
	m_name = newName;
}
void Pokemon::SetCP(int newCP) {
	// Update m_CP with the new combat power
	m_CP = newCP;
}
void Pokemon::Train(int maxCP) {
	// Increase the CP by TRAIN_VALUE, but ensure it doesn't exceed maxCP
	m_CP += TRAIN_VALUE;

	// If the new CP exceeds maxCP, set it to maxCP
	if (m_CP > maxCP) {
		m_CP = maxCP;
	}
}
