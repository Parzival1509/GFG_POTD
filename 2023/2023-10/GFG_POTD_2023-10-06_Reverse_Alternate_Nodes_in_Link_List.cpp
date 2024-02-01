// GFG POTD 2023/10/06
// Reverse Alternate Nodes in Link List
// Medium

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
    
}

void insert() {
    int n, value;
    cin >> n;
    struct Node *temp;
    for(int i = 0;i < n; i++) {
        cin >> value;
        if(i == 0) {
            start = new Node(value);
            temp = start;
        }
        else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

class Solution {
public:
    Node* reverseList(Node* head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr) {
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }

    void rearrange(Node *odd) {
        if(odd == NULL || odd->next == NULL) return;
        
        Node* tail = odd;
        Node* even = new Node(-1);
        Node* evenT = even;
        
        int i = 0;
        Node* tmp = odd->next;
        
        while(tmp != NULL) {
            Node* newNode = new Node(tmp->data);
            
            if(i % 2 == 0) {
                evenT->next = newNode;
                evenT = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            
            i++;
            tmp = tmp->next;
        }
        
        even = reverseList(even->next);
        tail->next = even;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }

    return 0;
}

/* Sample Input:
3
5
1 2 3 4 5
8
10 4 9 1 3 5 9 4
9
8 8 9 4 9 7 9 6 7

Sample Output:
1 3 5 4 2 
10 9 3 9 4 5 1 4 
8 9 9 9 7 6 7 4 8 

*/