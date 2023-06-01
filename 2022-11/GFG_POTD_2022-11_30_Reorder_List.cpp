// GFG POTD 2022/11/30
// Add Binary Strings
// Hard

#include<bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution{ 
public:
    // C++ easy solution in TC = O(N) and SC = O(1) 
    Node* reverse(Node* head){
        Node* prev=NULL, *curr=head;
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(Node* head) {
        if(head->next == NULL || head->next->next == NULL)
            return;
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* second = slow->next;
        slow->next = NULL;
        second = reverse(second);
        Node* first = head;
        while(first != NULL && second != NULL) {
            Node* firstNext = first->next;
            first->next = second;
            first = firstNext;
            Node* secondNext = second->next;
            second->next = first;
            second = secondNext;
        }
    }
    
    // // C++ Solution using deque T.C O(N) and S.C O(N)
    // void reorderList(Node* head) {
    //     deque<int> q;
    //     Node*temp=head;
    //     while(temp) {
    //         q.push_back(temp->data);
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     int i=1;
    //     while(temp) {
    //         if(i%2==0) {
    //             temp->data=q.back();
    //             q.pop_back();
    //         }
    //         else {
    //             temp->data=q.front();
    //             q.pop_front();
    //         }
    //         i++;
    //         temp=temp->next;
    //     }
    // }
};

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while(t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for(i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        Solution ob;
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

/* Sample Input
2
3
1 2 3
4
1 7 3 4

Sample Output
1 3 2 
1 4 7 3 

*/