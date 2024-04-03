// GFG POTD 2024/03/21
// ZigZag Tree Traversal
// Medium

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

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
        if (i >= ip.size())
            break;
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
    vector<int> zigZagTraversal(Node* root) {
        deque<Node*> q;
        q.push_back(root);
        vector<int> res;
        bool flag = true;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                if (flag) {
                    auto node = q.front();
                    q.pop_front();
                    if (node->left)
                        q.push_back(node->left);
                    if (node->right)
                        q.push_back(node->right);
                    res.push_back(node->data);
                } else {
                    auto node = q.back();
                    q.pop_back();
                    if (node->right)
                        q.push_front(node->right);
                    if (node->left)
                        q.push_front(node->left);
                    res.push_back(node->data);
                }
            }
            flag = !flag;
        }

        return res;
    }
};

int main() {
    int T;
    scanf("%d ", &T);
    while (T--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);

        Solution ob;
        vector<int> ans;
        ans = ob.zigZagTraversal(root);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}

/* Sample Input
3
3 2 1
1 2 3 4 5 6 7
7 9 7 8 8 6 N 10 9

Sample Output
3 1 2 
1 3 2 4 5 6 7 
7 7 9 8 8 6 9 10 

*/