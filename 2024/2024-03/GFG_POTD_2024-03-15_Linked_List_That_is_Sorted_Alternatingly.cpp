// GFG POTD 2024/03/15
// Linked List That is Sorted Alternatingly
// Medium

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

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);
    struct Node* last = *headRef;
    if (*headRef == NULL) {
        *headRef = new_node;
        *tailRef = *headRef;
        return;
    }

    (*tailRef)->next = new_node;
    *tailRef = (*tailRef)->next;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    void sort(Node** head) {
        if (head == nullptr || *head == nullptr)
            return;

        vector<int> dataVector;
        Node* curr = *head;
        while (curr != nullptr) {
            dataVector.push_back(curr->data);
            curr = curr->next;
        }

        std::sort(dataVector.begin(), dataVector.end());

        curr = *head;
        for (int i = 0; i < dataVector.size(); ++i) {
            curr->data = dataVector[i];
            curr = curr->next;
        }
    }
};

int main() {
    int test;
    cin >> test;
    while (test--) {
        struct Node* head = NULL;
        struct Node* tail = NULL;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            append(&head, &tail, k);
        }
        Solution ob;
        ob.sort(&head);
        printList(head);
    }
    return 0;
}

/* Sample Input
2
6
1 9 2 8 3 7
5
13 99 21 80 50

Sample Output
1 2 3 7 8 9 
13 21 50 80 99 

*/