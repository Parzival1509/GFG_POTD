// GFG POTD 2024/03/16
// Delete Without Head Pointer
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
}* head;

Node* findNode(Node* head, int search_for) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}

void insert() {
    int n, i, value;
    Node* temp;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

class Solution {
public:
    void deleteNode(Node* del_node) {
        Node* temp = del_node->next;
        del_node->data = del_node->next->data;
        del_node->next = del_node->next->next;
        delete (temp);
    }
};

int main(void) {
    int t, k, n, value;
    scanf("%d", &t);
    while (t--) {
        insert();
        scanf("%d", &k);
        Node* del = findNode(head, k);
        Solution ob;
        if (del != NULL && del->next != NULL)
            ob.deleteNode(del);
        printList(head);
    }
    return (0);
}

/* Sample Input
2
2
1 2
1
4
10 20 4 30
20

Sample Output
2 
10 4 30 

*/