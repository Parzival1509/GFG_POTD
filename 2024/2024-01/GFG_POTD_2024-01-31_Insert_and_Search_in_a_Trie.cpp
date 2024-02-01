// GFG POTD 2024/01/31
// Insert and Search in a Trie
// Medium

#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;
        pNode->isLeaf = false;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

class Solution {
public:
    void insert(struct TrieNode *root, string key) {
        for (int i = 0; i < key.size(); i++) {
            if (root->children[key[i]-'a'] == NULL)
                root->children[key[i]-'a'] = new TrieNode();
            root = root->children[key[i]-'a'];
        }
        root->isLeaf = true;
    }

    bool search(struct TrieNode *root, string key) {
        for (int i = 0; i < key.size(); i++) {
            if (root->children[key[i]-'a'] == NULL)
                return false;
            
            root = root->children[key[i]-'a'];
        }

        return root->isLeaf;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++)
            cin >> keys[i];
        
        Solution obj;
        struct TrieNode *root = getNode();
        for (int i = 0; i < n; i++)
            obj.insert(root, keys[i]);
        string abc;
        cin >> abc;
        
        if (obj.search(root, abc))
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}

/* Sample Input:
2
8
the a there answer any by bye their
the
8
the a there answer any by bye their
geeks

Sample Output:
1
0

*/