#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at the beginning
    void insertAtHead(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Insert after a specific value
    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Key not found!\n";
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Value not found.\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

// ----------------------------
// MAIN FUNCTION FOR TESTING
// ----------------------------
int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertAfter(20, 25);

    list.display();

    cout << "Deleting 30...\n";
    list.deleteNode(30);
    list.display();

    cout << "Searching for 25: ";
    if (list.search(25))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << "Searching for 99: ";
    if (list.search(99))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
