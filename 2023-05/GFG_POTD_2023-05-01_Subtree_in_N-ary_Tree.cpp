// GFG POTD 2023/05/01
// Subtree in N-ary Tree
// Medium

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;
    Node(int val) {
        data = val;
    }
};

class N_ary_Tree {
public:
    Node *root;
    int size;

    N_ary_Tree() {
        root = NULL;
        size = 0;
    }

    Node *add(int new_key, Node *parent_key = NULL) {
        Node *new_node = new Node(new_key);
        if(parent_key == NULL) {
            root = new_node;
            size = 1;
        }
        else {
            parent_key->children.push_back(new_node);
            size += 1;
        }
        return new_node;
    }
};

class Solution {
public:
    string constructSubtreeString(Node* node, unordered_map<string, int>& subtreeMap) {
        string s = to_string(node->data) + ":";
        vector<string> childSubtrees;
        for(auto child: node->children)
            childSubtrees.push_back(constructSubtreeString(child, subtreeMap));
        sort(childSubtrees.begin(), childSubtrees.end());
        for(auto childSubtree: childSubtrees)
            s += childSubtree + ",";
        subtreeMap[s]++;
        return s;
    }

    int duplicateSubtreeNaryTree(Node *root) {
        unordered_map<string, int> subtreeMap;
        constructSubtreeString(root, subtreeMap);
        int count = 0;
        for(auto it: subtreeMap)
            if(it.second > 1) count++;
        return count;
    }
};

int main() {
    int t;
    cin>>t;
    for(int i=0; i<t; i++) {
        if(i == 0) {
            string p;
            getline(cin, p);
        }
        string str;
        getline(cin, str);
        stringstream st(str);
        vector<string> s;
        string y;
        while(st>>y)
            s.push_back(y);
        N_ary_Tree *tree = new N_ary_Tree();
        Node *curr;
        queue<Node*> q;
        for(int i=0; i<s.size(); i++) {
            if(i == 0) curr = tree->add(stoi(s[0]));
            else if(s[i] == " ") continue;
            else if(q.size() and s[i] == "N") {
                curr = q.front();
                q.pop();
            }
            else if(s[i] != "N") q.push(tree->add(stoi(s[i]), curr));
        }
        Solution ob;
        int res = ob.duplicateSubtreeNaryTree(tree->root);
        cout<<res<<endl;
    }
}

/* Sample Input:
2
1 N 2 3 N 4 N 4 4 3 N N N N N
1 N 2 3 N 4 5 6 N N N N

Sample Output:
1
0

*/