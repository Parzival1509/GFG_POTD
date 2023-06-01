// GFG POTD 2022/11/19
// Check if all levels of two trees are anagrams or not

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
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str;) ip.push_back(str);

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

class Solution{
public:
    bool areAnagrams(Node *root1, Node *root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);
        while(1) {
            int s1=q1.size(), s2=q2.size();
            if(s1!=s2) return false;
            if(s1==0) break;
            vector<int> lvlt1, lvlt2;
            while(s1--) {
                Node* node1=q1.front();
                q1.pop();
                if(node1->left != NULL) q1.push(node1->left);
                if(node1->right != NULL) q1.push(node1->right);
                lvlt1.push_back(node1->data);
                Node* node2=q2.front();
                q2.pop();
                if(node2->left != NULL) q2.push(node2->left);
                if(node2->right != NULL) q2.push(node2->right);
                lvlt2.push_back(node2->data);
            }
            sort(lvlt1.begin(), lvlt1.end());
            sort(lvlt2.begin(), lvlt2.end());
            if(lvlt1 != lvlt2)
                return false;
        }
        return true;
    }
};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

/* Sample Input
3
1 3 2 N N 5 4
1 2 3 4 5 N N

Sample Output
1
1
1

*/