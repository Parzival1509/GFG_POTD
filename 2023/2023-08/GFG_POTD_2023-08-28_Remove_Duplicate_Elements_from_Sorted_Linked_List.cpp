// GFG POTD 2023/08/28
// Remove Duplicate Elements from Sorted Linked List
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


void print(Node *root) {
    Node *temp = root;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *removeDuplicates(Node *head) {
    Node *tmp = head->next, *tail = head;
    while(tmp) {
        if(tail->data != tmp->data) {
            tail->next = tmp;
            tail = tail->next;
        }
        tmp = tmp->next;
    }
    tail->next = NULL;
    
    return head;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int K;
        cin >> K;
        Node *head = NULL;
        Node *temp = head;

        for(int i = 0; i < K; i++) {
            int data;
            cin >> data;
            if(head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        
        Node *result = removeDuplicates(head);
        print(result);
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
4
1 2 3 4
8
1 1 2 2 3 3 4 4
8
1 1 2 2 3 3 4 5

Sample Output:
1 2 3 4 
1 2 3 4 
1 2 3 4 5 

*/