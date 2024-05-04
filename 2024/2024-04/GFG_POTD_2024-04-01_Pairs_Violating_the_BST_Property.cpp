// GFG POTD 2024/04/01
// Pairs Violating the BST Property
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
    vector<int> bit;

    void update(int i, int val, int n) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];

        return sum;
    }

    void dfs(Node* root) {
        if (root->left != nullptr)
            dfs(root->left);
        v.push_back(root->data);
        if (root->right != nullptr)
            dfs(root->right);
    }

    int pairsViolatingBST(int n, Node* root) {
        dfs(root);
        int ans = 0;
        bit.resize(n + 1, 0);
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++)
            pairs[i] = {v[i], i + 1};
        sort(pairs.rbegin(), pairs.rend());
        
        for (auto& p : pairs) {
            ans += query(p.second - 1);
            update(p.second, 1, n);
        }

        return ans;
    }
};


int main() {
    int T;
    scanf("%d ", &T);
    getchar();
    while (T--) {
        string treeString;
        getline(cin >> ws, treeString);
        int x;
        cin >> x;
        Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.pairsViolatingBST(x, root) << endl;
    }

    return 0;
}

/* Sample Input
2
5
10 50 40 N N 20 30 N N N N
6
80 40 30 70 N 60 70

Sample Output
5
8

*/