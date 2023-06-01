// GFG POTD 2023/05/23
// Construct a Full Binary Tree
// Medium

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

class Solution {
public:
    Node* solve(int pre[], int s, int e) {
        if(s > e) return NULL;
        if(s == e) return new Node(pre[s]);
      
        Node* root = new Node(pre[s]);
        int size = (e - s) / 2;
  
        root->left = solve(pre, s + 1, s + size);
        root->right = solve(pre, s + size + 1, e);
        return root;
    }
    
    Node* constructBinaryTree(int pre[], int preMirror[], int size) {
        Node* ans = solve(pre, 0, size - 1);
        return ans;
    }
};

void printInorder(Node* node) {
    if (node == NULL)return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int preOrder[n];
        int preOrderMirror[n];
        for(int i=0; i<n; i++) cin>>preOrder[i];
        for(int i=0; i<n; i++) cin>>preOrderMirror[i];
        Solution obj;
        printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
0 1 2
0 2 1
7
1 2 4 5 3 6 7
1 3 7 6 2 5 4

Sample Output:
1 0 2 
4 2 5 1 6 3 7 

*/