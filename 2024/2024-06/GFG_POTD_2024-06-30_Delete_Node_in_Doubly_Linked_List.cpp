// GFG POTD 2024/06/30
// Delete Node in Doubly Linked List
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if (head == nullptr || x <= 0)
            return head;

        Node* curr = head;
        if (x == 1) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete curr;

            return head;
        }

        for (int i = 1; curr != nullptr && i < x - 1; i++)
            curr = curr->next;

        if (curr == nullptr || curr->next == nullptr)
            return head;

        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        
        if (toDelete->next != nullptr)
            toDelete->next->prev = curr;

        delete toDelete;

        return head;
    }
};

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int t, x, n, i;
    scanf("%d", &t);
    while (t--) {
        struct Node *temp, *head = NULL;
        scanf("%d", &n);
        temp = NULL;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);
        Solution ob;
        head = ob.deleteNode(head, x);
        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        free(head);
    }

    return 0;
}

/* Sample Input
2
3
1 3 4
3
4
1 5 2 9
1

Sample Output
1 3 
5 2 9 

*/