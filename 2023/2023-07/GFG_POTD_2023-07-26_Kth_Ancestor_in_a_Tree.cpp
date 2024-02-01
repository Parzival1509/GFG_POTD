// GFG POTD 2023/07/26
// Kth Ancestor in a Tree
// Medium

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
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
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

int helper(Node *root, int k, int node, int &result) {
    if(root == NULL) return 0;
    if(root->data == node) return 1;
    
    int i = helper(root->left, k, node, result);
    int j = helper(root->right, k, node, result);
    int sum = i + j;
    if(sum == 0) return 0;
    
    if(k == sum && result == -1) result = root->data;
    return sum + 1;
}

int kthAncestor(Node *root, int k, int node) {
    int result = -1;
    helper(root, k, node, result);
    return result;
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t--) {
        int k , node;
        scanf("%d ", &k);
        scanf("%d ", &node);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        cout << kthAncestor(root, k, node) << endl;
    }
    return 0;
}

/* Sample Input:
2
2 4
1 2 3 4 5 N N
1 3
1 2 3

Sample Output:
1
1

*/