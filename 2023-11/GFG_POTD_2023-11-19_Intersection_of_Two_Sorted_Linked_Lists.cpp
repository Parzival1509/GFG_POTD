// GFG POTD 2023/11/19
// Intesection of Two Sorted Linked Lists
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* inputList(int size) {
    Node *head, *tail;
    int val;
    
    cin >> val;
    head = tail = new Node(val);
    
    while(--size) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n) {
    if(n) {
        while(n) {
            cout << n->data << " ";
            n = n->next;
        }
    }
    else cout << " ";
}

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node* head = NULL;
        Node* tail = NULL;
        
        if(head1 == NULL || head2 == NULL) return head;

        while(head1 != NULL && head2 != NULL) {
            if(head1->data == head2->data) {
                Node* tmp = new Node(head1->data);
                if(head == NULL) {
                    head = tmp;
                    tail = tmp;
                }
                else {
                    tail->next = tmp;
                    tail = tmp;
                }
                
                head1 = head1->next;
                head2 = head2->next;
            }
            else if(head1->data > head2->data)
                head2 = head2->next;
            else head1 = head1->next;
        }

        return head;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        Node* head1 = inputList(n);
        Node* head2 = inputList(m);
        
        Solution ob;
        Node* result = ob.findIntersection(head1, head2);
        
        printList(result);
        cout << endl;
    }

    return 0;
}


/* Sample Input:
2
5 4
1 2 3 4 6
2 4 6 8
4 2
10 20 40 50
15 20

Sample Output:
2 4 6 
20 

*/