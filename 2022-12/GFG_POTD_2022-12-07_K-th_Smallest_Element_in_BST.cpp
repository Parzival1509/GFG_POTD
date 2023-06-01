// GFG POTD 2022/12/07
// K-th Smallest Element in BST
// Medium

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// O(N) TC
class Solution {
    int Iterations = 0, k=0, ans=-1;
public:
    void search(Node* bst) {
        if(bst) {
            search(bst->left);
            Iterations++;
            if(Iterations == k)
                ans = bst->data;
            else if(Iterations > k)
                return;
            search(bst->right);
        }
    }
    
    int KthSmallestElement(Node *bst, int K) {
        k = K;
        search(bst);
        return ans;
    }
};

// // O(N log(N)) TC
// class Solution {
// public:
//     void preorder(Node* root, vector<int>& vec) {
//         if(root==NULL) return;
//         vec.push_back(root->data);
//         preorder(root->left, vec);
//         preorder(root->right, vec);
//     }
//     int KthSmallestElement(Node *root, int K) {
//         vector<int> vec;
//         preorder(root, vec);
//         sort(vec.begin(), vec.end());
//         int ans=-1;
//         if(vec.size()>=K) return vec[K-1];
//         return ans;
//     }
// };

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        //  getline(cin, s);
        Solution obj;
        cout << obj.KthSmallestElement(root, k) << endl;
        // cout<<"~"<<endl;
    }
    return 0;
}

/* Sample Input
NLR
2
2 1 3
2
2 1 3
5

Sample Output
2
-1

*/