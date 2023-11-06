// GFG POTD 2023/10/15
// Normal BST to Balanced BST
// Easy

#include <bits/stdc++.h>
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

Node* insert(struct Node* node, int key) {
    if (node == NULL) return new Node(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

void preOrder(Node* node) {
    if (node == NULL)return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node* node)  {
  if (node==NULL) 
    return 0;
  int lDepth = height(node->left);
  int rDepth = height(node->right);
  if (lDepth > rDepth) 
    return(lDepth+1);
  else 
    return(rDepth+1);
}

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    void inorder(Node* root, vector<int>& arr) {
        if(root) {
            inorder(root->left, arr);
            arr.push_back(root->data);
            inorder(root->right, arr);
        }
    }
    
    Node* construct(vector<int>& arr, int l, int r) {
        if (l <= r) {
            int mid = (l + r) / 2;
            Node* curr = new Node(arr[mid]);
            
            curr->left = construct(arr, l, mid - 1);
            curr->right = construct(arr, mid + 1, r);
            
            return curr;
        }
        
        return NULL;
    }

    Node* buildBalancedTree(Node* root) {
        vector<int> arr;
        inorder(root, arr);
        
        int l = 0, r = arr.size() - 1;
        Node* res = construct(arr, l, r);
        
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while(t--) {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin, tree);
        root = buildTree(tree);

        Solution obj;
        root = obj.buildBalancedTree(root);
        cout << height(root) << endl;
    }

    return 0;
}

/* Sample Input:
2
30 20 N 10 N N N
4 3 N 2 N 1

Sample Output:
2
3

*/