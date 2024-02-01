// GFG POTD 2023/07/25
// Level Order Traversal in Spiral Form
// Easy

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

// Function to Build Tree
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

vector<int> findSpiral(Node *root) {
    bool flag = true;
    queue<Node*> q;
    vector<int> v;
    q.push(root);
    
    while(!q.empty()) {
        int n = q.size();
        vector<int> v1;
        for(int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();
            v1.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        // Left to right
        if(!flag) {
            for(int i = 0; i < v1.size(); i++)
                v.push_back(v1[i]);
            flag = true;
        }
        
        // Right to left(reverse order of above)
        else {
            for(int i = v1.size() - 1; i >= 0; i--)
                v.push_back(v1[i]);
            flag = false;
        }
    }
    
    return v;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--) {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x: vec)
            cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
1 3 2
10 20 30 40 60

Sample Output:
1 3 2 
10 20 30 60 40 

*/