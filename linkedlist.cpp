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

    void insertFront(int);
    void insertEnd(int);
    void deleteNode(int);
    void sortList();
    void printList();

    void insertFront(int value) {

    }

    int getHeadValue() {
        if(head == NULL) {
            return -1;
        }else {
            return head->value;
        }
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
}

void LinkedList::insertEnd(int value) {
    cout << "Inserting" << value << "\n";

    // Step 1: Creating a new node
    Node* newNode = new Node(value);

    // Step 2: Iterating through the whole list to find the end
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    // Step 3: After finding NULL, assigning our newNode
    temp->next = newNode;
}

int main() {
    LinkedList* someList = new LinkedList();

    someList->insertFront(3);
    cout << "The value at the head is: " << someList -> getHeadValue() << "\n";

    someList.insertFront(2);
    cout << "The valie at the head is: " << someList -> getHeadValue() << "\n";

    return 0;
}
