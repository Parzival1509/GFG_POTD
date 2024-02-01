// GFG POTD 2023/03/09
// Find Anagrams in Linked List
// Medium

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

class Solution {
private:
    bool isAnagram(string s1, string s2) {
        array<int, 26> fq{};
        for(char ch: s1) ++fq[ch-'a'];
        for(char ch: s2) --fq[ch-'a'];
        for(auto it: fq)
            if(it != 0) return false;
        return true;
    }

public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        if(!head) return {};
        Node* curr = head;
        Node* prev = NULL;
        vector<Node*> ans;
        
        while(head) {
            string tmp = "";
            for(int i=0; i<s.length(); ++i) {
                if(!curr) return ans;
                tmp += curr->data;
                prev = curr;
                curr = curr->next;
            }
            
            if(isAnagram(tmp,s)) {
                ans.push_back(head);
                prev->next = NULL;
            }
            else curr = head->next;
            head = curr;    // because overlapping nodes are not allowed
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        struct Node *head = inputList();
        string s;
        cin >> s;
        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);
        for (int i = 0; i < res.size(); i++)
            printList(res[i]);
        cout<<endl;
        if (res.size() == 0) cout << "-1\n";
    }
}

/* Sample Input:
3
4
a b c a
abc
8
a b c a d b c a
bac
5
a b d c a
bac

Sample Output:
a b c 

a b c 
b c a 


-1

*/