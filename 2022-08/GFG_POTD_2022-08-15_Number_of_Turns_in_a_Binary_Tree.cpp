// GFG POTD 2022/08/15
// Number of Turns in a Binary Tree
// Hard

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

// Function to Build Tree
Node* buildTree(string str) {   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    // Creating vector of strings from input string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
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
            // Create the left child for the current Node
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

class Solution{
    Node* lowestCommonAncestor(Node *root, int p, int q) {
        if(!root) return NULL;
        if(root->data==p) return root;
        if(root->data==q) return root;
        Node* left = lowestCommonAncestor(root->left, p, q);
        Node* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
    
    int turns(Node* root, int p, int q, int turn, int dir) {
        if(!root) return 0;
        int left=0, right=0;
        if(root->data==q || root->data==p){
            left=turns(root->left,p,q,turn,1);
            right=turns(root->right,p,q,turn,2);
            if(left || right) return left+right;
            return turn;
        }
        if(dir==1){
            left=turns(root->left,p,q,turn,1);
            right=turns(root->right,p,q,turn+1,2);
        }
        else if(dir==2){
            right = turns(root->right,p,q,turn,2);
            left = turns(root->left,p,q,turn+1,1);
        }
        else{
            left=turns(root->left,p,q,turn,1);
            right=turns(root->right,p,q,turn,2);
            return left+right+1;
        }
        return left+right;
    }
    
public:
    int NumberOFTurns(struct Node* root, int first, int second) {
       Node* ancestor = lowestCommonAncestor(root, first, second);
       int ans= turns(ancestor, first, second, 0, 0);
       if(ans==0) return -1;
       return ans;
    }
};

int main() {
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if((turn = ob.NumberOFTurns(root, first, second)))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

/* Sample Input

Sample Output

*/