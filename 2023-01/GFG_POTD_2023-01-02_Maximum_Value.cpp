// GFG POTD 2023/01/02
// Maximum Value
// Medium

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
public:
    vector<int> maximumValue(Node* node) {
        vector<int> ans;
        if(node == NULL) return ans;
        solve(node, ans, 0);
        return ans;
    }
    
    void solve(Node* node , vector<int> &ans, int l){
        if(node == NULL) return;
        if(l >= ans.size()) ans.push_back(node-> data);
        else ans[l] = max(ans[l], node->data);
        
        solve(node->left, ans, l+1);
        solve(node->right, ans, l+1);
    }
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
    if(str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str;)
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
        if(i >= ip.size()) break;
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

vector<int> maximumValue(struct Node* tree);

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> answer = ob.maximumValue(root);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
1 2 3
4 9 2 3 5 7

Sample Output
1 3 
4 9 7 

*/