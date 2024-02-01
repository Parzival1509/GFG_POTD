// GFG POTD 2023/01/18
// Find the First Node of Loop in Linked List
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if(position == 0) return;
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution {
public:
    Node* helper(Node* &head) {
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return fast;
        }
        return new Node(-1);
    }
    
    int findFirstNode(Node* head) {
        Node* fast = helper(head);
        if(fast->data == -1) return -1;
        Node* slow=head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    
    // // Using Map/Unordered Map
    // int findFirstNode(Node* head) {
    //     map<Node*, int> m1;
    //     Node* temp=head;
    //     m1[temp]++;
    //     while(temp->next != NULL) {
    //         temp = temp->next;
    //         if(m1[temp]) return temp->data;
    //         else m1[temp]++;
    //     }
    //     return -1;
    // }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, num;
        cin>>n;
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        for(int i=0 ; i<n-1 ; i++) {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
    return 0;
}

/* Sample Input
2
5
1 3 2 4 5
2
4
1 3 2 1
0

Sample Output
3
-1

*/