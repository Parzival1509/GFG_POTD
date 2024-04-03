// GFG POTD 2024/03/18
// Level Order Trsversal
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution {
public:
    vector<int> levelOrder(Node* root) {
        vector<int> v;
        queue<Node*> q;
        if (root == NULL)
            return v;
        
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* update_node = q.front();
                q.pop();

                if (update_node->left != NULL)
                    q.push(update_node->left);
                if (update_node->right != NULL)
                    q.push(update_node->right);

                v.push_back(update_node->data);
            }
        }

        return v;
    }
};

void inOrder(struct Node* node) {
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;

        if (i >= ip.size())
            break;

        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.levelOrder(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
1 3 2
10 20 30 40 60

Sample Output
1 3 2 
10 20 30 40 60 

*/