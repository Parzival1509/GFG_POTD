// GFG POTD 2024/05/05
// Vertical Sum
// Medium

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

class Solution {
public:
    void helper(Node* root, unordered_map<int, int>& m, int level, int& min, int& max) {
        if (!root) return;

        if (level < min)
            min = level;
        if (level > max)
            max = level;

        m[level] += root->data;

        helper(root->left, m, level - 1, min, max);
        helper(root->right, m, level + 1, min, max);
    }

    vector<int> verticalSum(Node* root) {
        unordered_map<int, int> m;
        int minLevel = 0, maxLevel = 0;

        helper(root, m, 0, minLevel, maxLevel);

        vector<int> ans;
        for (int i = minLevel; i <= maxLevel; i++)
            ans.push_back(m[i]);

        return ans;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        vector<int> res = obj.verticalSum(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
}

/* Sample Input
2
1 2 3 4 5 6 7
1 2 N 3 N 4 N 5 N 6 N 7

Sample Output
4 2 12 3 7 
7 6 5 4 3 2 1 

*/