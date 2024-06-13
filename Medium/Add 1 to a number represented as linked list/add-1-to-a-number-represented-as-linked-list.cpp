//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

int recursion(Node* temp){
    if(temp==NULL){
        return 1;
    }
    int carry=recursion(temp->next);
    temp->data+=carry;
    if(temp->data>=10){
        temp->data=0;
        return 1;
    }
    else{
        return 0;
    }
}
class Solution
{
    public:
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        int carry=recursion(head);
        if(carry==1){
            Node* car=new Node(1);
            car->next=head;
            return car;
        }
        else{
            return head;
        }
        // return head of list after adding one
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends