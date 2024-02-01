// GFG POTD 2023/10/08
// Insert in a Sorted List
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

void printList(Node* node) {
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
}

class Solution {
public:
    Node *sortedInsert(struct Node* head, int data) {
        Node* newNode = new Node(data);
        
        if(head->data >= data) {
            newNode->next = head;
            return newNode;
        }
        
        Node* tmp = head;
        Node* prev = NULL;
        
        while(tmp) {
            if(tmp->data >= data) 
                break;
            prev = tmp;
            tmp = tmp->next;
        }
        
        prev->next = newNode;
        newNode->next = tmp;
        
        return head;
    }
};

int main()  {
    int t;
    cin >> t;
    while(t--) {
        int n, data;
        cin >> n >> data;
        Node *head = new Node(data);
        Node *tail = head;
        for(int i = 0; i < n-1; ++i) {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        Solution obj;
        head = obj.sortedInsert(head, k);
        printList(head); 
    }

    return 0; 
} 

/* Sample Input:
2
6
25 36 47 58 69 80
19
2
1 3
2

Sample Output:
19 25 36 47 58 69 80 
1 2 3 

*/