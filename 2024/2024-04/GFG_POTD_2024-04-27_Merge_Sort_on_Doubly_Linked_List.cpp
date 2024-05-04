// GFG POTD 2024/04/27
// Merge Sort on Doubly Linked List
// Medium

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    struct Node* sortDoubly(struct Node* head) {
        if (head == NULL)
            return head;
        Node* temp = head;
        vector<int> arr;
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        struct Node* newNode = new Node(arr[0]);
        struct Node* dummyHead = newNode;
        for (int i = 1; i < arr.size(); i++) {
            Node* temp_node = new Node(arr[i]);
            dummyHead->next = temp_node;
            temp_node->prev = dummyHead;
            dummyHead = temp_node;
        }
        return newNode;
    }
};

void insert(struct Node** head, int data) {
    struct Node* temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node* head) {
    struct Node* temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

void swap(int* A, int* B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node* head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
5
9 15 0 -1 0
8
7 3 5 2 6 4 1 8

Sample Output
-1 0 0 9 15 
15 9 0 0 -1 

1 2 3 4 5 6 7 8 
8 7 6 5 4 3 2 1 


*/