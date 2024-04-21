#include "Food.h"
#include <vector>

enum FOOD_TYPE { APPETIZER, ENTREE, DESSERT };

//Write addToMenu
//Ask the user how many items they want to add to the menu
//For each item, ask the user for the name and type (0-2)
//Create a Food object with the information and add it to the vector
//You might have to use if(cin.peek() == '\n') cin.ignore(256,'\n') to clear the buffer
void addToMenu(vector<Food>& Menu) {

}

//Write displayWithoutIterator
//Display the number of items on the menu
//For each item, display the name, type, and serving time
//Use a switch statement to display the type and serving time
//Don't forget to display the name aswell
void displayWithoutIterator(vector<Food>& Menu) {

}

//Here is some free code! Use it wisely!
/*
  switch(FILL THIS IN){
  case APPETIZER:
  cout << "An Appetizer called ";
  break;
  case ENTREE:
  cout << "An Entree called ";
  break;
  case DESSERT:
  cout << "A Dessert called ";
  break;
  default:
  cout << "A Food called ";
  break;
  }
*/

//FUNCTION TO COMPLETE
void DisplayWithIterator(vector<Food>& Menu) {
	//This function is the same as the one above, but uses an iterator to display the menu
}

//Main
//Provided.

int main() {
	vector<Food> Menu;
	addToMenu(Menu);
	cout << "Displaying Menu without iterator:" << endl;
	displayWithoutIterator(Menu);
	cout << endl;
	cout << "Displaying Menu with iterator:" << endl;
	DisplayWithIterator(Menu);
	cout << endl << "What a good looking menu!" << endl;
	return 0;
}

