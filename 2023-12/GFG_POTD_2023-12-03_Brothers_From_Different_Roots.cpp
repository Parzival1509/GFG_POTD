// GFG POTD 2023/12/03
// Brothers From Different Roots
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    void dfs(Node* root, unordered_map<int, int>& mp, int& x, int& cnt, bool flag) {
        if(!root) return;
        
        if(flag) cnt += mp[x - root->data];
        else mp[root->data]++;
        
        dfs(root->left, mp, x, cnt, flag);
        dfs(root->right, mp, x, cnt, flag);
    }
    
    int countPairs(Node* root1, Node* root2, int x) {
        unordered_map<int,int> mp;
        int cnt = 0;
        
        dfs(root1, mp, x, cnt, 0);
        dfs(root2, mp, x, cnt, 1);
        
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }

    return 0;
}

/* Sample Input:
2
5 3 7 2 4 6 8 
10 6 15 3 8 11 18 
16
1 N 3 2
3 2 4 1
4

Sample Output:
3
3

*/