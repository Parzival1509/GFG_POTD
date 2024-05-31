// GFG POTD 2024/05/04
// Construct Binary Tree from Inorder and Postorder
// Medium

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);

    preOrder(node->left);
    preOrder(node->right);
}

class Solution {
public:
    Node* buildTree(int in[], int post[], int n) {
        if (n == 0)
            return NULL;

        int rootIndex = 0;
        while (rootIndex < n && in[rootIndex] != post[n - 1])
            rootIndex++;

        Node* root = new Node(post[n - 1]);

        Node* leftSubtree = buildTree(in, post, rootIndex);
        Node* rightSubtree = buildTree(in + rootIndex + 1, post + rootIndex, n - rootIndex - 1);

        root->left = leftSubtree;
        root->right = rightSubtree;

        return root;
    }
};

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
5
9 5 2 3 4
5 9 3 4 2
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1

Sample Output
2 9 5 4 3 
1 2 4 8 5 3 6 7 

*/