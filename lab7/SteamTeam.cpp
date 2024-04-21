//File: SteamTeam.cpp
//Date: 3/25/2024 - 3/28/2024                                                                                         
//Description: You are working on this file!
//Adding and removing nodes from the linked list

#include "SteamTeam.h"

//Constructor
SteamTeam::SteamTeam(){
  m_head = nullptr;
  m_tail = nullptr;
}


//Destructor
SteamTeam::~SteamTeam(){
  //Removes nodes unitl linked list is empty
  while(m_head != nullptr){
      RemoveFirst();
  }

  //reset head and tail of linked list
  m_head = nullptr;
  m_tail = nullptr;
}


//PLEASE COMPLETE THIS FUNCTION
//Takes in name of train to create a steam engine object
//then inserts it to end of linked list
void SteamTeam::InsertEnd(string name) {
    // Create a steam engine object
    SteamEngineNode* newEngine = new SteamEngineNode(name);

    // If the linked list is empty
    if (m_head == nullptr) {
        m_head = newEngine;
        m_tail = newEngine;
    }
    else {
        // Newly created object becomes the new tail
        m_tail->m_next = newEngine;
        m_tail = newEngine;
    }
}


//PLEASE COMPLETE THIS FUNCTION
//Removes the first train in line
//Consider special cases:
//1. When there are no trains in line
//2. One or more trains in line
void SteamTeam::RemoveFirst() {
    // Check if there are any trains left
    if (m_head == nullptr) {
        cout << "The trains are all in their berths" << endl;
    }
    else {
        // Store the current head to delete later
        SteamEngineNode* temp = m_head;

        // Move head to the next node
        m_head = m_head->m_next;

        // If there was only one node, update tail
        if (m_head == nullptr)
            m_tail = nullptr;

        // Delete the old head
        delete temp;
    }
}


//PLEASE COMPLETE THIS FUNCTION
//Outputs the linked list which in this case is the trains in line!
void SteamTeam::Display() {
    // Start from the head of the linked list
    SteamEngineNode* current = m_head;

    // Iterate over the linked list
    while (current != nullptr) {
        // Output each node's data
        cout << current->m_name << " -> ";
        // Move to the next node
        current = current->m_next;
    }
    // Display "END"
    cout << "END" << endl;
}

string SteamTeam::GetFirstInLine(){
  if(m_head)
    return m_head->m_name;
  return "";
}
