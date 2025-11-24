#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear >= MAX - 1) {
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
    return rear >= MAX - 1;
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
    cout << "Is full: " << (isFull() ? "Yes" : "No") << endl;
    
    dequeue();
    dequeue();
    
    cout << "Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    
    dequeue();
    
    return 0;
}
