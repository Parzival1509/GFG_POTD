// GFG POTD 2022/12/30
// Single Valued Subtree
// Medium

#include <bits/stdc++.h>
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
	if (str.length() == 0 || str[0] == 'N')
		return NULL;
	// Creating vector of strings from input string after spliting by space
	vector<string> ip;
	istringstream iss(str);
	for (string str; iss >> str; )
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
    int dfs(Node* root, int& ans) {
        if(!root) return 0;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        
        if((!l && !r) || (l==r && l==root->data) || (!l && r==root->data) || (!r && l==root->data)) {
            ans++;
            return root->data;
        }
        return -1;
    }
    
    int singlevalued(Node *root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    // int singlevalued(Node *root) {
    //     int ans = 0;
    //     function<int(Node*)> fun = [&] (Node *root) {
    //         if(!root) return 0;
    //         int left = fun(root->left);
    //         int right = fun(root->right);
            
    //         if(left == -1 || right == -1) return -1;
    //         if(left != 0 && root->data != left) return -1;
    //         if(right != 0 && root->data != right) return -1;
    //         if(left != 0 && right != 0 && left != right) return -1;
    //         ++ans;
    //         return root->data;
    //     };
        
    //     fun(root);
    //     return ans;
    // }
};

int main() {
	int t;
	cin >> t;
	getchar();
	while(t--) {
		string inp;
		getline(cin, inp);
        Solution ob;
        struct Node* root = buildTree(inp);
		cout << ob.singlevalued(root) << "\n";
	}
	return 0;
}

/* Sample Input
2
5 1 5 5 5 5
5 4 5 4 4 5

Sample Output
4
5

*/