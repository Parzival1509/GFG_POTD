// GFG POTD 2024/07/01
// Make Binary Tree From Linked List
// Medium

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

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void lvl(TreeNode* r) {
    if (r == NULL)
        return;
    queue<TreeNode*> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode* j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node** head) {
    Node* prev = NULL;
    Node* cur = *head;
    Node* nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

class Solution {
public:
    void convert(Node* head, TreeNode*& root) {
        if (head == NULL) {
            root = NULL;
            return;
        }

        queue<TreeNode*> q;
        root = new TreeNode(head->data);
        q.push(root);

        head = head->next;
        while (head) {
            TreeNode* par = q.front();
            q.pop();

            TreeNode *lft = NULL, *rgt = NULL;
            lft = new TreeNode(head->data);
            head = head->next;
            q.push(lft);
            if (head) {
                rgt = new TreeNode(head->data);
                head = head->next;
                q.push(rgt);
            }
            par->left = lft;
            par->right = rgt;
        }

        return;
    }
};

int main() {
    int T, i, n, l, k;
    cin >> T;
    while (T--) {
        struct Node* head = NULL;
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        Node* prevhead = head;
        TreeNode* root = NULL;
        Solution obj;

        obj.convert(head, root);
        if (root == NULL)
            cout << "-1\n";
        else if (root == NULL && prevhead != NULL)
            cout << "-1\n";
        else {
            lvl(root);
            cout << endl;
        }
        getchar();
    }

    return 0;
}

/* Sample Input
2
5
1 2 3 4 5
5
5 4 3 2 1

Sample Output
1 2 3 4 5 
5 4 3 2 1 

*/