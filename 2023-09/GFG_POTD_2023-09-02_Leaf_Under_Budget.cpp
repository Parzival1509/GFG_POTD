// GFG POTD 2023/09/02
// Leaf Under Budget
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node) {
    if(node == NULL) return;
    
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

Node *buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
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

class Solution {
public:
    int getCount(Node *root, int k) {
        queue<Node*> q;
        q.push(root);
        
        int ct = 0, level = 0;
        while(!q.empty()) {
            int n = q.size();
            level++;
            
            for(int i = 0; i < n; i++) {
                Node* tmp = q.front();
                q.pop();
                
                if(tmp->left == NULL && tmp->right == NULL) {
                    if(k - level >= 0) {
                        k -= level;
                        ct++;
                    }
                    else return ct;
                }
                else {
                    if(tmp->left != NULL) q.push(tmp->left);
                    if(tmp->right != NULL) q.push(tmp->right);
                }
            }
        }
        
        return ct;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    cin.ignore();
    while(t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        int res = obj.getCount(root, k);
        cout << res << "\n";
    }

    return 0;
}

/* Sample Input:
2
10 8 2 3 N 3 6 N N N 4
8
1 2 3 4 5 6 7
5

Sample Output:
2
1

*/