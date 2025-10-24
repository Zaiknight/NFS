#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void display(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

void insertAtStart(Node* &head, int val){
	Node* newNode = new Node;
	newNode -> data = val;
	newNode -> next = head;
	head = newNode;
	display(head);
}

void insertAtEnd(Node* &head, int val){
	Node* newNode = new Node;
	newNode -> data = val;
	newNode -> next = NULL;
	if(head == NULL){
		head = newNode;
		display(head);
		return;
	}
	Node* temp = head;
	while (temp -> next != NULL)
		temp = temp ->next;
	temp -> next = newNode;
	display(head);
}

void deletebyVal(Node* &head, int val){
	if(head == NULL)return;
	if(head -> data == val){
		Node* toDel = head;
		head = head -> next;
		delete toDel;
		return;
	}
	Node* temp = head;
	while (temp -> next != NULL && temp -> next -> data != val)
		temp = temp->next;
	if (temp -> next == NULL)return;
	Node* toDel = temp -> next;
	temp -> next = temp -> next-> next;
	delete toDel;
}                   



int main(){
	Node* head = NULL;
	insertAtEnd(head, 10);
	insertAtStart(head, 5);
	insertAtEnd(head, 80);
	insertAtEnd(head, 90);
	insertAtStart(head, 3);
	insertAtStart(head, 1);
	deletebyVal(head, 80);
	display(head);
}