// GFG POTD 2023/02/06
// BST Downward Traversal
// Easy

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

#define ll long long

class Solution {
public:
    Node* search(Node* root,int target) {
        if(root == NULL) return NULL;
        if(root->data == target) return root;
        if(root->data > target) search(root->left, target);
        else search(root->right, target);
    }
   
    void calc(Node* root,int v,ll &sum) {
        if(root == NULL) return;
        if(v == 0) sum += root->data;
        calc(root->left, v-1, sum);
        calc(root->right, v+1, sum);
    }
   
    ll verticallyDownBST(Node *root, int target) {
        Node* tnode = search(root, target);
        if(tnode == NULL) return -1;
        ll sum=0;
        calc(tnode->left, -1, sum);
        calc(tnode->right, 1, sum);
        return sum;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
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

void inorder(Node *root, vector<int> &v) {
    if(root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int target;
        cin>>target;
        string newline;
        getline(cin,newline);
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.verticallyDownBST(root, target)<<endl;
    }
    return 0;
}

/* Sample Input:
2
35
25 20 35 15 22 30 45 N N N N N 32 N N
25
25 20 35 15 22 30 45 N N N N N 32 N N

Sample Output:
32
52

*/