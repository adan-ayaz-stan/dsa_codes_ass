#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void add(int val) {
        Node* n = new Node();
        n->data = val;
        n->next = NULL;
        
        if (head == NULL) {
            head = n;
            n->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
        }
    }

    void addFront(int val) {
        Node* n = new Node();
        n->data = val;
        
        if (head == NULL) {
            head = n;
            n->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            n->next = head;
            temp->next = n;
            head = n;
        }
    }

    void remove(int val) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        Node* prev = NULL;
        
        if (head->data == val) {
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }
            
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        
        prev = head;
        temp = head->next;
        
        while (temp != head && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        
        if (temp == head) {
            cout << "Value not found" << endl;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to " << head->data << ")" << endl;
    }
};

int main() {
    CircularLinkedList list;
    
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
