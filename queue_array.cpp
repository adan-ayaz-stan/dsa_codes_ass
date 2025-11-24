#include <iostream>
using namespace std;

class Queue {
private:
    int queue[100];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (rear >= 100 - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        
        if (front == -1) {
            front = 0;
        }
        
        rear++;
        queue[rear] = val;
        cout << val << " enqueued to queue" << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << queue[front] << " dequeued from queue" << endl;
        front++;
        
        if (front > rear) {
            front = rear = -1;
        }
    }

    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << queue[front] << endl;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return rear >= 100 - 1;
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
    cout << "Is full: " << (q.isFull() ? "Yes" : "No") << endl;
    
    q.dequeue();
    q.dequeue();
    
    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    q.dequeue();
    
    return 0;
}
