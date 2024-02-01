// GFG POTD 2023/11/20
// K Sum Paths
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
    if (str.length() == 0 || str[0] == 'N') return NULL;

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
        if (i >= ip.size()) break;
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
    int mod = 1e9 + 7;
    
    int func(Node *root, map<int, int> &mp, int k, int sum) {
        if(root == NULL) return 0;
        
        int ans = 0;
        if(mp.find(sum + root->data - k) != mp.end())
            ans += mp[sum + root->data - k] % mod;
            
        mp[sum + root->data]++;
        ans += (func(root->left, mp, k, sum + root->data) % mod + func(root->right, mp, k, sum + root->data) % mod) % mod;
        mp[sum + root->data]--;
        
        return ans % mod;
    }
    
    int sumK(Node *root,int k) {
        map<int, int> mp;
        mp[0] = 1;
        
        return func(root, mp, k, 0);
    }
};

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while(t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << endl;
    }

    return 0;
}


/* Sample Input:
2
1 2 3
3
1 3 -1 2 1 4 5 N N 1 N 1 2 N 6
5

Sample Output:
2
8

*/