// GFG POTD 2024/04/03
// Kth Common Ancestor in BST
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
    int kthCommonAncestor(Node* root, int k, int x, int y) {
        vector<int> vec;

        while (true) {
            vec.push_back(root->data);

            if (x > root->data && y > root->data)
                root = root->right;
            else if (x < root->data && y < root->data)
                root = root->left;
            else break;
        }
        int ind = vec.size() - k;

        return (vec.size() < k) ? -1 : vec[ind];
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string treeString;
        getline(cin, treeString);
        int k, x, y;
        cin >> k >> x >> y;
        cin.ignore();
        Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.kthCommonAncestor(root, k, x, y) << endl;
    }

    return 0;
}

/* Sample Input
2
30 20 50 N N 40 60
2 40 60
50 40 70 30 N 60 80
2 40 60

Sample Output
30
-1

*/