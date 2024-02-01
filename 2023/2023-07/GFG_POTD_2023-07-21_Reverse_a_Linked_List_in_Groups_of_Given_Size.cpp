// GFG POTD 2023/07/21
// Reverse a Linked List in Groups of Given Size
// Medium

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;
    
    node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution {
public:
    node *reverse (node *head, int k) { 
        if(head == NULL || k == 1) return head;
        
        node *dummy = new node(0);
        dummy->next = head;
        node *prev = dummy, *curr = dummy, *nxt = dummy;
        int ct = 0;   
        node *temp = head;
        while(temp != NULL) {
            ct++;
            temp = temp->next;
        }
        
        while(ct > 0) {
            curr = prev->next;
            nxt = curr->next;
            for(int i = 1; i < k && i < ct; i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            ct -= k;
        }
        
        return dummy->next;
    }
};

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if(i == 0) {
                head = new node(value);
                temp = head;
            }
            else {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


/* Sample Input:
2
8 4
1 2 3 4 5 6 7 8
5 3
1 2 3 4 5

Sample Output:
4 3 2 1 8 7 6 5 
3 2 1 5 4 

*/