#include<stdio.h>
#include<iostream>
#include<assert.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

/* Global variable that stores the base address of the list */
Node* head;
int list_size = 0;

/* Function to create linked list 
	* Time complexity : O(N)
	* Space complextiy : O(N)
*/
Node* CreateLinkedList(int A[], int NumNodes)
{
    Node* result;
    for(int i = 0; i < NumNodes; i++)
    {
        result = new Node();
        result -> data = A[i];
        result ->next = head;
        head = result;
    }
    return result;
}

/* Function to traverse linked list 
	* Time complexity : O(N)
	* Space complextiy : O(N)*/

void LinkedListTraversal()

{   
    Node* temp = head;
    while(temp -> next != NULL)
    {
        cout << "The values in the list is \t" << temp->data << "\n";
        temp = temp -> next;
    }
}

/* Function to insert a node to linked list 
   * Time complexity : O(1) without considering link traversal
   * Space complextiy : O(N)
*/
void InsertNodeLinkedList(int ElementToAdd, int position)
{
    Node* result = head;
    Node* temp = new Node();
    temp -> data = ElementToAdd;
    temp -> next = NULL;
    assert((position < list_size) && (position >=0));
    if (position == 0)
    {
        temp -> next = head;
        head = temp;
        return;
    }   
    // First traverse to the position
    for (int i = 0; i < position - 1; i++)
    {
        result = result-> next;
    }
    temp -> next = result -> next;
    result -> next = temp;
}

/* Function to delete a node from existing linked list 
	* Time complexity : O(1) without considering link traversal
	* Space complextiy : O(N)*/

void DeleteNodeLinkedList (int position)
{
    assert(head != NULL);
    assert((position < list_size) && (position >=0));
    Node* result = head;
    //Traverse to the position in the linked list
    for (int i =0; i < position - 1; i++)
    {
        result = result -> next;
    }
    result -> next = result -> next -> next;
}

/*Reverse the given linked List 
	* Time complexity : O(N) 
    * Space complextiy : O(1)- inplace approach*/

void ReverseLinkedList()
{
   Node* current = head;
   Node* prev = NULL;
   Node* next;
   while ( current != NULL)
   {
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
    
   }
   head = prev;
}

/* Implementation of reverse LinkedList using recursion 
	* Time complexity : O(N) without considering link traversal
    * Space complextiy : O(N) - implicit stack
*/
void ReverseLinkedListRecursion(Node* temp)
{
    if (temp -> next == NULL)
    {
        head = temp;
        return;
    }
    ReverseLinkedListRecursion(temp->next);
    Node* temp1 = temp -> next;
    temp1 -> next = temp;
    temp -> next = NULL;

}

int main()
{
  
  /* Create linked list */
  head = NULL;
  int A[] = {1,3,5,7,9};
  list_size = sizeof(A) / sizeof(A[0]);
  head = CreateLinkedList(A, list_size);

  /* Linked List traversal */
  LinkedListTraversal();

  /* Insert a Node to a linked list at nth position */
  int position = 3;
  int ElementToAdd = 11;
  InsertNodeLinkedList(ElementToAdd, position);
  list_size ++;

  /* Delete a Node from the linked list at nth position */
  DeleteNodeLinkedList(position); 

  /* Reverse the Linked list using iterative method and recursion */ 
  ReverseLinkedList(); 
  Node* temp = head;
  ReverseLinkedListRecursion(temp);

}
