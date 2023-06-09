// GFG POTD 2022/09/13
// BST to Max Heap
// Medium

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
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
            currNode->left = newNode(stoi(currVal));
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
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
void postorderTraversal(Node* root) {
    if(!root)
        return;
    // recur on left subtree
    postorderTraversal(root->left);
    // then recur on right subtree
    postorderTraversal(root->right);
    // print the root's data
    cout << root->data << " ";
}

class Solution{
public:
    void InOrder(vector<int> &vec, Node *root){
        if(root){
            InOrder(vec, root->left);
            vec.push_back(root->data);
            InOrder(vec, root->right);
        }
    }
    
    void postOrderConvert(vector<int> &vec, Node* root, int &i){
        if(root){
            postOrderConvert(vec, root->left, i);
            postOrderConvert(vec, root->right, i);
            root->data=vec[i++];
        }
    }
    void convertToMaxHeapUtil(Node* root){
        vector<int> vec;
        InOrder(vec, root);
        int ind=0;
        postOrderConvert(vec, root, ind);
    }   
};

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string inp, ch;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution ob;
        ob.convertToMaxHeapUtil(root);
        postorderTraversal(root);
        cout << "\n";
    }
    return 0;
}

/* Sample Input
1
4 2 6 1 3 5 7

Sample Output
1 2 3 4 5 6 7

*/