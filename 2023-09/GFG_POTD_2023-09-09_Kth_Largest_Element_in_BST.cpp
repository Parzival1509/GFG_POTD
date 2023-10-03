// GFG POTD 2023/09/09
// Kth Largest Element in BST
// Easy

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
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
        if(currVal != "N") {
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
    int f(Node *root,int &k) {
        if(root == 0) return -1;
        
        int r = f(root->right, k);
        if(r != -1) return r;
        
        k--;
        if(k == 0) return root->data;
        
        int l = f(root->left, k);
        return l;
    }
    
    int kthLargest(Node *root, int K) {
        int ans = f(root, K);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while(t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);
        int k;
        cin >> k;
        getchar();
        Solution ob;
        cout << ob.kthLargest(head, k) << endl;
    }

    return 1;
}

/* Sample Input:
2
4 2 9
2
9 N 10
1

Sample Output:
4
10

*/