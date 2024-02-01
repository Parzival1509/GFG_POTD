// GFG POTD 2023/06/28
// Maximum Depth Of Binary Tree
// Easy

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    int depth(Node *root) {
        if(root == NULL) return 0;
        
        int d1 = depth(root->left);
        int d2 = depth(root->right);
        return max(d1, d2) + 1;
    }
    
    int maxDepth(Node *root) {
        return depth(root);
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        cout << obj.maxDepth(root) << endl;
    }
    return 0;
}

/* Sample Input:
3
1 3 2 4
10 2 11 1 5 N N N N 3 6 N 4
10 20 30 N 40 N 60 N N 2

Sample Output:
3
5
4

*/