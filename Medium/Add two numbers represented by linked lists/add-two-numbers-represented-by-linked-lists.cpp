//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    struct Node* reverseList(struct Node* head) {
        Node* newHead = NULL;
        Node* currNode;
        
        while(head != NULL) {
            currNode = head->next;
            head->next = newHead;
            newHead = head;
            head = currNode;
        }
        
        return newHead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* revSumHead = new Node(0);
        Node* temp = revSumHead;
        
        Node *temp1 = reverseList(first), *temp2 = reverseList(second);
        
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL || carry) {
            int sum = 0;
            
            if(temp1 != NULL) {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            
            if(temp2 != NULL) {
                sum += temp2->data;
                temp2 = temp2->next;
            }
            
            sum += carry;
            carry = sum/10;
            
            Node* newNode = new Node(sum % 10);
            temp->next = newNode;
            temp = temp->next;
        }

        Node* head = reverseList(revSumHead->next);
        while (head->data == 0 && head->next != NULL) {
            head = head->next;
        }
        
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
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends