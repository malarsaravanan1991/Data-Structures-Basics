/* Implementation of stack from different data structures in C++ */

/* Stack - Array based Implementation using OOP concepts */

#include<stdio.h>
#include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;
#define MAX_SIZE 1000

/* linked list datastructure Node */

class Node
{
    public:
        int data;
        Node* next;
};
Node* head; //base address of the linked list


/* Stack Array based Implementation */
class stack
{
    private:
        int top;
        int A[MAX_SIZE];

    public:
        
        // Constructor
        stack()
        {
            top = -1;
        }

        /* Push the element into the stack and update top | Time : O(1)*/
        void push(int x)
        {
            if (top > MAX_SIZE-1)
            {
                cout << "Error: stack overflow" << '\n';
                return;
            }
            top = top + 1;
            A[top] = x;
        }

        /* Delete the element from the top of the stack | Time : O(1) */
        void pop()
        {
            int result = IsEmpty();
            if (result == 1)
            {
                cout << "Error: The stack is empty - no element to pop";
                return;
            }
            else
            {
                 --top;   
            }    
        }

        /* Check if the stack is empty or not */
        int IsEmpty()
        {
            if (top == -1)return 1;
            return 0;

        }

        /* Get the top element from the stack*/
        int Top()
        {
            if (top == -1) return 0;
            return A[top];
        }

        /* Print the stack elements */
        void print()
        {
            cout << "\n";
            for (int i =0; i <= top; i++)
            {
                cout << A[i] << ",";
            }
        }
};

/* function to create linked list */
void CreateLinkedList(int A[], int NumNodes)
{
    Node* result;
    for(int i = 0; i < NumNodes; i++)
    {
        result = new Node();
        result -> data = A[i];
        result ->next = head;
        head = result;
    }
    
}

/* Function to traverse linked list */

void LinkedListTraversal(Node* temp)
{   
    
    while(temp != NULL)
    {
        cout << "The values in the list is \t" << temp->data << "\n";
        temp = temp -> next;
    }
}


void ReverseLinkedList(int length)
{
    Node* temp = head;
    stack S;
    
    
    // push the data into the stack
    for (int i=0; i < length ; i++ )
    {
        S.push(temp -> data);
        temp = temp->next;

    }
     
    Node* temp1 = head;
    for (int i=0; i < length ; i++ )
    { 
        temp1 -> data = S.Top();
        temp1 = temp1 -> next;
        S.pop();
    }
}

int main()
{
    stack S;

    int A[] = {1,2,3,4,5};
    int a_size = (sizeof(A)/sizeof(A[0]));
    for (int i =0; i < a_size ; i++)
    {
        S.push(A[i]);
        S.print();
    }

    for (int i=0; i< a_size; i++)
    {
        S.pop();S.print();
    }

    /* Reverse linked list using stack */
    CreateLinkedList(A, a_size);
    LinkedListTraversal(head);

    ReverseLinkedList(a_size);
    LinkedListTraversal(head);
    
}


