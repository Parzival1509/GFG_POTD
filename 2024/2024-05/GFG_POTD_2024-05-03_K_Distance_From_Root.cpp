// GFG POTD 2024/05/03
// K Distance From Root
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
    void solve(Node* root, int k, vector<int>& ans) {
        if (!root) return;
        
        if (k == 0)
            ans.push_back(root->data);
        solve(root->left, k - 1, ans);
        solve(root->right, k - 1, ans);
    }

    vector<int> Kdistance(Node* root, int k) {
        if (!root) return {};
        if (k == 0) return {root->data};
        
        vector<int> ans;
        solve(root, k, ans);

        return ans;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        int k;
        scanf("%d ", &k);
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        vector<int> vec = obj.Kdistance(root, k);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 1;
}

/* Sample Input
2
0
1 3 2
3
1 2 N N 1 5 3

Sample Output
1 
5 3 

*/