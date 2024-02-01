// GFG POTD 2023/05/05
// Good Subtrees
// Medium

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
    if(str.length() == 0 || str[0] == 'N') return NULL;
    
    // Creating vector of strings from input string after spliting by space
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
        if(i >= ip.size()) break;
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
    unordered_set<int> help(Node* root, int k, int &ans) {
        unordered_set<int> st;
        if(!root) return st;

        unordered_set<int> left = help(root->left, k, ans);
        unordered_set<int> right = help(root->right, k, ans);
        st.insert(left.begin(), left.end());
        st.insert(right.begin(), right.end());
        st.insert(root->data);
        
        if(st.size() <= k) ans++;
        return st;
    }

    int goodSubtrees(Node *root,int k) {
        int ans = 0;
        help(root, k, ans);
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    for(int i=0; i<t; i++) {
        if(i == 0) {
            string s;
            getline(cin, s);
        }
        string str;
        getline(cin, str);
        int k;
        cin>>k;
        string newline;
        getline(cin, newline);
        Node* root = buildTree(str);
        Solution ob;
        cout<<ob.goodSubtrees(root, k)<<endl;
    }
    return 0;
}

/* Sample Input:
2
1 2 2 3 N 5 4
2
1 2 2 2 N N 2
1

Sample Output:
4
4

*/