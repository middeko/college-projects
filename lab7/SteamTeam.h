// File: SteamTeam.h
// Date: 3/25/2024 - 3/28/2024
// Description: header file for linked list and train nodes
#ifndef STEAMTEAM_H_
#define STEAMTEAM_H_
#include <iostream>
using namespace std;

// Our nodes in the linked list will be the steam engines!
struct SteamEngineNode{
  // SteamEngine constructor
  SteamEngineNode(){
    m_name = "";       // default name
    m_next = nullptr;  // pointer to the next node!
  }

  // overloaded constructor
  SteamEngineNode(string name){
    m_name = name;
    m_next = nullptr;
  }

  string m_name;           // our node's data
  SteamEngineNode *m_next; // pointer to next node
};

class SteamTeam{
public:
  SteamTeam();            // Constructor for our linked list
  ~SteamTeam();           // Destructor for our linked list
  void Display();         // outputs the linked list
  void RemoveFirst();     // removes the first object in linked list
  void InsertEnd(string); // inserts object to end of linked list
  string GetFirstInLine();// gets name of the train at the front of the line

private:
  SteamEngineNode *m_head; // points to beginning of linked list
  SteamEngineNode *m_tail; // points to end of linked list
};

#endif
