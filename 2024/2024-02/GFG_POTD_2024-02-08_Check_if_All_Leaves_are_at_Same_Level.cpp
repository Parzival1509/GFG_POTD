// GFG POTD 2024/02/08
// Check if All Leaves are at Same Level
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
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
    int val = -1;

    bool check(Node *root, int level = 0) {
        if(root == NULL) return true;
        
        if((root->left == NULL) && (root->right == NULL)) {
            if(val == -1) val = level;
            else return (val == level);
        }
        
        if(check(root->left, level + 1) == false) return false;
        if(check(root->right, level + 1) == false) return false;
        
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);
        Solution obj;
        cout << obj.check(head) << endl;
    }

    return 0;
}

/* Sample Input:
2
1 2 3
10 20 30 10 15

Sample Output:
1
0

*/