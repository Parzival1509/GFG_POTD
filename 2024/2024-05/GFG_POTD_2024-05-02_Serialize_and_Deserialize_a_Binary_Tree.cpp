// GFG POTD 2024/05/02
// Serialize and Deserialize a Binary Tree
// Medium

#include <bits/stdc++.h>
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

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
        string currdata = ip[i];

        // If the left child is not null
        if (currdata != "N") {
            currNode->left = new Node(stoi(currdata));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currdata = ip[i];

        // If the right child is not null
        if (currdata != "N") {
            currNode->right = new Node(stoi(currdata));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    void inorder(Node* root, vector<int>& v) {
        if (root == nullptr) return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    vector<int> serialize(Node* root) {
        vector<int> v;
        inorder(root, v);
    
        return v;
    }
    
    Node* buildtree(vector<int>& v, vector<int>::iterator start, vector<int>::iterator end) {
        if (start == end)
            return nullptr;
        
        auto mid = start + (end - start) / 2;
        Node* root = new Node(*mid);
        root->left = buildtree(v, start, mid);
        root->right = buildtree(v, mid + 1, end);
    
        return root;
    }

    Node* deSerialize(vector<int>& v) {
        return buildtree(v, v.begin(), v.end());
    }
};

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node) {
    if (node == NULL)
        return;

    _deleteTree(node->left);
    _deleteTree(node->right);

    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node* temp = root;
        deleteTree(&root);
        Node* getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";
    }

    return 0;
}

/* Sample Input
2
1 2 3
10 20 30 40 60

Sample Output
2 1 3 
40 20 60 10 30 

*/