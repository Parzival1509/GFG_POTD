// GFG POTD 2023/03/07
// Max Level Sum in a Binary Tree
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

class Solution {
public:
    vector<int> vec;
    int maxLevelSum(Node* root) {
        if(root == NULL) return 0;
        levelSum(root, 0);
        int max = vec[0];
        return *max_element(vec.begin(), vec.end());
    }
    
    //Function to sum all the elements of its level into a vector.
    void levelSum(Node* root, int i) {
        if(root == NULL) return;

        //To create a space for vector to perform addition else it will show segmentation fault.
        while(vec.size() <= i) vec.push_back(0);
        //preorder traversal
        vec[i] += root->data;
        levelSum(root->left, i+1);
        levelSum(root->right, i+1);
    }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution obj;
        Node *root = buildTree(treeString);
        cout << obj.maxLevelSum(root) << "\n";
    }
    return 0;
}

/* Sample Input:
2
4 2 -5 -1 3 -2 6
1 2 3 4 5 8 N N 6 7

Sample Output:
6
17

*/