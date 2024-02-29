// GFG POTD 2024/02/06
// Count the Nodes at Distance K from Leaves
// Medium

#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    bool heightK(Node* node, int k) {
        if(!node) return false;
        
        if(!node->left && !node->right)
            return (k == 0);
        
        if(heightK(node->left, k - 1) || heightK(node->right, k - 1))
            return true;
        
        return false;
    }
    
    int count(Node* root, int k) {
        if(!root) return 0;
        
        if(heightK(root, k))
            return 1 + count(root->left, k) + count(root->right, k);
        
        return count(root->left, k) + count(root->right, k);
    }
    
    int printKDistantfromLeaf(Node* root, int k) {
        return count(root, k);
    }
};

int main() {
    int T;
    scanf("%d ", &T);
    while(T--) {
        string s, ks;
        getline(cin, s);
        Node *root = buildTree(s);
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        cout << ob.printKDistantfromLeaf(root, k) << endl;
    }
    
    return 0;
}

/* Sample Input:
2
1 2 3 4 5 6 7 N N N N N 8
2
1 3 N 5 7 8 N N N 9
4

Sample Output:
2
1

*/