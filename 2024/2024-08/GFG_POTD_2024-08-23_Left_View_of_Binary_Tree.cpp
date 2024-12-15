// GFG POTD 2024/08/23
// Left View of Binary Tree
// Easy

#include <bits/stdc++.h>
using namespace std;

vector<int> leftView(Node* root) {
    vector<int> ans;
    if (root == NULL)
        return ans;
    
    if (!root->left && !root->right) {
        ans.push_back(root->data);
        return ans;
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int s = q.size(), sz = s;
        while (s--) {
            Node* temp = q.front();
            if (s == sz - 1)
                ans.push_back(temp->data);
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        
    }
    return 0;
}

/* Sample Input
2
-7 9 8 3 1 1
2
5 2 7 5
13

Sample Output
2
14

*/