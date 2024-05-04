// GFG POTD 2024/04/28
// Delete Middle of Linked List
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
    Node* deleteMid(Node* head) {
        Node *s = head, *f = head, *p = NULL;

        while (f and f->next) {
            p = s;
            s = s->next;
            f = f->next->next;
        }

        p->next = s->next;
        return head;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, data;
        cin >> n >> data;
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 0; i < n - 1; ++i) {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution obj;
        head = obj.deleteMid(head);
        printList(head);
    }
    return 0;
}

/* Sample Input
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Sample Output
1 2 4 5 
2 4 6 5 1 

*/