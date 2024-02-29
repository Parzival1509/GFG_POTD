// GFG POTD 2024/02/05
// Sorted Insert for a Circular Linked List
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
    Node* sortedInsert(Node* head, int data) {
        Node* cur = head;
        Node* nhead = new Node(data);
        if (!head) {
            nhead->next = nhead;

            return nhead;
        } else if (head->data > data) {
            while (cur->next != head)
                cur = cur->next;
            nhead->next = cur->next;
            cur->next = nhead;

            return nhead;
        } else {
            while (cur->next != head && cur->next->data < data)
                cur = cur->next;
            nhead->next = cur->next;
            cur->next = nhead;
        }

        return head;
    }
};

void printList(struct Node* start) {
    struct Node* temp;
    if (start != NULL) {
        temp = start;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != start);
        printf("\n");
    }
}

int main() {
    int t, n, x;
    cin >> t;
    int arr;
    while (t--) {
        cin >> n >> x;
        int list_size, i;
        struct Node* start = NULL;
        struct Node *temp, *r;

        if (n > 0) {
            scanf("%d", &arr);
            temp = new Node(arr);
            start = temp;
            r = start;
        }

        for (i = 0; i < n - 1; i++) {
            scanf("%d", &arr);
            temp = new Node(arr);
            r->next = temp;
            r = r->next;
        }

        if (n > 0) temp->next = start;

        Solution ob;
        start = ob.sortedInsert(start, x);
        printList(start);
        r = start;
        while (r != start->next) {
            temp = start;
            start = start->next;
            free(temp);
        }
        free(start);
    }

    return 0;
}

/* Sample Input:
2
3 2
1 2 4
4 5
1 4 7 9

Sample Output:
1 2 2 4 
1 4 5 7 9 

*/