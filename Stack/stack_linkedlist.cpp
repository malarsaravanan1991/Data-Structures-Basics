/*  * Implement reverse linked list by stack
    * Implement balanced parantheses stack
    * Implment reverse string using stack 
*/

#include <stdio.h>
#include<iostream>
#include <stack>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

};
Node* head;  // Global variable to store the base address of the Linked List

/* Function to create linked list */
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
        cout << "The values in the list is \t" << temp -> data << "\n";
        temp = temp -> next;
    }
}

/* Function to reverse Linked list using Stack*/
void ReverseLinkedList_stack()
{
    Node* temp = head;
    //Declaring a Stack from Standard template library in C++ and datatype is linkedlist node
    stack<Node*> S;

    while (temp -> next!= NULL)
    {
        S.push(temp);
        temp = temp -> next;
    }

    head = temp; 
    while (!S.empty()) { 
        temp->next = S.top(); 
        temp = temp->next; 
        S.pop(); 
    }       
    temp->next = NULL; 
}

/* Function to reverse string using Stack */
char* ReverseString(char string[], int length)
{
    stack<char>S;
    for (int i=0 ; i<length; i++)
    {
        S.push(string[i]);
    }

    int i = 0;
    while (!S.empty())
    {
        string[i] = S.top();
        S.pop();
        i++;
    }
    return string;
}

// Function to check whether two characters are opening parantheses
// and closing of same type. 
bool ArePair(char open,char close)
{
	if(open == '(' && close == ')') return true;
	else if(open == '{' && close == '}') return true;
	else if(open == '[' && close == ']') return true;
	return false;
}

/* Function to Check if the parantheses are balanced or not */
bool CheckBalancedParantheses(char input[])
{
  int arr_size = sizeof(input)/sizeof(input[0]);
  stack<char> S;
  for (int i = 0; i < arr_size; i++)
  {
      // Push only for opening parantheses
      if (input[i] == '(' | input[i] == '[' | input[i] == '{')
      {
          S.push(input[i]);
      }
      else if (S.empty() & (input[i] == ')' | input[i] == ']' | input[i] == '}'))
      {
          return false;
      }
      else
      {
           bool checkpair = ArePair(S.top(),input[i]);
           if (checkpair == true) S.pop();
           else return false;
      }

  }
  return S.empty() ? true : false;
}

int main()
{
    /* Implement reverse linked list by stack */
    int A[] = {1,4,6,7,9};
    int arr_size = sizeof(A) / sizeof (A[0]);
    CreateLinkedList(A,arr_size);
    LinkedListTraversal(head);
    ReverseLinkedList_stack();

    /* Implement reverse string using stack*/
    char string[] = "Hello";
    ReverseString(string, strlen(string));
    cout << "Reversed string is " << string << '\n';  

    /* Implement balanced parantheses stack */
    // Check whether the input has balanced parantheses or not using stack

    char* input[] = {"[{}]",")(","[]{(}{}", "[", ")"};
    int input_size = sizeof(input)/sizeof(input[0]);
    std::cout << std::boolalpha;
    for (int i =0; i< input_size; i++)
    {
        bool result = CheckBalancedParantheses(input[i]);
        
        cout << "Are the parantheses for: " << input[i] << " Balanced or not: " << result << endl;
    }
}

