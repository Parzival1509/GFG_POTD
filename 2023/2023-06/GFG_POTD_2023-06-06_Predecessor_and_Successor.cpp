// GFG POTD 2023/06/06
// Predecessor and Successor
// Medium

#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    
    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void predecessor(Node* root, Node*& pred, int key) {
        while(root != 0) {
            if(key <= root->key) root = root->left;
            else {
                pred = root;
                root = root->right;
            }
        }
    }
    
    void successor(Node* root, Node*& succ, int key) {
        while(root != 0) {
            if(key >= root->key) root = root->right;
            else {
                succ = root;
                root = root->left;
            }
        }
    }
    
    void findPreSuc(Node* root, Node*& pred, Node*& succ, int key) {
        predecessor(root, pred, key);
        successor(root, succ, key);
    }
};

Node* buildTree(string str) {
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));

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

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--) {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre = NULL, *succ = NULL;
        Solution ob;
        ob.findPreSuc(root, pre, succ, k);
        (pre != NULL)? cout<<pre->key: cout<<-1;
        cout<<" ";
        (succ != NULL)? cout<<succ->key: cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   }
   return 0;
}

/* Sample Input:
2
10 2 11 1 5 N N N N 3 6 N 4
8
8 1 9 N 4 N 10 3
11

Sample Output:
6 10
10 -1

*/