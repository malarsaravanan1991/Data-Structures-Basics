/*Implementation of doubly linked list */

#include<assert.h>
#include<stdio.h>
#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
};

/* Global varaibles base address of the linked list and linked list size */
Node* head;
int list_size = 0;


/* create Doubly linked list 
	* Time Complexity : O(N)
*/
void CreateDLL(int A[], int list_size)
{
    for (int i = 0 ; i < list_size ; i++)
        {   
            if (head == NULL)
            {
                Node* temp1 = new Node();
                temp1 -> data = A[i];
                //temp -> prev = NULL;
                temp1 -> next = head;
                head = temp1;
            }
            else
            {
                Node* temp = new Node();
                temp -> data = A[i];
                head->prev = temp;
                temp->next = head;
                head = temp;
            }
            
        }   
}

/* Traverse and print the data in the linked list 
	* Time Complexity : O(N)
*/
void print()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << '\n';
        temp = temp -> next;
    }
}

/* Insert node at nth position in Doubly Linked List 
	* Time Complexity : O(1) if list traversal is not considered
	* Space Complexity : O(N)
*/	
void InsertDLL(int position, int ElementToAdd)
{
    Node* temp = head;
    for (int i = 0 ; i < position - 1 ; i++)
    {
       temp = temp-> next;
    }

    Node* newnode = new Node();
    newnode -> data = ElementToAdd;
    newnode -> prev = temp; 
    newnode -> next = temp -> next;
    temp -> next -> prev = newnode;
    temp -> next = newnode;
}

/* Delete the node at nth position from the doubly linked list 
	* Time Complexity : O(1) if list traversal is not considered
	* Space Complexity : O(N)
*/
void DeleteDLL(int position)
{
    Node* temp = head;
    for (int i = 0 ; i < position - 1 ; i++)
    {
       temp = temp-> next;
    }
    temp -> next = temp -> next -> next;
    temp -> next -> prev = temp;
}

/* Reverse doubly linked list iterative approach
	* Time Complexity : O(N) 
	* Space Complexity : O(1)*/
void ReverseDLL()
{
    Node* current = head;
    Node* temp = NULL;

    while(current != NULL)
    {
        temp = current->prev; 
        current->prev = current->next; 
        current->next = temp; 
        // reversed the pointers, traverse backwards            
        current = current->prev; 

    }
    head = temp -> prev;
}


int main()
{
    /* Create a doubly linked list from the array*/
    int A[] = {1,3,5,7,9};
    list_size = (sizeof(A)/ sizeof (A[0]));
    CreateDLL(A, list_size);
    print();

    /* Insert a node at nth position */
    int ElementToAdd = 11;
    int position = 3;
    InsertDLL(position, ElementToAdd);
    print();

    /* Delete a node at nth position */
    DeleteDLL(position);
    print();

    /* Reverse the Doubly linked list */
    ReverseDLL();
    print();
}

