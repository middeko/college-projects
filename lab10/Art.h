// File: Art.h
// Desc: This is the parent class for lab 10
// Date: 2/1/2022
// Author: Tyler Castle

#ifndef ART_H
#define ART_H
#include <iostream>
using namespace std;
 
class Art{
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Art();
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Art();
 
  // callMyType() - Prints object's type
  // Preconditions: Object exists
  // Postconditions: Object's type is printed
  virtual void CallMyType();
 
  // callTitle() - Prints object's name
  // Preconditions: Object exists
  // Postconditions: Object's title is printed
  virtual void CallMyTitle() = 0; // <- Declares as purely virtual function
 
  // getType() - returns myType
  // Preconditions: myType is initialized
  // Postconditions: None
  string GetType();
 
  // setType() - sets value of myType
  // Preconditions: None
  // Postconditions: None
  void SetType(string type);
 
  // describeMe() - gives description of the art
  // Preconditions: None
  // Postconditions: None
  virtual void DescribeMe() = 0; // <- Declares as purely virtual function
 
private:
  string m_myType;
};
 
#endif
