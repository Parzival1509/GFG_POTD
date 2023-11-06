// GFG POTD 2023/10/13
// Floor in BST
// Medium

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

class Solution {
public:
    int floor(Node* root, int x) {
        int ans = -1;
        if(root == NULL) return ans;
        
        while(root) {
            if(root->data == x) return x;
            
            if(root->data < x) {
                ans = root->data;
                root = root->right;
            }
            else root = root->left;
        }
        
        return ans;
    }
};

Node* insert(Node *tree, int val) {
    Node *temp = NULL;
    if(tree == NULL) return new Node(val);

    if(val < tree->data)
        tree->left = insert(tree->left, val);
    else if (val > tree->data)
        tree->right = insert(tree->right, val);

    return tree;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        Node *root = NULL;
        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }
        int x;
        cin >> x;
        Solution obj;
        cout << obj.floor(root, x) << "\n";
    }
}

/* Sample Input:
2
7
2 81 87 42 66 90 45
87
4
6 8 7 9
11

Sample Output:
87
9

*/