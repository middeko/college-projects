#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
using namespace std;

class Food{
public:
  Food(); //default constructor

  Food(string name, int type); //overloaded constructor


  //GetName() returns the food item's name
  string GetName(); 

  //GetType() returns the type of the food item
  int GetType();

  //SetName() sets m_name to name
  void SetName(string name);

  //SetType() sets m_type to type
  void SetType(int type);

private:
  string m_name; // Name of the food item
  int m_type; //Type of the food item (Appetizer, Entree, or Dessert)
};

#endif
