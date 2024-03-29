// GFG POTD 2023/09/01
// Leftmost and Rightmost Nodes of Binary Tree
// Medium

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

void printCorner(Node *root);

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

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--) {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        printCorner(root);
        cout<<endl;
    }

    return 0;
}

void printCorner(Node *root) {
    if(root == NULL) return;
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()) {
        int count = q.size();
        
        for(int i = 0; i < count; i++) {
            Node *current = q.front();
            q.pop();
            
            if(i == 0 || i == count - 1)
                cout << current->data << " ";
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
        }
    }
}

/* Sample Input:
2
1 2 3 4 5 6 7
10 20 30 40 60

Sample Output:
1 2 3 4 7 
10 20 30 40 60 

*/