// GFG POTD 2023/07/24
// Right View of Binary Tree
// Easy

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution {
public:
    vector<int> rightView(Node *root) {
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int hd = it.second;
            Node* node = it.first;
            mp[hd] = node->data;
           
            if(node->left) q.push({node->left, hd + 1});
            if(node->right) q.push({node->right, hd + 1});
        }
       
       vector<int> result;
       for(auto it: mp)
           result.push_back(it.second);
           
       return result;
    }
};

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

int main() {
    int t;
    string tc;
    getline(cin ,tc);
    t = stoi(tc);
    while(t--) {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> vec = ob.rightView(root);
        for(int x: vec)
            cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
1 3 2
10 20 30 40 50

Sample Output:
1 2 
10 30 50 

*/