#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    
    if (rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
    cout << val << " enqueued to queue" << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    Node* temp = front;
    cout << front->data << " dequeued from queue" << endl;
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;
    }
    
    delete temp;
}

void peek() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    Node* temp = front;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isEmpty() {
    return front == NULL;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();
    
    peek();
    
    dequeue();
    dequeue();
    
    display();
    
    peek();
    
    cout << "Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    
    dequeue();
    dequeue();
    
    cout << "Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    
    dequeue();
    
    return 0;
}
