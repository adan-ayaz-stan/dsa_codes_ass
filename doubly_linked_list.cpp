#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void add(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    n->prev = NULL;
    
    if (head == NULL) {
        head = n;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void addFront(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = head;
    n->prev = NULL;
    
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
}

void remove(int val) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    delete temp;
}

void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void displayReverse() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    add(10);
    add(20);
    add(30);
    add(40);
    
    cout << "List after adding: ";
    display();
    
    addFront(5);
    cout << "After adding 5 at front: ";
    display();
    
    cout << "Display in reverse: ";
    displayReverse();
    
    remove(20);
    cout << "After removing 20: ";
    display();
    
    remove(5);
    cout << "After removing 5: ";
    display();
    
    return 0;
}
