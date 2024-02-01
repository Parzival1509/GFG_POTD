// GFG POTD 2023/05/28
// Nth Node from End of Linked List
// Easy

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int getNthFromLast(Node *head, int n) {
    int ct = 0;
    Node *tmp = head;
    while(tmp != NULL) {
        tmp = tmp->next;
        ct++;
    }
    
    ct -= n;
    if(ct < 0) return -1;
    
    tmp = head;
    while(ct) {
        tmp = tmp->next;
        ct--;
    }
    return tmp->data;
}

int main() {
    int T = 1, i, n, l, k;
    cin>>T;
    while(T--) {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i = 1; i < n; i++) {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}

/* Sample Input:
2
9 2
1 2 3 4 5 6 7 8 9
4 5
1 2 3 4

Sample Output:
8
-1

*/