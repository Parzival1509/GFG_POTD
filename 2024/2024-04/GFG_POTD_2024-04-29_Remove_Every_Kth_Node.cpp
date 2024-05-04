// GFG POTD 2024/04/29
// Remove Every Kth Node
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

void append(struct Node** head_ref, struct Node** tail_ref, int new_data) {
    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else (*tail_ref)->next = new_node;

    *tail_ref = new_node;
}

class Solution {
public:
    Node* deleteK(Node* head, int K) {
        if (K == 1) return NULL;
        
        int k = 1;
        Node* t = head;
        while (t != NULL && t->next != NULL && k++)
            if (k == K) {
                t->next = t->next->next;
                t = t->next;
                k = 1;
            }
            else t = t->next;
        
        return head;
    }
};

int main() {
    int T, i, l;
    cin >> T;
    while (T--) {
        int n, K;
        cin >> n >> K;
        struct Node *head = NULL, *tail = NULL;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
        }
        Solution obj;
        Node* res = obj.deleteK(head, K);
        Node* temp = res;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
8 2
1 2 3 4 5 6 7 8
10 3
1 2 3 4 5 6 7 8 9 10

Sample Output
1 3 5 7 
1 2 4 5 7 8 10 

*/