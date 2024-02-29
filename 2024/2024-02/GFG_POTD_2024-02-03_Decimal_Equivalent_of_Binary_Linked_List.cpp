// GFG POTD 2024/02/03
// Decimal Equivalent of Binary Linked List
// Easy

#include<bits/stdc++.h>
using namespace std;
const long long unsigned int MOD = 1000000007;

struct Node {
    bool data;
    struct Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    void solve(Node *head, long long unsigned int &ans) {
        if(head == NULL) return;
        
        ans = (ans * 2 + head->data) % MOD;
        solve(head->next, ans);
    }

    long long unsigned int decimalValue(Node *head) {
        long long unsigned int ans = 0;
        solve(head, ans);
        
        return ans;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data) {
    struct Node* new_node = new Node(new_data);    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);

int main() {
    bool l;
    int i, n, T;
    cin >> T;
    while(T--) {
        struct Node *head = NULL,  *tail = NULL;
        cin >> n;
        for(i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
        }
        Solution obj;
        cout << obj.decimalValue(head) << endl;
    }

    return 0;
}

/* Sample Input:
2
3
0 1 1
4
1 1 1 0

Sample Output:
3
14
    
*/