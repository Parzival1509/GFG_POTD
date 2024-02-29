// GFG POTD 2024/02/18
// Sum of Leaf Nodes in BST
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* r, int num);

class Solution {
public:
    void preorder(Node* node, int& ans) {
        if (!node) return;

        if (node->right == NULL && node->left == NULL) {
            ans += node->data;
            return;
        }

        preorder(node->right, ans);
        preorder(node->left, ans);
    }

    int sumOfLeafNodes(Node* root) {
        int sum = 0;

        // // Approach 1: S.C. = O(H)
        // preorder(root, sum);

        // Approach 2: Morris Traversal
        // S.C. = O(1)

        while (root) {
            if (root->left == NULL) {
                if (root->right == NULL)
                    sum += root->data;
                root = root->right;
            } else {
                Node* current = root->left;
                while (current->right && current->right != root)
                    current = current->right;

                if (current->right == root) {
                    current->right = NULL;
                    if (current->left == NULL)
                        sum += current->data;
                    root = root->right;
                } else {
                    current->right = root;
                    root = root->left;
                }
            }
        }

        return sum;
    }
};

int main(void) {
    int t, n, data;
    scanf("%d", &t);
    while (t--) {
        Node* root = NULL;
        scanf("%d", &n);
        // printf("n=%d\n",n);
        while (n--) {
            scanf("%d", &data);
            // printf("data=%d\n",data);
            root = insert(root, data);
        }
        // inOrderDisplay(root);
        Solution obj;
        printf("%d\n", obj.sumOfLeafNodes(root));
    }

    return 0;
}

Node* insert(Node* r, int num) {
    if (r == NULL)
        r = new Node(num);
    else {
        if (num < r->data)
            r->left = insert(r->left, num);
        else r->right = insert(r->right, num);
    }

    return r;
}

void preOrderDisplay(Node* r) {
    if (r != NULL) {
        printf("%d ", r->data);
        preOrderDisplay(r->left);
        preOrderDisplay(r->right);
    }
}

void inOrderDisplay(Node* r) {
    if (r != NULL) {
        inOrderDisplay(r->left);
        printf("%d ", r->data);
        inOrderDisplay(r->right);
    }
}

void postOrderDisplay(Node* r) {
    if (r != NULL) {
        postOrderDisplay(r->left);
        postOrderDisplay(r->right);
        printf("%d ", r->data);
    }
}

int search(Node* r, int num) {
    if (r == NULL) return 0;
    if (r->data == num) return 0;
    
    if (r->data > num)
        search(r->left, num);
    else search(r->right, num);
}

/* Sample Input:
2
1
45
6
67 34 82 12 45 78

Sample Output:
45
135

*/