#include <iostream>
using namespace std;

class Stack {
private:
    int stack[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int val) {
        if (top >= 100 - 1) {
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
        return top >= 100 - 1;
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
    cout << "Is full: " << (s.isFull() ? "Yes" : "No") << endl;
    
    s.pop();
    s.pop();
    
    cout << "Is empty: " << (s.isEmpty() ? "Yes" : "No") << endl;
    
    s.pop();
    
    return 0;
}
