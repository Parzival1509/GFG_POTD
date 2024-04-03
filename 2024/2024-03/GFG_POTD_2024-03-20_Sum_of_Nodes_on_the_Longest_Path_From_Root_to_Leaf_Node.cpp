// GFG POTD 2024/03/20
// Sum of Nodes on the Longest Path From Root to Leaf Node
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
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
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
    int height(Node* root) {
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    void solve(Node* root, int tot, int height, int& res) {
        if (height == 0) {
            res = max(res, tot);
            return;
        }

        if (!root) return;

        solve(root->left, tot + root->data, height - 1, res);
        solve(root->right, tot + root->data, height - 1, res);
    }

    int sumOfLongRootToLeafPath(Node* root) {
        int h = height(root), res = INT_MIN;
        solve(root, 0, h, res);

        return res;
    }
};

int main() {
    int T;
    scanf("%d ", &T);
    while (T--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        int res = ob.sumOfLongRootToLeafPath(root);
        cout << res << endl;
    }

    return 0;
}

/* Sample Input
2
4 2 5 7 1 2 3 N N 6 N
1 2 3 4 5 6 7

Sample Output
13
11

*/