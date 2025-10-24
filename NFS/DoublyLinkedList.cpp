#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void displayBackward(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;  // move to last node
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}


void insertAtHead(Node* &head, int val){
	Node* newNode = new Node;
	newNode -> data = val;
	newNode -> prev = NULL;
	newNode -> next = head;
	
	if(head != NULL)
		head -> prev = newNode;
	head = newNode;
}

void insertAtTail(Node* &head, int val){
	if (head == NULL){
		insertAtHead(head, val);
		return;
	}
	Node* temp = head;
	while (temp -> next != NULL)
		temp = temp ->next;
	
	Node* endNode = new Node;
	temp -> next = endNode;
	endNode -> data = val;
	endNode -> next = NULL;
	endNode -> prev = temp;		
}

void deleteNode(Node* &head, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) return; // not found

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; // deleting first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

int main(){
	Node* head = NULL;
	insertAtTail(head, 10);
	insertAtHead(head, 5);
	insertAtTail(head, 80);
	insertAtTail(head, 90);
	insertAtHead(head, 3);
	insertAtHead(head, 1);
	deleteNode(head, 80);
	displayForward(head);
	cout << endl;
	displayBackward(head);
}