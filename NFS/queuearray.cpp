#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0; // first element
        rear++;
        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // overflow (MAX=5)
    q.display();

    return 0;
}
