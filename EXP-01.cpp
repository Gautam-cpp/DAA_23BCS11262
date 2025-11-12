
#include <iostream>
#include <string>
using namespace std;

// Doubly Linked List
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void display() {
        if (head == nullptr) {
            cout << "(empty)" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

// Circular Linked List
class CNode {
public:
    string data;
    CNode* next;

    CNode(string val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    CNode* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insertAtBeginning(string data) {
        CNode* newNode = new CNode(data);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAtEnd(string data) {
        CNode* newNode = new CNode(data);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFromBeginning() {
        if (tail == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        CNode* temp = tail->next;
        if (tail->next == tail) {
            tail = nullptr;
        } else {
            tail->next = temp->next;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
            return;
        }
        CNode* current = tail->next;
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;
        delete tail;
        tail = current;
    }

    void display() {
        if (tail == nullptr) {
            cout << "(empty)" << endl;
            return;
        }
        CNode* current = tail->next;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != tail->next);
        cout << "(head)" << endl;
    }
};

// Main Function
int main() {
    cout << "--- Doubly Linked List Operations ---" << endl;
    DoublyLinkedList dll;
    dll.display();
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.display();
    dll.deleteFromBeginning();
    dll.display();
    dll.deleteFromEnd();
    dll.display();

    cout << "\n--- Circular Linked List Operations ---" << endl;
    CircularLinkedList cll;
    cll.display();
    cll.insertAtEnd("A");
    cll.insertAtEnd("B");
    cll.insertAtBeginning("X");
    cll.display();
    cll.deleteFromBeginning();
    cll.display();
    cll.deleteFromEnd();
    cll.display();

    return 0;
}
