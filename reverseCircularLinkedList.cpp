// Mohammad Sadegh Salehi

// reverse a circular linked list 
#include <bits/stdc++.h> 
#include<iostream>
using namespace std; 
struct Node { 
	int data; 
	Node* next; 
}; 

Node* getNode(int data) 
{ 
	Node* newNode = new Node; 
	newNode->data = data; 
	newNode->next = NULL; 
	return newNode; 
} 
void reverse(Node** head_ref) 
{ 
	if (*head_ref == NULL) 
		return; 
        
	Node* prev = NULL; 
	Node* current = *head_ref; 
	Node* next; 
	do { 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} while (current != (*head_ref)); 

	(*head_ref)->next = prev; 
	*head_ref = prev; 
} 

void printList(Node* head) 
{ 
	if (head == NULL) 
		return; 

	Node* temp = head; 
	do { 
		cout << temp->data << " "; 
		temp = temp->next; 
	} while (temp != head); 
} 
int main() 
{ 

	int a=0;int size=0;
    cout<<"Enter size of list"<<endl;
    cin>>size;
    cout<<"Enter the list (digit by digit)"<<endl;
    cin>>a;
	Node *head = getNode(a); 
    Node *temp;temp=head;
    for(int i = 0; i < size-1; i++)
    {
        cin>>a;
        temp->next=getNode(a);
        temp=temp->next; 
    }
	temp->next = head; 

	cout << "Given circular linked list: "; 
	printList(head); 

	reverse(&head); 

	cout << "\nReversed circular linked list: "; 
	printList(head); 

	return 0; 
} 
