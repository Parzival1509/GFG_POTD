// GFG POTD 2023/10/12
// Duplicate Subtree in Binary Tree
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
    string solve(Node *root, unordered_map<string, int> &m) {
        if(!root) return "$";
        
        string curr = "#";
        if(!root->left && !root->right) {
            curr = to_string(root->data);
            return curr;
        }
        
        curr += to_string(root->data);
        curr += "#";
        curr += solve(root->left, m);
        curr += "#";
        curr += solve(root->right, m);
        curr += "#";
        m[curr]++;
        
        return curr;
    }
    
    int dupSub(Node *root) {
        unordered_map<string, int> m;
        solve(root, m);
        for(auto &val: m)
            if(val.second >= 2)
                return true;
        
        return false;
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
        if(ob.dupSub(root)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
1 2 3 4 5 N 2 N N N N 4 5
1 2 3

Sample Output:
true 
false 

*/