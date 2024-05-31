// GFG POTD 2024/05/06
// Print All Nodes That Don't Have Siblings
// Easy

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
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

void help(Node* root, vector<int>& ans) {
    if (!root)
        return;

    if (!(root->left) and root->right)
        ans.push_back(root->right->data);
    else if (!(root->right) and root->left)
        ans.push_back(root->left->data);

    help(root->left, ans);
    help(root->right, ans);
}

vector<int> noSibling(Node* node) {
    vector<int> ans;
    help(node, ans);
    if (ans.size() == 0)
        ans.push_back(-1);
    else sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> res = noSibling(root);
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
37 20 N 113
1 2 3

Sample Output
20 113 
-1 

*/