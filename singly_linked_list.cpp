#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void add(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    
    if (head == NULL) {
        head = n;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void addFront(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = head;
    head = n;
}

void remove(int val) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        cout << "Value not found" << endl;
    } else {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
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
    
    remove(20);
    cout << "After removing 20: ";
    display();
    
    remove(5);
    cout << "After removing 5: ";
    display();
    
    return 0;
}
