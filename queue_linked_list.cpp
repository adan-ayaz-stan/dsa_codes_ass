#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

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
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    q.display();
    
    q.peek();
    
    q.dequeue();
    q.dequeue();
    
    q.display();
    
    q.peek();
    
    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    q.dequeue();
    q.dequeue();
    
    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    q.dequeue();
    
    return 0;
}
