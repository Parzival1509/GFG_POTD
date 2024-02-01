// GFG POTD 2023/08/29
// Delete Nodes Having Greater Value on Right
// Medium

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

class Solution {
public:
    Node *reverse(Node *head) {
        Node *curr = head, *forward, *prev = NULL;
        
        while(curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    
    Node *compute(Node *head) {
        // // Approach 1: Without reversing
        // Node *tmp = head;
        
        // while(tmp->next != NULL) {
        //     if(tmp->next->data > tmp->data) {
        //         tmp->data = tmp->next->data;
        //         tmp->next = tmp->next->next;
        //         tmp = head;
        //     }
        //     else tmp = tmp->next;
        // }
        
        // Approach 2: By reversing the List
        Node *rHead = reverse(head);
        Node *tmp = rHead;
        
        while(tmp->next != NULL) {
            if(tmp->next->data < tmp->data)
                tmp->next = tmp->next->next;
            else tmp = tmp->next;
        }
        
        head = reverse(rHead);
        return head;
    }
};

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

        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
8
12 15 10 11 5 6 2 3
6
1 2 3 4 5 6

Sample Output:
15 11 6 3 
6 

*/