#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = top;
    top = n;
    cout << val << " pushed to stack" << endl;
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    Node* temp = top;
    cout << top->data << " popped from stack" << endl;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element: " << top->data << endl;
    }
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    Node* temp = top;
    cout << "Stack: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isEmpty() {
    return top == NULL;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    
    display();
    
    peek();
    
    pop();
    pop();
    
    display();
    
    peek();
    
    cout << "Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    
    pop();
    pop();
    
    cout << "Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    
    pop();
    
    return 0;
}
