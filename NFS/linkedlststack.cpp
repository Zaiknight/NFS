#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* top; // pointer to the top of the stack
public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top; // link new node to the current top
        top = newNode;       // move top to the new node
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next; // move top one down
        delete temp;     // free the popped node
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    cout << "Top after pop: " << s.peek() << endl;

    s.pop();
    s.pop();
    s.pop(); // underflow test

    return 0;
}
