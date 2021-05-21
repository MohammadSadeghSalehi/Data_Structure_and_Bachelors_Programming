// Mohammad Sadegh Salehi
// sorted insert in circular linked list 
#include <bits/stdc++.h> 
#include<iostream>
using namespace std; 

class Node 
{ 
	public: 
	int data; 
	Node *next; 
}; 

void sortedInsert(Node** head_ref, Node* new_node) 
{ 
	Node* current = *head_ref; 

	if (current == NULL) 
	{ 
		new_node->next = new_node; 
		*head_ref = new_node; 
	} 
	
	else if (current->data >= new_node->data) 
	{ 
		while(current->next != *head_ref) 
			current = current->next; 
		current->next = new_node; 
		new_node->next = *head_ref; 
		*head_ref = new_node; 
	} 
	else
	{ 
		while (current->next!= *head_ref && 
			current->next->data < new_node->data) 
		current = current->next; 
	
		new_node->next = current->next; 
		current->next = new_node; 
	} 
} 
void printList(Node *start) 
{ 
	Node *temp; 
	
	if(start != NULL) 
	{ 
		temp = start; 
		do { 
		cout<<temp->data<<" "; 
		temp = temp->next; 
		} while(temp != start); 
	} 
} 

int main() 
{ 
    int list_size, i;
    cout<<"enter list size"<<endl;
    cin>>list_size; 
	int arr[list_size]; 
    cout<<"enter data separately"<<endl;
    for(int j = 0; j < list_size; j++)
    {
        cin>>arr[j];
    }
    
	Node *start = NULL; 
	Node *temp; 
	
	for (i = 0; i< list_size; i++) 
	{ 
		temp = new Node(); 
		temp->data = arr[i]; 
		sortedInsert(&start, temp); 
	} 
	
	printList(start); 
	
} 
 
