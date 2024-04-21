#ifndef GROCERY_H
#define GROCERY_H

#include <iostream>
#include <string>
using namespace std;

class Grocery {
public:
    Grocery(); //default constructor

    Grocery(string name, int type); //overloaded constructor

    //GetName() returns the grocery item's name
    string GetName();

    //GetType() returns the type of the grocery item
    int GetType();

    //SetName() sets m_name to name
    void SetName(string name);

    //SetType() sets m_type to type
    void SetType(int type);

private:
    string m_name; // Name of the grocery item
    int m_type;    // Type of the grocery item (e.g., fruits, vegetables, dairy)
};

#endif
