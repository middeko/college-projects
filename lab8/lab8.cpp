//Title:  Lab 8 - Debugging
//Course: CMSC 202
//Desc:   For this lab, you will use GDB to find where the errors occur.
//        None of the errors are in main(). You should not edit main in any way.
//        You MUST use GDB to get credit for this lab

/* When corrected, this program should output:
     The list is empty!
     This list has 3 nodes.
     Tomato->Asparagus->Carrot->END
     This list has 1 nodes.
     Carrot->END
 */

#include <iostream>
#include <string>
using namespace std;

struct Node {
public:
    string m_info; //Data
    Node* m_next; //Node pointer
};

class LinkedList {
public:
    LinkedList(); //constructor
    ~LinkedList(); //destructor
    void InsertEnd(string data); //Insert function
    void RemoveFront(); //Remove the first node
    void Display(); //Display function
private:
    Node* m_head; //Track front of linked list
    int m_size; //Track size of linked list
};

LinkedList::LinkedList() {
    m_head = nullptr; // Initialize m_head to nullptr
    m_size = 0; // Initialize m_size to 0
}


LinkedList::~LinkedList() { // Destructor for linked list
    while (m_size > 0) {      // While the list is not empty, Remove the first node
        RemoveFront();
    }
}

void LinkedList::InsertEnd(string data) {
    //Possible Cases:
    //list is empty
    if (m_size == 0) {
        m_head = new Node;     // m_head will point to the new Node
        m_head->m_info = data;
        m_head->m_next = nullptr; // Ensure the next pointer of the head node is set to nullptr
        m_size++; // Increment the size of the list
    }
    //list is not empty
    else {
        Node* lastNode = m_head; // lastNode will point to the last Node of the list
        Node* newNode = new Node; // newNode points to the Node being inserted
        newNode->m_info = data;
        while (lastNode->m_next != nullptr) { // iterate lastNode through the list
            lastNode = lastNode->m_next;
        }
        lastNode->m_next = newNode; // link the (old) last node to the new one
        newNode->m_next = nullptr; // link the new node to nullptr
        m_size++; // Increment the size of the list
    }
}


void LinkedList::RemoveFront() {
    if (m_head != nullptr) { // Check if the list is not empty
        //Possible cases:
        //List has one Node
        if (m_size == 1) { // Delete m_head, set to nullptr, and decrement m_size
            delete m_head;
            m_head = nullptr;
            m_size--;
        }
        //List has multiple nodes
        else {
            Node* temp = m_head; // temp keeps track of the first Node to prevent leaks when moving m_head
            m_head = m_head->m_next; // move m_head to the next Node in the list
            delete temp; // delete the old first Node
            temp = nullptr; // temp isn't needed anymore, nullptr
            m_size--; // update size
        }
    }
}


void LinkedList::Display() {
    if (m_head == nullptr) { // Check if the list is empty
        cout << "The list is empty!" << endl;
    }
    else {
        cout << "This list has " << m_size << " nodes." << endl;
        Node* temp = m_head;
        while (temp != nullptr) { // Modify loop condition to check if temp is not nullptr
            cout << temp->m_info << "->";
            temp = temp->m_next;
        }
        cout << "END" << endl;
    }
}






int main() {
    LinkedList list; //Create a new linked list
    list.Display();

    list.RemoveFront(); //Attempt to remove a Node from an empty list

    // Insert several nodes into the linked list
    list.InsertEnd("Tomato");
    list.InsertEnd("Asparagus");
    list.InsertEnd("Carrot");
    list.Display();

    //Remove nodes from the list
    list.RemoveFront();
    list.RemoveFront();
    list.Display();

    return 0;
}
