// GFG POTD 2023/01/10
// Transform to Sum Tree
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str) {   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N') return NULL;
    // Creating vector of strings from input 
    // string after spliting by space
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
        if(i >= ip.size()) break;
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

void inorder(Node * node) {
    if(node==NULL) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

class Solution {
public:
    int transform(Node *node) {
        if(node == NULL) return 0;
        int left = transform(node->left);
        int right = transform(node->right);
        int temp = node->data + left + right;
        node->data = left + right;
        return temp;
    }
    
    void toSumTree(Node *root) {
        transform(root);
    }
};

int main() {
    int t;
	scanf("%d ",&t);
    while(t--) {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        ob.toSumTree(root);
        inorder(root);
        cout<<endl;
    }
    return 1;
}

/* Sample Input
2
10 -2 6 8 -4 7 5
10 -2 6 8 -4 7 5 2 -2 3 -5 9 -8 2 8

Sample Output
0 4 0 20 0 12 0 
0 0 0 2 0 -2 0 29 0 1 0 23 0 10 0 

*/