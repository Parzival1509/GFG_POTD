// GFG POTD 2024/03/31
// Closest Neighbour in BST
// Easy

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
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
    int findMaxForN(Node* root, int n) {
        int maxVal = -1;
        
        while (root) {
            if (root->key <= n) {
                maxVal = root->key;
                root = root->right;
            } else
                root = root->left;
        }
        
        return maxVal;
    }
};

int main() {
    int T;
    scanf("%d ", &T);
    while (T--) {
        string treeString;
        getline(cin >> ws, treeString);
        int x;
        cin >> x;
        // getchar();
        Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.findMaxForN(root, x) << endl;
    }

    return 0;
}

/* Sample Input
2
5 2 12 1 3 9 21 N N N N N N 19 25 
24
5 2 12 1 3 9 21 N N N N N N 19 25 
4

Sample Output
21
3

*/