// GFG POTD 2023/07/23
// Given a Linked List of 0s, 1s and 2s, Sort It
// Easy

#include <bits/stdc++.h>
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

class Solution {
public:
    Node* segregate(Node *head) {
        if(head == NULL || head->next == NULL) return head;
        
        Node *head0, *head1, *head2, *tail0, *tail1, *tail2;
        head0 = head1 = head2 = tail0 = tail1 = tail2 = NULL;
        
        Node* curr = head;
        
        while(curr != NULL) {
            int val = curr->data;
            
            if(val == 0) {
                if(head0 == NULL)
                    head0 = tail0 = curr;
                else {
                    tail0->next = curr;
                    tail0 = tail0->next;
                }
            }
            else if(val == 1) {
                if(head1 == NULL)
                    head1 = tail1 = curr;
                else {
                    tail1->next = curr;
                    tail1 = tail1->next;
                }
            }
            
            else if(val == 2) {
                if(head2 == NULL)
                    head2 = tail2 = curr;
                else {
                    tail2->next = curr;
                    tail2 = tail2->next;
                }
            }
            
            curr = curr->next;
        }
        
        if(tail0 != NULL) tail0->next = NULL;
            
        if(tail1 != NULL) tail1->next = NULL;
            
        if(tail2 != NULL) tail2->next = NULL;
        
        if(head0 == NULL && head1 == NULL) return head2;
        else if(head1 == NULL && head2 == NULL) return head0;
        else if(head0 == NULL && head2 == NULL) return head1;
        
        else if(head0 == NULL) {
            tail1->next = head2;
            return head1;
        }
        else if(head1 == NULL) {
            tail0->next = head2;
            return head0;
        }
        else if(head2 == NULL) {
            tail0->next = head1;
            return head0;
        }
        
        tail0->next = head1;
        tail1->next = head2;
        return head0;
    }
};

void printList(struct Node *Node) {
    while (Node != NULL) {
        cout << Node->data << ' ';
        Node = Node->next;
    }
    cout << endl;
}

void insert(int n1) {
    int n, value, i;
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        cin >> value;

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        }
        else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }
    return 0;
}

/* Sample Input:
2
8
1 2 2 1 2 0 2 2
4
2 2 0 1

Sample Output:
0 1 1 2 2 2 2 2 
0 1 2 2 

*/