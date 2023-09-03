// GFG POTD 2023/08/30
// Delete a Node in Single Linked List
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

Node* deleteNode(Node *head, int x) {
    if(x == 1) return head->next;
    
    Node *tmp = head, *prev = NULL;
    while(--x) {
        prev = tmp;
        tmp = tmp->next;
    }
    
    prev->next = tmp->next;
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

        int x;
        cin >> x;
        Node *result = deleteNode(head, x);
        print(result);
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

4
1 6 3 9
1

4
1 6 3 9
2

Sample Output:
6 3 9 
1 3 9 

*/