// GFG POTD 2023/11/18
// Reverse a Doubly Linked List
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node * prev;
    Node (int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *newNode(int data) {
    Node *temp = new Node(data);
    return temp;
}

void displayList(Node *head) {
    while(head->next) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
}

int getLength(Node * head) {
    Node *temp = head;
    int count = 0;
    
    while(temp->next != head) {
        count++;
        temp = temp->next;
    }

    return count + 1;
}

bool verify(Node* head) {
    int fl = 0, bl = 0;
    Node *temp = head;
    
    while(temp->next) {
        temp = temp->next;
        fl++;
    }
    
    while(temp->prev) {
        temp = temp->prev;
        bl++;
    }
    
    return fl == bl;
}

class Solution {
public:
    Node* reverseDLL(Node * head) {
        Node* curr;
        while(head) {
            swap(head->next, head->prev);
            curr = head;
            head = head->prev;
        }
        
        return curr;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin >> n >> x;

        Node *head = NULL, *tail = NULL;
        head = newNode(x);
        tail = head;
        
        for(int i = 0; i < n - 1; i++) {
            cin >> x;
            Node* temp = newNode(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        Solution ob;
        head = ob.reverseDLL(head);

        if(verify(head)) displayList(head);
        else cout << "Your pointers are not correctly connected";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
3
3 4 5
5
1 2 3 4 5

Sample Output:
5 4 3
5 4 3 2 1

*/