//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
          if(*head == nullptr || (*head)->next == nullptr) {
            return;
        }
         Node *forwardConcatenationHead = *head;
         Node *forwardConcatenation = forwardConcatenationHead;
         Node *currentPosition = forwardConcatenation->next;
         Node *reverseConcatenation = nullptr;
         bool lowValue = false;
         while(currentPosition != nullptr) {
             Node *temp = currentPosition->next;
             if(lowValue == true) {
                 forwardConcatenation->next = currentPosition;
                 forwardConcatenation = forwardConcatenation->next;
             } else {
                 currentPosition->next = reverseConcatenation;
                 reverseConcatenation = currentPosition;
             }
             lowValue = !lowValue;
             currentPosition = temp;
         }
         forwardConcatenation->next = nullptr;
         //sort the two resulting linked lists
         Node *it = *head;
         if(reverseConcatenation->data < it->data) {
             int temp =reverseConcatenation->data;
             reverseConcatenation->data = it->data;
             it->data = temp;
         }
         while(reverseConcatenation != nullptr) {
             int data = reverseConcatenation->data;
             while(it->next != nullptr && it->next->data < data) {
                 it = it->next;
             }
             //insert in list
             Node *temp = reverseConcatenation->next;
             reverseConcatenation->next = it->next;
             it->next = reverseConcatenation;
             reverseConcatenation = temp;
         }
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends