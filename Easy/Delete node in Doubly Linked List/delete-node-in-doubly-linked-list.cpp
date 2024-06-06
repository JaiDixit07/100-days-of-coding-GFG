//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

class Solution
{
    public:
    Node* deleteNode(Node *head, int x)
    {
        // Check if the list is empty
        if(head == NULL) {
            return NULL;
        }

        // If the head node needs to be deleted
        if(x == 1) {
            Node* temp = head;
            head = head->next;
            if(head) {
                head->prev = NULL;
            }
            delete temp;
            return head;
        }

        // Initialize pointers to traverse the list
        Node* current = head;
        int cnt = 1;

        // Traverse to the x-th node
        while(current && cnt < x) {
            current = current->next;
            cnt++;
        }

        // If the x-th node is found
        if(current) {
            Node* prev = current->prev;
            Node* next = current->next;

            if(prev) {
                prev->next = next;
            }
            if(next) {
                next->prev = prev;
            }

            delete current;
        }

        return head;
    }
};

// class Solution
// {
//     public:
//     Node* deleteNode(Node *head, int x)
//     {
//       //Your code here
//       if(head==NULL){
//           return NULL;
//       }
//       if(x==1){
//           Node*temp=head;
//           head=head->next;
//           if(head){head->prev=nullptr;}
//           temp->next=nullptr;
//           delete temp;
//           return head;
//       }
//       int cnt=1 ;
//       Node* current=head;
//       Node* prev=NULL;
//       Node* next=current->next;
//           while(current ){
//             if(cnt==x){
//                 prev->next=next;
//                 next->prev=current;
//                 current->prev=nullptr;
//                 current->next=nullptr;
//                 delete current;
//                 break; 
//             }
//             cnt++;
//             prev=current;
//             current=current->next;
//             next=current->next;
              
//           }
//       return head;
//     }
// };


//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node)
{
  while(node!=NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
   printf("\n");
}
 
/* Drier program to test above functions*/
int main()
{
  int t, x, n, i;
  scanf("%d",&t);
  
  while(t--)
  {
      /* Start with the empty list */
      struct Node *temp,*head = NULL;
      scanf("%d",&n);
      
      temp = NULL;
      
      for(i=0;i<n;i++){
        scanf("%d",&x);
        
        if(head == NULL){
            head = new Node(x);
            temp = head;
        }
        else{
            Node *temp1 = new Node(x);
            temp->next = temp1;
            temp1->prev = temp;
            temp = temp->next;
        }
      }
  
    scanf("%d",&x);
      
    Solution ob;  
    head = ob.deleteNode(head,x); 
      
        
        printList(head);           
        while(head->next!=NULL)
        {
    	    temp=head;
    	    head=head->next;
    	    free(temp);
    	}
    	
    	free(head);
	}
	return 0;
}

// } Driver Code Ends