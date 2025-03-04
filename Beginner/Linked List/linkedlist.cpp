/*
    Author: Vladyslav Hirchuk
    Created: March 2025
    Description: Implementation of a Linked List with insertion, deletion, and sorting.
    License: MIT
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    // Constructor to initialize the node with a given value
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    // Create the Node tail (for optimal insertion)
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() {  // Destructor to free memory
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Insertion
    void insertFront(int);
    void insertEndNOptimal(int);
    void insertEndOptimal(int);
    void insertAfterK(int, int);

    // Deletion
    void deleteByIndex(int);
    void deleteFront();
    void deleteEnd();

    // Basic operations with L
    void sort();
    void reverse();
    bool find(int);
    int length();

    void print();

    int getHeadValue() {
        if(head == NULL) {
            return -1;
        }else {
            return head->value;
        }
    }

    int getLastValue(){
        return (tail) ? tail->value : -1;
    }
};

void LinkedList::insertFront(int value) {
    cout << "Inserting: " << value << "\n";

    // Step 1: Creating a new node
    Node* newNode = new Node(value);

    // Step 2: Set next of newNode to the current head
    newNode->next = head;

    // Step 3: Set newNode as the head
    head = newNode;

    // Step 4: If the list  was empty. update tail to a new node
    if (tail == nullptr) {
        tail = newNode;
    }
}
void LinkedList::insertEndNOptimal(int value) {
    // Create a new Node with initial value as value
    Node* newNode = new Node(value);
    Node* current = head;

    // If there's no nodes in the linked list
    // Set the new node as head and return
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Iterate to the end of the list
    while (current->next != NULL) {
        current = current -> next;
    }

    current -> next = newNode;
}
void LinkedList::insertEndOptimal(int value) {
    Node* newNode = new Node(value);

    // If there are no nodes in the linked list
    // Set the new node as head and return
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Set the tail to the newNode
    tail -> next = newNode;
    // Set newNode as the new tail
    tail = newNode;
}
void LinkedList::insertAfterK(int value, int k) {
    Node* newNode = new Node(value);
    Node* current = head;

    // If there are no nodes in the linked list
    // Set the new node as head and return
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Iterate to the k-th node
    for(int i = 1; i < k; ++i){
        current = current -> next;
    }

    // Check if it's out of bounds that we can actually store that value
    if(current == nullptr) {
        cout << "Position is out of bounds" << endl;
        delete newNode;
        return;
    }

    // The next node of our "current" becomes the next of the newNode
    newNode -> next = current -> next;

    // And then node "current" takes next as newNode
    current -> next = newNode;

    if(newNode->next == nullptr) {
        tail = newNode;
    }
}

void LinkedList::deleteFront() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.";
        return;
    }

    // Store the current head node
    Node* temp = head;

    // Move head to the next node
    head = head->next;

    // If head becomes nullptr (list is now empty), update tail too
    if (head == nullptr) {
        tail = nullptr;
    }

    // Free the old head node
    delete temp;
}
void LinkedList::deleteByIndex(int index) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete.";
        return;
    }

    // Step 1: Check if we delete the front
    if (index == 0) {
        deleteFront();
        return;
    }


    // Step 2: Iterating through the whole list, trying to find the index, but also check if the current != nullptr
    Node* current = head;
    Node* prev = nullptr;

    for(int i = 0; i < index && current != nullptr; ++i) {
        prev = current;
        current = current -> next;
    }

    // Step 3: Check if index is out of bounds
    if (current == nullptr) {
        cout << "Invalid index" << endl;
        return;
    }

    // Step 4: Update the previous node's next pointer
    prev -> next = current -> next;

    // If the deleted node was the last node, update tail
    if (current->next == nullptr) {
        tail = prev;
    }

    delete current;
}
void LinkedList::deleteEnd() {
    if(head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // Only head exists
    if(head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    // Traversing through the whole list
    Node* current = head;
    while(current->next->next != nullptr) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr; // Update tail
}

void LinkedList::sort() {
    // Bubble sort implementation (0(n^2)), yes, nothing is perfect
    if(!head || !head -> next) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while(current->next) {
            if(current->value > current->next->value) {
                swap(current->value, current->next->value);
                swapped = true;
            }
            current = current->next;
        }
    }while(swapped);
}
void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next;

    tail = head;

    while(current != nullptr) {
        next = current->next; // Store next
        current->next = prev; // Reverse pointer
        prev = current;
        current = next;
    }
    head = prev;
}
int LinkedList::length() {
    int counter = 0;
    Node* current = head;
    while(current) {
        counter++;
        current = current->next;
    }

    return counter;
}
bool LinkedList::find(int value) {
    Node* curr = head;
    while(curr) {
        if(curr->value == value) return true;
        curr = curr->next;
    }

    return false;
}


void LinkedList::print() {
    Node* temp = head;
    while (temp) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    LinkedList list;
    int choice, value, index;

    cout << "Linked List Implementation\n\n";
    while (true) {
        cout << "1. Insert Front\n2. Insert End (Non-Optimal)\n3. Insert End (Optimal)\n4. Insert After K\n5. Delete Front\n6. Delete by Index\n7. Print List\n8. Exit\n\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertFront(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEndNOptimal(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                list.insertEndOptimal(value);
                break;
            case 4:
                cout << "Enter value and position: ";
                cin >> value >> index;
                list.insertAfterK(value, index);
                break;
            case 5:
                list.deleteFront();
                break;
            case 6:
                cout << "Enter index to delete: ";
                cin >> index;
                list.deleteByIndex(index);
                break;
            case 7:
                list.print();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

