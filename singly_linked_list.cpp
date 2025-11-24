#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

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
};

int main() {
    SinglyLinkedList list;
    
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    
    cout << "List after adding: ";
    list.display();
    
    list.addFront(5);
    cout << "After adding 5 at front: ";
    list.display();
    
    list.remove(20);
    cout << "After removing 20: ";
    list.display();
    
    list.remove(5);
    cout << "After removing 5: ";
    list.display();
    
    return 0;
}
