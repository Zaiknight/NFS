#include <iostream>
using namespace std;

#define MAX 5 // maximum size of stack

class Stack {
    int arr[MAX];
    int top; // points to top element index
public:
    Stack() { top = -1; }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s; // create a Stack object

    cout << "Pushing elements...\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); // will cause overflow (MAX=5)

    cout << "\nCurrent stack (top to bottom): ";
    s.display();

    cout << "\nTop element: " << s.peek() << endl;

    cout << "\nPopping two elements...\n";
    s.pop();
    s.pop();

    cout << "Current stack (top to bottom): ";
    s.display();

    cout << "\nTop element after popping: " << s.peek() << endl;

    cout << "\nPopping all elements...\n";
    while (!s.isEmpty())
        s.pop();

    cout << "Trying to pop from empty stack:\n";
    s.pop(); // will cause underflow

    return 0;
}

