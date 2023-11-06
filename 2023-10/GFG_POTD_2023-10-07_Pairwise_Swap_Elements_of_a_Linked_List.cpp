// GFG POTD 2023/10/07
// Pairwise Swap Elements of a Linked List
// Easy

#include <bits/stdc++.h> 
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
    Node* solve(Node* head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        Node* a = head;
        Node* b = a->next;
        Node* c = b->next;
        
        b->next = a;
        a->next = solve(c);
        
        return b;
    }

    Node* pairWiseSwap(Node* head) {
        head = solve(head);
        return head;
    }
};

void printList(Node* node) {
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, data;
        cin >> n >> data;
        Node *head = new Node(data);
        Node *tail = head;
        map<Node*, int> mp;
        mp[head] = head->data;

        for(int i = 0; i < n - 1; ++i) {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
            mp[tail] = tail->data;
        }

        Node *failure = new Node(-1);
        Solution ob;
        head = ob.pairWiseSwap(head);
        int flag = 0;
        Node *temp = head;

        while(temp) {
            if(mp[temp] != temp->data) {
                flag = 1;
                break;
            }
            temp = temp->next;
        }

        if(flag) printList(failure);
        else printList(head);
    }
    return 0; 
}

/* Sample Input:
2
8
1 2 2 4 5 6 7 8
7
1 3 4 7 9 10 1

Sample Output:
2 1 4 2 6 5 8 7 
3 1 7 4 10 9 1 

*/