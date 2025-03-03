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

    void insertFront(int);
    void insertEndNOptimal(int);
    void insertEndOptimal(int);
    void insertAfterK(int, int);
    void deleteByIndex(int);
    void sortList();
    void printList();

    int getHeadValue() {
        if(head == NULL) {
            return -1;
        }else {
            return head->value;
        }
    }

    int getLastValue(){
        if(head == NULL) {
            return -1;
        }else{
            Node* current = head;
            while(current -> next != NULL) {
                current = current -> next;
            }

            return current -> value;
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
void LinkedList::insertEndNOptimal(int value) {
    // Create a new Node with initial value as value
    Node* newNode = new Node(value);
    Node* current = head;

    // If there's no nodes in the linked list
    // Set the new node as head and return
    if(head == NULL) {
        head = newNode;
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
        return;
    }

    // Iterate to the k-th node
    for(int i = 1; i < k; ++i){
        current = current -> next;
    }

    // The next node of our "current" becomes the next of the newNode
    newNode -> next = current -> next;

    // And then node "current" takes next as newNode
    current -> next = newNode;
}
void LinkedList::deleteByIndex(int index) {
    Node* _head = head;
    Node* temp = temp;

    int ll=0;

    if(head == NULL) {
        cout << "List is empty" << endl;
    }

    while(_head != NULL) {
        _head
    }
}


}
int main() {
    return 0;
}
