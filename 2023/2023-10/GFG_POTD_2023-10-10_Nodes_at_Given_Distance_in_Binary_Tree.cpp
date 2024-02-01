// GFG POTD 2023/10/10
// Nodes at Given Distance in Binary Tree
// Hard

#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    
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

class Solution {
public:
    void dfs(Node* root, unordered_map<Node*, Node*>& parent) {
        if(root == NULL) return;
        
        if(root->left) {
            parent[root->left] = root;
            dfs(root->left, parent);
        }
        
        if(root->right) {
            parent[root->right] = root;
            dfs(root->right, parent);
        }
    }
    
    void findNode(Node* root, Node* &targetNode, int t) {
        if(root == NULL) return;
        
        if(root->data == t) {
            targetNode = root;
            return;
        }
        
        if(root->left) findNode(root->left, targetNode, t);
        if(root->right) findNode(root->right, targetNode, t);
    }
    
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        Node* targetNode;
        findNode(root, targetNode, target);
        
        queue<Node*> q;
        q.push(targetNode);
        
        unordered_map<Node*, Node*> parent;
        parent[root] = NULL;
        dfs(root, parent);
        
        unordered_map<Node*, bool> vis;
        vis[targetNode] = true;
        
        int level = 0;
        while(!q.empty()) {
            if(level == k) break;
            
            level += 1;
            int size = q.size();
            
            for(int i=1; i<=size; i++) {
                Node* node = q.front();
                q.pop();
                
                if(node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                
                if(node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = 1;
                }
                
                if(parent[node] && !vis[parent[node]]) {
                    q.push(parent[node]);
                    vis[parent[node]] = 1;
                }
            }
        }
        
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()->data);
            q.pop();
        }
        sort(res.begin(), res.end());
        
        return res;
    }
};

int main() {
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--) {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
2
20 8 22 4 12 N N N N 10 14
8
2
20 7 24 4 3 N N N N 1
7
2

Sample Output:
10 14 22 
1 24 

*/