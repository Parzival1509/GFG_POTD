// GFG POTD 2023/10/11
// Check for Balanced Tree
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

Node* buildTree(string str) {
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    
    Node *root = new Node(stoi(ip[0]));
    
    queue<Node*> queue;
    queue.push(root);
    
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        
        string currVal = ip[i];
        
        if(currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        
        if(currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution {
public:
    int checkHeight(Node* node, bool& ans) {
        if(node == nullptr) return 0;
        
        int leftHeight = checkHeight(node->left, ans);
        int rightHeight = checkHeight(node->right, ans);
        
        if(abs(leftHeight - rightHeight) > 1)
            ans = false;
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(Node *root) {
        bool ans = true;
        checkHeight(root, ans);
        return ans;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while(t--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        if(ob.isBalanced(root)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
2
1 2 N N 3
1 2 3 4 6

Sample Output:
false 
true 

*/