// GFG POTD 2024/05/07
// Reverse Level Order Traversal
// Easy

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
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

vector<int> reverseLevelOrder(Node* root) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            if(!q.empty())
                q.push(NULL);
        } else {
            ans.push_back(temp->data);
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 1;
}

/* Sample Input
2
1 3 2
10 20 30 40 60

Sample Output
3 2 1 
40 60 20 30 10 

*/