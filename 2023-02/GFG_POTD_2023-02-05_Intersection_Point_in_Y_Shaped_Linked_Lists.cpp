// GFG POTD 2023/02/05
// Intersection Point in Y Shaped Linked Lists
// Medium

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

Node* inputList(int size) {
    if(size == 0) return NULL;

    int val;
    cin >> val;
    Node *head = new Node(val);
    Node *tail = head;

    for(int i=0; i<size - 1; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

class Solution {
public:
    int intersectPoint(Node* h1, Node* h2) {
        Node *p1 = h1, *p2 = h2;
        while(p1 || p2) {
            if(p1 == p2) return p1->data;
            if(p1 == NULL) p1 = h2;
            if(p2 == NULL) p2 = h1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return -1;
    }
};

int main() {
    int T, n1, n2, n3;
    cin >> T;
    while(T--) {
        cin >> n1 >> n2 >> n3;
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;
        if(temp != NULL) temp->next = common;

        temp = head2;
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;
        if(temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}

/* Sample Input:
2
3 1 2
3 6 9
10
15 30
2 3 3
4 1
5 6 1
8 4 5

Sample Output:
15
8

*/