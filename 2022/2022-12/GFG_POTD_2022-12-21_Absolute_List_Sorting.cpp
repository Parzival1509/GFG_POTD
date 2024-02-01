// GFG POTD 2022/12/21
// Absolute List Sorting
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* next;
    int data;
};

// Utility function to insert a node at the beginning
void push(Node** head, int data) {
    Node* newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head) {
    while(head != NULL) {
        cout << head->data;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* sortList(Node* head) {
        Node* tmp = head;
        while(tmp->next != NULL)
            if(tmp->next->data < 0) {
                Node* temp = tmp->next->next;
                tmp->next->next = head;
                head = tmp->next;
                tmp->next = temp;
            }
            else tmp = tmp->next;
        return head;
    }
};

int main() {
    int t = 0;
    int n = 0;
    cin >> t;
    while(t--) {
        Node* head = NULL;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            // push(&head, a);
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, arr[i]);
        }
        // printList(head);
        Solution ob;
        head = ob.sortList(head);
        printList(head);
    }
    return 0;
}

/* Sample Input
2
2
5 -10
5
1 -2 3 4 -5

Sample Output
-10 5
-5 -2 1 3 4

*/