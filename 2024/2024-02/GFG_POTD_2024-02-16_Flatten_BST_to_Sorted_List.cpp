// GFG POTD 2024/02/16
// Flatten BST to Sorted List
// Medium

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *newNode(int key) {
    Node *node = new Node(key);
    return node;
}

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void printList(Node *head) {
    while (head) {
        if(head->left)
            cout << "-1 ";
        cout << head->data << " ";
        head = head->right;
    }
    cout << "\n";
}

class Solution {
public:
    void inorderTraversal(Node *root, vector<int>& res) {
        if (root == NULL) return;

        inorderTraversal(root->left, res);
        res.push_back(root->data);
        inorderTraversal(root->right, res);
    }

    Node* constructRightTree(vector<int>& res, int& index) {
        if (index >= res.size())
            return NULL;

        Node* newNode = new Node(res[index++]);
        newNode->right = constructRightTree(res, index);
        return newNode;
    }

    Node* flattenBST(Node* root) {
        vector<int> res;
        inorderTraversal(root, res);
        int index = 0;
        
        return constructRightTree(res, index);
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        auto ans = ob.flattenBST(root);
        printList(ans);
    }
    
    return 0;
}

/* Sample Input:
2
5 3 7 2 4 6 8
5 N 8 7 9

Sample Output:
2 3 4 5 6 7 8 
5 7 8 9 

*/