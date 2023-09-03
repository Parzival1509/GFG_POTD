// GFG POTD 2023/06/27
// Union of Two Linked Lists
// Easy

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        set<int> st;
        while(head1) {
            st.insert(head1->data);
            head1 = head1->next;
        }
        while(head2) {
            st.insert(head2->data);
            head2 = head2->next;
        }
        Node* ans = new Node(0);
        Node* ptr = ans;
        for(auto i: st) {
            Node* tmp = new Node(i);
            ptr->next = tmp;
            ptr = tmp;
        }
        return ans->next;
    }
};

struct Node* buildList(int size) {
    int val;
    cin>> val;
    Node* head = new Node(val);
    Node* tail = head;
    for(int i = 0; i < size - 1; i++) {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n) {
    while(n) {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n;
        Node* first = buildList(n);
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first, second);
        printList(head);
    }
    return 0;
}

/* Sample Input:
2
6
9 6 4 2 3 8
5
1 2 8 6 2
6
1 5 1 2 2 5
5
4 5 6 7 1

Sample Output:
1 2 3 4 6 8 9 
1 2 4 5 6 7 

*/