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

class Solution {
public:
    Node* reverse(Node *head) {
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    Node* addOne(Node *head) {
        head = reverse(head);
        int carry = 1;
        Node *temp = head;
        Node *tail = NULL;
        while (temp != NULL) {
            if (temp->next == NULL) {
                tail = temp;
            }
            int totalSum = temp->data + carry;

            int digit = totalSum % 10;
            carry = totalSum / 10;
            temp->data = digit;
            temp = temp->next;
            if (carry == 0) {
                break;
            }
        }

        if (carry != 0) {
            Node *newNode = new Node(carry);
            newNode->next = NULL;
            tail->next = newNode;
        }

        head = reverse(head);

        return head;
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