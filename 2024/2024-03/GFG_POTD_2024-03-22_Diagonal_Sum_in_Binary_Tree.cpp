// GFG POTD 2024/03/22
// Diagonal Sum in Binary Tree
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
    void solve(Node* root, int x, int y, map<int, int>& mp) {
        if (root == NULL) return;
        
        mp[y - x] = mp[y - x] + root->data;
        solve(root->left, x - 1, y + 1, mp);
        solve(root->right, x + 1, y + 1, mp);
    }

    vector<int> diagonalSum(Node* root) {
        map<int, int> mp;
        solve(root, 0, 0, mp);
        vector<int> ans;
        for (auto& it : mp)
            ans.push_back(it.second);
        
        return ans;
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
        vector<int> res = ob.diagonalSum(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
4 1 3 N N 3
10 8 2 3 5 2

Sample Output
7 4 
12 15 3 

*/