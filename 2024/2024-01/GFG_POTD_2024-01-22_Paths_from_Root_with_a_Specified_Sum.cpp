// GFG POTD 2024/01/22
// Paths from Root with a Specified Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<vector<int>> ans;
        queue<pair<Node*, pair<int, vector<int>>>> q;
        q.push({root, {root->key, {root->key}}});
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(sum == node.second.first)
                ans.emplace_back(node.second.second.begin(),node.second.second.end());
            if(node.first->left) {
                vector<int> tempV(node.second.second.begin(), node.second.second.end());
                int tempS = node.second.first + node.first->left->key;
                tempV.push_back(node.first->left->key);
                q.push({node.first->left, {tempS, tempV}});
            }
           
            if(node.first->right) {
                vector<int> tempV(node.second.second.begin(), node.second.second.end());
                int tempS =node.second.first + node.first->right->key;
                tempV.push_back(node.first->right->key);
                q.push({node.first->right, {tempS, tempV}});
            }
        }
        
        return ans;
    }
};

int main () {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        int sum;
        cin >> sum;
        getchar();
        string inp;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution ob;
        vector<vector<int>> ans = ob.printPaths(root, sum);
        sort(ans.begin(),ans.end());
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
8
1 20 3 N N 4 15 6 7 8 9
38
10 28 13 N N 14 15 21 22 23 24

Sample Output:
1 3 4 

10 13 15 
10 28 


*/