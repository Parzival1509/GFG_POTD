// GFG POTD 2024/01/20
// Distribute Candies in a Binary Tree
// Hard

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
        // Get the current node's value from the string
        string currVal = ip[i];
        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    int moves;
    
    int solve(Node* root) {
        if(root == NULL) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        moves += (abs(l) + abs(r));
    
        return (l + r + root->key) - 1;
    }
    
    int distributeCandy(Node* root) {
        moves = 0;
        solve(root);
        
        return moves;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        cout << ob.distributeCandy(root) << "\n";
    }

    return 0;
}

/* Sample Input:
4
6
-1 2 2 -1 0 0
8
1 0 4 2 0 6 2 4
9
2 3 4 -1 2 0 0 -1 0
9
2 3 4 -1 0 0 0 0 0

Sample Output:
2
1
-1
3

*/