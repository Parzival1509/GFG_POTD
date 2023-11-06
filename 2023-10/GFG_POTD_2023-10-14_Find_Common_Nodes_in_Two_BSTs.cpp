// GFG POTD 2023/10/14
// Find Common Nodes in Two BSTs
// Easy

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
    vector<int> ans;
    
    bool find(Node *root, int val) {
        if(!root) return 0;
        if(root->data > val) return find(root->left, val);
        if(root->data < val) return find(root->right, val);
        return 1;
    }
    
    void helper(Node *root1, Node *root2) {
        if(!root1 or !root2) return;
        
        helper(root1->left, root2);
        if(find(root2,(root1->data)))
            ans.push_back(root1->data);
        helper(root1->right, root2);
    }
    
    vector<int> findCommon(Node *root1, Node *root2) {
        ans.clear();
        helper(root1, root2);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while(t--) {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector<int> res = ob.findCommon(root1, root2);
        for(int i: res)
            cout << i << " ";
        cout<< endl;
    }

    return 1;
}

/* Sample Input:
2
5 1 10 0 4 7 N N N N N N 9
10 7 20 4 9
10 2 11 1 3
2 1 3

Sample Output:
4 7 9 10 
1 2 3 

*/