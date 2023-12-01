// GFG POTD 2023/11/17
// Binary Tree to CDLL
// Medium

#include <bits/stdc++.h>
using namespace std;

// Tree Node
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

void displayCList(Node *head) {
    Node *itr = head;
    do {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout << endl;

    itr = itr->left;
    head = itr;
    do {
        cout<<itr->data<<" ";
        itr=itr->left;
    } while(head!=itr);
    cout<<endl;
}

// Function to Build Tree
Node* buildTree(string str) {
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
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
    void InorderTravarsal(Node *root, vector<Node*> &nodes) {
        if(!root) return;
        
        InorderTravarsal(root->left, nodes);
        nodes.push_back(root);
        InorderTravarsal(root->right, nodes);
    }
    
    Node *bTreeToCList(Node *root) {
        vector<Node*>nodes;
        InorderTravarsal(root, nodes);
        if(nodes.size() == 0) return NULL;
        
        Node* result = nodes[0];
        int n = nodes.size();
        
        for(int i = 0; i < n; i++) {
            auto curr_node = nodes[i];
            
            if(i == 0) {
                if(n <= 1) continue;
                curr_node->right = nodes[i + 1];
                curr_node->left = nodes[n - 1];
            }
            else if(i == n - 1) {
                if(n <= 1) continue;
                curr_node->right = nodes[0];
                curr_node->left = nodes[i - 1];
            }
            else {
                curr_node->left = nodes[i - 1];
                curr_node->right = nodes[i + 1];
            }
        }
        
        return result;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        Node *head = obj.bTreeToCList(root);
        displayCList(head);
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
1 3 2
10 20 30 40 60

Sample Output:
3 1 2 
2 1 3 

40 20 60 10 30 
30 10 60 20 40 


*/