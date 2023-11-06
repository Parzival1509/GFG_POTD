// GFG POTD 2023/10/10
// Height of Binary Tree
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
    int height(Node* node) {
        if(!node) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        return 1 + max(left, right);
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
        cout << ob.height(root) << endl;
    }

    return 0;
}

/* Sample Input:
2
1 2 3
2 N 1 3

Sample Output:
2
3

*/