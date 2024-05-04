// GFG POTD 2024/04/02
// Minimum Absolute Difference in BST
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
    vector<int> v;
    
    void inorder(Node* root) {
        if (!root) return;
        
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }

    int absolute_diff(Node* root) {
        int m = INT_MAX;
        inorder(root);
        for (int i = 1; i < v.size(); i++) {
            int d = abs(v[i - 1] - v[i]);
            m = min(m, d);
        }

        return m;
    }
};

int main() {
    int T;
    scanf("%d ", &T);
    // getchar();
    while (T--) {
        string treeString;
        getline(cin, treeString);
        // getline(cin >> ws, treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.absolute_diff(root) << endl;
    }

    return 0;
}

/* Sample Input
3
5 3 7 2 4 6 8
50 30 70 20 N 60 80
60 30 90 10

Sample Output
1
10
20

*/