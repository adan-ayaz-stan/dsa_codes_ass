#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        cout << "Stack overflow" << endl;
        return;
    }
    
    top++;
    stack[top] = val;
    cout << val << " pushed to stack" << endl;
}

void pop() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    cout << stack[top] << " popped from stack" << endl;
    top--;
}

void peek() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}

void display() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

bool isEmpty() {
    return top < 0;
}

bool isFull() {
    return top >= MAX - 1;
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
    cout << "Is full: " << (isFull() ? "Yes" : "No") << endl;
    
    pop();
    pop();
    
    cout << "Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    
    pop();
    
    return 0;
}
