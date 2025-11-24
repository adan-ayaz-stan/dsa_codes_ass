#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

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
};

int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    
    s.display();
    
    s.peek();
    
    s.pop();
    s.pop();
    
    s.display();
    
    s.peek();
    
    cout << "Is empty: " << (s.isEmpty() ? "Yes" : "No") << endl;
    
    s.pop();
    s.pop();
    
    cout << "Is empty: " << (s.isEmpty() ? "Yes" : "No") << endl;
    
    s.pop();
    
    return 0;
}
