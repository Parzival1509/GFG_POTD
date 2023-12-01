// GFG POTD 2023/12/01
// Check Whether BST Contains Dead End
// Easy

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node ** tree, int val) {
    Node *temp = NULL;
    if(!(*tree)) { 
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
        insert(&(*tree)->left, val);
    else if(val > (*tree)->data)
        insert(&(*tree)->right, val);
}

int getCountOfNode(Node *root, int l, int h) {
    if(!root) return 0;

    if(root->data == h && root->data == l)
        return 1;

    if(root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);

    if(root->data < l)
         return getCountOfNode(root->right, l, h);

    return getCountOfNode(root->left, l, h);
}

class Solution {
public:
    vector<int> arr, leaf;
    
    void inorder(Node* node) {
        if(!node) return;
        
        inorder(node->left);
        arr.push_back(node->data);
        if(!node->left && !node->right)
            leaf.push_back(node->data);
        inorder(node->right);
    }
    
    bool isDeadEnd(Node *root) {
        arr = {0}; 
        leaf = {};
        inorder(root);
        
        int j = 0;
        for(int i = 1; i < arr.size() && j < leaf.size(); ++i)
            if(arr[i] == leaf[j]) {
                if(arr[i-1] == leaf[j] - 1 && arr[i+1] == leaf[j] + 1)
                    return true;
                
                ++j;
            }
        
        return false;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        Node *root, *tmp;
        root = NULL;

        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
            int k;
            cin >> k;
            insert(&root, k);
        }

        Solution ob;
        cout << ob.isDeadEnd(root) << endl;
    }
}

/* Sample Input:
2
6
8 5 9 7 2 1
6
8 7 10 2 9 13

Sample Output:
1
1

*/