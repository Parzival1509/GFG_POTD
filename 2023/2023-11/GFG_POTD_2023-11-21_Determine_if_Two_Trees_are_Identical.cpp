// GFG POTD 2023/11/21
// Determine if Two Trees are Identical
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
    bool isIdentical(Node *r1, Node *r2) {
        if(r1 == NULL and r2 == NULL) return 1;
        
        if((r1 && r2 == NULL) || (r2 && r1 == NULL) || (r1->data != r2->data))
            return 0;
        
        bool a = isIdentical(r1->left, r2->left) ;
        bool b = isIdentical(r2->right, r1->right) ;
        
        return a & b;
    }
};

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while(t--) {
        string s1, s2;
        getline(cin, s1);
        Node* rootA = buildTree(s1);
        getline(cin, s2);
        Node* rootB = buildTree(s2);
        Solution ob;
        if(ob.isIdentical(rootA, rootB)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }

    return 0;
}


/* Sample Input:
2
1 2 3
1 2 3
1 2 3
1 3 2

Sample Output:
Yes
No

*/